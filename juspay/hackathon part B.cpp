#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string name;
    int lockedBy;
    bool isLocked;
    int lockedDescendantCount;
    bool inProgress; // For algorithmic synchronization
    TreeNode* parent;
    vector<TreeNode*> children;
    TreeNode(string nm, TreeNode* par) {
        name = nm;
        parent = par;
        lockedBy = -1;
        isLocked = false;
        lockedDescendantCount = 0;
        inProgress = false;
    }
};

class MAryTree {
    TreeNode* root;
    unordered_map<string, TreeNode*> nodeMap;
public:
    MAryTree(string rootName) {
        root = new TreeNode(rootName, nullptr);
        nodeMap[rootName] = root;
    }

    void buildTree(vector<string>& nodes, int m) {
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1, n = nodes.size();
        while (!q.empty() && idx < n) {
            TreeNode* current = q.front();
            q.pop();
            for (int i = 0; i < m && idx < n; i++) {
                TreeNode* child = new TreeNode(nodes[idx], current);
                current->children.push_back(child);
                nodeMap[nodes[idx]] = child;
                q.push(child);
                idx++;
            }
        }
    }

    bool lock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        vector<TreeNode*> reservation;
        if (!reservePath(node, reservation)) return false;

        bool result = false;
        if (!node->isLocked && node->lockedDescendantCount == 0 && checkAncestorsUnlocked(node)) {
            node->isLocked = true;
            node->lockedBy = uid;
            TreeNode* temp = node->parent;
            while (temp) {
                temp->lockedDescendantCount++;
                temp = temp->parent;
            }
            result = true;
        }
        releasePath(reservation);
        return result;
    }

    bool unlock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        vector<TreeNode*> reservation;
        if (!reservePath(node, reservation)) return false;

        bool result = false;
        if (node->isLocked && node->lockedBy == uid) {
            node->isLocked = false;
            node->lockedBy = -1;
            TreeNode* temp = node->parent;
            while (temp) {
                temp->lockedDescendantCount--;
                temp = temp->parent;
            }
            result = true;
        }
        releasePath(reservation);
        return result;
    }

    bool upgradeLock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        vector<TreeNode*> reservation;
        if (!reserveSubtree(node, reservation)) return false;

        bool result = false;
        if (!node->isLocked && node->lockedDescendantCount > 0 &&
            checkAllDescendantsSameUser(node, uid) && checkAncestorsUnlocked(node)) {
            unlockAllDescendants(node, uid);
            node->isLocked = true;
            node->lockedBy = uid;
            TreeNode* temp = node->parent;
            while (temp) {
                temp->lockedDescendantCount++;
                temp = temp->parent;
            }
            result = true;
        }
        releasePath(reservation);
        return result;
    }

private:
    // Reserve node and ancestors
    bool reservePath(TreeNode* node, vector<TreeNode*>& reservation) {
        TreeNode* temp = node;
        while (temp) {
            if (temp->inProgress) { rollback(reservation); return false; }
            temp->inProgress = true;
            reservation.push_back(temp);
            temp = temp->parent;
        }
        return true;
    }

    // Reserve node and all descendants (for upgrade)
    bool reserveSubtree(TreeNode* node, vector<TreeNode*>& reservation) {
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (cur->inProgress) { rollback(reservation); return false; }
            cur->inProgress = true;
            reservation.push_back(cur);
            for (auto child : cur->children) q.push(child);
        }
        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->inProgress) { rollback(reservation); return false; }
            temp->inProgress = true;
            reservation.push_back(temp);
            temp = temp->parent;
        }
        return true;
    }

    void rollback(vector<TreeNode*>& reservation) {
        for (auto node : reservation) node->inProgress = false;
        reservation.clear();
    }

    void releasePath(vector<TreeNode*>& reservation) {
        for (auto node : reservation) node->inProgress = false;
    }

    bool checkAncestorsUnlocked(TreeNode* node) {
        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->isLocked) return false;
            temp = temp->parent;
        }
        return true;
    }

    bool checkAllDescendantsSameUser(TreeNode* node, int uid) {
        if (node->isLocked && node->lockedBy != uid) return false;
        for (TreeNode* child : node->children) {
            if (!checkAllDescendantsSameUser(child, uid)) return false;
        }
        return true;
    }

    void unlockAllDescendants(TreeNode* node, int uid) {
        if (node->isLocked && node->lockedBy == uid) {
            node->isLocked = false;
            node->lockedBy = -1;
            TreeNode* temp = node->parent;
            while (temp) {
                temp->lockedDescendantCount--;
                temp = temp->parent;
            }
        }
        for (TreeNode* child : node->children) unlockAllDescendants(child, uid);
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];
    MAryTree tree(nodes[0]);
    tree.buildTree(nodes, m);
    while (q--) {
        int type, uid;
        string name;
        cin >> type >> name >> uid;
        bool result = false;
        if (type == 1) result = tree.lock(name, uid);
        else if (type == 2) result = tree.unlock(name, uid);
        else if (type == 3) result = tree.upgradeLock(name, uid);
        cout << (result ? "true" : "false") << "\n";
    }
    return 0;
}

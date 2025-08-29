#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string name;
    int lockedBy; // -1 if unlocked
    bool isLocked;
    TreeNode* parent;
    vector<TreeNode*> children;
    unordered_set<TreeNode*> lockedDescendants; // Faster lookups and inserts

    TreeNode(string nm, TreeNode* par) {
        name = nm;
        parent = par;
        lockedBy = -1;
        isLocked = false;
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
        if (node->isLocked || !node->lockedDescendants.empty()) return false;

        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->isLocked) return false;
            temp = temp->parent;
        }

        // Lock node
        node->isLocked = true;
        node->lockedBy = uid;

        // Update ancestors
        temp = node->parent;
        while (temp) {
            temp->lockedDescendants.insert(node);
            temp = temp->parent;
        }
        return true;
    }

    bool unlock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        if (!node->isLocked || node->lockedBy != uid) return false;

        // Unlock node
        node->isLocked = false;
        node->lockedBy = -1;

        // Update ancestors
        TreeNode* temp = node->parent;
        while (temp) {
            temp->lockedDescendants.erase(node);
            temp = temp->parent;
        }
        return true;
    }

    bool upgradeLock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        if (node->isLocked || node->lockedDescendants.empty()) return false;

        // Check all locked descendants have the same uid
        for (TreeNode* ld : node->lockedDescendants) {
            if (ld->lockedBy != uid) return false;
        }

        // Check ancestors not locked
        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->isLocked) return false;
            temp = temp->parent;
        }

        // Unlock all descendants
        auto copyDesc = node->lockedDescendants; // Copy to avoid invalidation
        for (TreeNode* ld : copyDesc) {
            unlock(ld->name, uid);
        }

        // Lock current node
        return lock(name, uid);
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

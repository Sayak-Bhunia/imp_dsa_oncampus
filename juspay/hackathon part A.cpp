#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string name;
    int lockedBy;             // -1 if unlocked
    bool isLocked;
    int lockedDescendantCount; // Count of locked descendants for fast checks
    TreeNode* parent;
    vector<TreeNode*> children;
    TreeNode(string nm, TreeNode* par) {
        name = nm;
        parent = par;
        lockedBy = -1;
        isLocked = false;
        lockedDescendantCount = 0;
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
            for(int i=0;i<m && idx<n;i++) {
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
        if(node->isLocked || node->lockedDescendantCount > 0) return false;
        // Check ancestors
        TreeNode* temp = node->parent;
        while(temp) {
            if(temp->isLocked) return false;
            temp = temp->parent;
        }
        // Lock the node
        node->isLocked = true;
        node->lockedBy = uid;
        // Update all ancestors' lockedDescendantCount
        temp = node->parent;
        while(temp) {
            temp->lockedDescendantCount++;
            temp = temp->parent;
        }
        return true;
    }

    bool unlock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        if(!node->isLocked || node->lockedBy != uid) return false;
        // Unlock node
        node->isLocked = false;
        node->lockedBy = -1;
        // Update ancestors
        TreeNode* temp = node->parent;
        while(temp) {
            temp->lockedDescendantCount--;
            temp = temp->parent;
        }
        return true;
    }

    bool upgradeLock(string name, int uid) {
        TreeNode* node = nodeMap[name];
        if(node->isLocked || node->lockedDescendantCount == 0) return false;
        // Check all locked descendants have same uid
        if(!checkAllDescendantsSameUser(node, uid)) return false;
        // Check ancestors not locked
        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->isLocked) return false;
            temp = temp->parent;
        }
        // Unlock all descendants
        unlockAllDescendants(node, uid);
        // Lock current node
        return lock(name, uid);
    }

private:
    bool checkAllDescendantsSameUser(TreeNode* node, int uid) {
        if (node->isLocked && node->lockedBy != uid) return false;
        for(TreeNode* child:node->children) {
            if(!checkAllDescendantsSameUser(child, uid)) return false;
        }
        return true;
    }

    void unlockAllDescendants(TreeNode* node, int uid) {
        if(node->isLocked && node->lockedBy == uid) unlock(node->name, uid);
        for(TreeNode* child:node->children) unlockAllDescendants(child, uid);
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> nodes(n);
    for(int i=0;i<n;i++) cin >> nodes[i];
    MAryTree tree(nodes[0]);
    tree.buildTree(nodes, m);
    while(q--) {
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

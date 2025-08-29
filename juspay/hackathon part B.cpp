#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string name;
    int lockedBy; // -1 if unlocked
    bool isLocked;
    int lockedDescendantCount;
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(string nm, TreeNode* par) {
        name = nm;
        parent = par;
        isLocked = false;
        lockedBy = -1;
        lockedDescendantCount = 0;
    }
};

unordered_map<string, TreeNode*> nodeMap;

TreeNode* buildTree(const vector<string>& names, const vector<pair<string, string>>& edges) {
    unordered_map<string, TreeNode*> temp;
    TreeNode* root = nullptr;

    for (auto& nm : names) {
        temp[nm] = new TreeNode(nm, nullptr);
    }

    for (auto& edge : edges) {
        string p = edge.first, c = edge.second;
        temp[c]->parent = temp[p];
        temp[p]->children.push_back(temp[c]);
    }

    if (!names.empty()) root = temp[names[0]];
    nodeMap = temp;
    return root;
}

bool canLock(TreeNode* node) {
    if (node->lockedDescendantCount > 0) return false;
    TreeNode* temp = node->parent;
    while (temp) {
        if (temp->isLocked) return false;
        temp = temp->parent;
    }
    return true;
}

bool lock(string name, int uid) {
    TreeNode* node = nodeMap[name];
    if (node->isLocked) return false;
    if (!canLock(node)) return false;

    node->isLocked = true;
    node->lockedBy = uid;

    TreeNode* temp = node->parent;
    while (temp) {
        temp->lockedDescendantCount++;
        temp = temp->parent;
    }

    return true;
}

bool unlock(string name, int uid) {
    TreeNode* node = nodeMap[name];
    if (!node->isLocked || node->lockedBy != uid) return false;

    node->isLocked = false;
    node->lockedBy = -1;

    TreeNode* temp = node->parent;
    while (temp) {
        temp->lockedDescendantCount--;
        temp = temp->parent;
    }

    return true;
}

bool upgradeLock(string name, int uid) {
    TreeNode* node = nodeMap[name];
    if (node->isLocked || node->lockedDescendantCount == 0) return false;

    vector<TreeNode*> lockedNodes;
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (cur->isLocked) lockedNodes.push_back(cur);
        for (auto child : cur->children) q.push(child);
    }

    if (lockedNodes.empty()) return false;
    for (auto ld : lockedNodes) {
        if (ld->lockedBy != uid) return false;
    }

    TreeNode* temp = node->parent;
    while (temp) {
        if (temp->isLocked) return false;
        temp = temp->parent;
    }

    for (auto ld : lockedNodes) {
        unlock(ld->name, uid);
    }

    return lock(name, uid);
}

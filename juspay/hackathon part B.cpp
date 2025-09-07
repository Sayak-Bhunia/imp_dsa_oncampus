bool lock(string name, int UserId) {
        TreeNode* node = nodeMap[name];
        lock_guard<mutex> guard(node->mtx);
        if (node->isLocked || !node->lockedDescendants.empty()) return false;
        TreeNode* temp = node->parent;
        while (temp) {
            lock_guard<mutex> ancestorGuard(temp->mtx); 
            if (temp->isLocked) return false;
            temp = temp->parent;
        }
        node->isLocked = true;
        node->lockedBy = UserId;
        temp = node->parent;
        while (temp) {
            lock_guard<mutex> ancestorGuard(temp->mtx);
            temp->lockedDescendants.insert(node);
            temp = temp->parent;
        }
        return true;
    }


bool lock(string name, int UserId) {
        TreeNode* node = nodemp[name];
        node->lockedCount++;
        if(node->lockedCount>1 || node->lockedDescendants.size()) {
            node->lockedCount--;
            return false;
        }
        TreeNode* par = node->parent;
        while(par) {
            par->lockedDescendants.insert(node);
            if(par->isLocked || par->lockedCount>0) {
                par->lockedDescendants.erase(node);
                node->lockedCount--;
                TreeNode* par1 = node->parent;
                while(par1 != par) {
                    par1->lockedDescendants.erase(node);
                    par1 = par1->parent;
                }
                return false;
            }
            par = par->parent;
        }
        node->lockedBy = UserId;
        node->isLocked = true;
        return true;
    }


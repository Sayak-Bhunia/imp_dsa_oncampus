bool lock(string name, int id) {
        TreeNode* node = nodeMap[name];

        // Step 1: Check if node is already locked or has locked descendants
        if (node->lockedCount > 0 || !node->lockedDescendants.empty()) {
            return false;
        }

        // Step 2: Check if any ancestor nodes are locked or have locked descendants
        TreeNode* temp = node->parent;
        while (temp) {
            if (temp->lockedCount > 0 || !temp->lockedDescendants.empty()) {
                return false;
            }
            temp = temp->parent;
        }

        // Step 3: Lock the node by incrementing lockedCount
        node->lockedCount = 1;
        node->lockedBy = id;

        // Step 4: Add the node to the lockedDescendants of all ancestors
        temp = node->parent;
        while (temp) {
            temp->lockedDescendants.insert(node);
            temp = temp->parent;
        }

        return true;
    }


bool lock(string name, int UserId) {
        TreeNode* node = nodemp[name];
        node->lockedCount++;
        if(node->lockedCount>1) {
            node->lockedCount--;
            return false;
        }
        TreeNode* par = node->parent;
        while(par) {
            if(par->lockedCount>0 || par->lockedDescendant.size()) {
                node->lockedCount--;
                TreeNode* par1 = node->parent;
                while(par1 != par) {
                    node->lockedDescendant.erase(node);
                    par1 = par1->parent;
                }
                return false;
            }
            par->lockedDescendants.insert(node);
            par = par->parent;
        }
        node->lockedBy = UserId;
        return true;
    }


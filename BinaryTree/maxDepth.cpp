//Problem Explanation:Maximum depth of binary tree ==finding the total number of levels in binary tree.
//Logic:count the levels of binary tree
//Algorithum:Use level order traversal(BFS)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int maxDep=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            maxDep++;
        }
        return maxDep;
        
    }
};

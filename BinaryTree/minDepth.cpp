//Problem explanation:minimum depth of binary tree means the level where you get your first leaf node
//logic:try to find first leaf node and after getting it return 
//Algorithum:you can/should use level order traversal/bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int minDep=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode*temp=q.front();
                q.pop();
                //node is leaf node
                if(temp->left==NULL&&temp->right==NULL)
                {
                     return minDep;
                }
                //go to left side and push into the queue
                if(temp->left!=NULL)
                q.push(temp->left);
                //go to left side and push into the queue
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            minDep++;
        }
        return minDep;
        
    }
};

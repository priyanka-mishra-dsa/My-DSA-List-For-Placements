class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1,ansLevel;
        int maxSum=INT_MIN;
        while(!q.empty())
        {
            int size=q.size();
            int levelSum=0;
            while(size--)
            {
                TreeNode*temp=q.front();
                q.pop();
                levelSum=levelSum+temp->val;
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            if(levelSum>maxSum)
            {
                maxSum=levelSum;
                ansLevel=level;

            }
            level++;
        }
        return ansLevel;
    }
};

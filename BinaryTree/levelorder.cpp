class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        return {};
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            while(size--)
            {
                TreeNode*temp=q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left!=NULL)
                q.push(temp->left);
                if(temp->right!=NULL)
                q.push(temp->right);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};

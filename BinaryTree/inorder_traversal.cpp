class Solution {
public:
void inOrder(TreeNode*root,vector<int>&ans)
{
    if(root==NULL)
    return;
    //go to left
    inOrder(root->left,ans);
    //go to node
    ans.push_back(root->val);
    //go to right
    inOrder(root->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inOrder(root,ans);
        return ans;
        
    }
};

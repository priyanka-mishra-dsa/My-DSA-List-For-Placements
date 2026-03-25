class Solution {
public:
void postOrder(TreeNode*root,vector<int>&ans)
{
    if(root==NULL)
    return;
    //go to left
    if(root->left!=NULL)
    postOrder(root->left,ans);
    //go to right
    if(root->right!=NULL)
    postOrder(root->right,ans);
    //go to node
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postOrder(root,ans);
        return ans;
        
    }
};

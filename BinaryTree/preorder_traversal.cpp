class Solution {
public:
void preOrder(TreeNode*root,vector<int>&ans)
{
    if(root==NULL)
    return;
    //go to node
    ans.push_back(root->val);
    //go to left
    if(root->left!=NULL)
    preOrder(root->left,ans);
    //go to right
    if(root->right!=NULL)
    preOrder(root->right,ans);

}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preOrder(root,ans);
        return ans;
        
    }
};

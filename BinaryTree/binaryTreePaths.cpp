class Solution {
public:
void pre(TreeNode*root,string path,vector<string>&ans)
{
    if(root==NULL)
    return;
    //n
    //node is not a leaf node
    path=path+to_string(root->val);
    //node is leaf node
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(path);
        return;
    }
    path=path+"->";
    //L
    if(root->left!=NULL)
    pre(root->left,path,ans);
    //R
    if(root->right!=NULL)
    pre(root->right,path,ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        pre(root,"",ans);
        return ans;
        
    }
};

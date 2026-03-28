class Solution {
public:
void preOrder(TreeNode*root,string&s)
{
    //base case
    if(root==NULL)
    {
        s=s+"#";
        return;
    }
   //node is a leaf node
   if(root->left==NULL && root->right==NULL)
   {
     s=s+to_string(root->val)+"$";
   }
   //go to left side
   if(root->left!=NULL)
   {
    preOrder(root->left,s);
   }
   //go to right side
   if(root->right!=NULL)
   {
    preOrder(root->right,s);
   }
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        //apply any  traversal
        string s1="";
        string s2="";
        preOrder(root1,s1);
        preOrder(root2,s2);
        if(s1==s2)
        return true;
        else
        return false;    
    }
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        //base cases
        if(root1==NULL)
        {
            return root2;
        }
        if(root2==NULL)
        {
            return root1;
        }
        //preOrder traversal
        //first->present hai node pr
        root1->val=root1->val+root2->val;
        //left jao
        root1->left=mergeTrees(root1->left,root2->left);
        //right
        root1->right=mergeTrees(root1->right,root2->right);
        return root1;
    }
};

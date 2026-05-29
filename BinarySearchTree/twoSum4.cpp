class Solution {
public:
void inorder(TreeNode* root,vector<int>&nums)
{
    if(root==NULL)
    return;
    //left
    if(root->left!=NULL)
    inorder(root->left,nums);
    //node
    nums.push_back(root->val);
    //right
    if(root->right!=NULL)
    inorder(root->right,nums);
}
    bool findTarget(TreeNode* root, int k) {
        //step1:apply inorder in bst->it makes nodes in sorted order
        //step2:now you can apply two pointer on sorted array
        vector<int>nums;//store sorted array ko
        inorder(root,nums);  
        //apply 2 pointer
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i]+nums[j];
            if(sum>k)
            {
                j--;
            }
            else if(sum==k)
            {
                return true;
            }
            else if(sum<k)
            {
                i++;
            }
        }
        return false;
    }
};

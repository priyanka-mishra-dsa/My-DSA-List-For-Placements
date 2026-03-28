class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            //node is a leaf node of left side
            if(temp->left!=NULL && temp->left->left==NULL && temp->left->right==NULL)
            {
                sum=sum+temp->left->val;
            }
            //go to left side and push the value in the queue
            if(temp->left!=NULL)
            q.push(temp->left);
            //go to right side and push the value in the queue
            if(temp->right!=NULL)
            q.push(temp->right);
        }
        return sum;
    }
};

//method1:using bfs(level order traversal)
class Solution {
public:
    int countNodes(TreeNode* root) {
     if(root==NULL)
     return 0;
     int countNodes=0;
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty())
     {
        TreeNode*temp=q.front();
        q.pop();
        countNodes++;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
     }
     return countNodes;
        
    }
};
//method2:only using the given function (DFS)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;

        return (1+countNodes(root->left)+countNodes(root->right));
        
    }
};

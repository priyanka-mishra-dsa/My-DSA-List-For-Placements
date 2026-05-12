class Solution {
public:
pair<int,TreeNode*> findLevelAndParent(TreeNode*root,int target)
{
    //this is not recursion
    //using bfs
    queue<pair<TreeNode*,TreeNode*>>q;
    q.push({root,NULL});
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            TreeNode* node=q.front().first;
            TreeNode*parent=q.front().second;
            q.pop();
            //node ka value hi target ke equal agya
            if(node->val==target)
            {
                return {level,parent};
            }
            //node ka left hai
            if(node->left!=NULL)
            {
                q.push({node->left,node});
            }
            //node ka right hai
            if(node->right!=NULL)
            {
                q.push({node->right,node});
            }
        }
        level++;

    }
    return {-1,NULL};
}
    bool isCousins(TreeNode* root, int x, int y) {
        //bfs function to find level and parent node of given node
        //one by one pass the node
        pair<int,TreeNode*>p1=findLevelAndParent(root,x);
        pair<int,TreeNode*>p2=findLevelAndParent(root,y);
        //satisify both the conditions of cousion node
        int levelX=p1.first;
        int levelY=p2.first;
        TreeNode*parentX=p1.second;
        TreeNode*parentY=p2.second;
        if(levelX==levelY&&parentX!=parentY)
        {
            return true;
        }
        else
        return false;
    }
};

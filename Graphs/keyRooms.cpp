class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //rooms==adj list is already given
        //do simple traversal if you visit all the rooms then return true else return false
        int n=rooms.size();
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int j=0;j<rooms[node].size();j++)
                {
                    int neig=rooms[node][j];
                    if(visited[neig]==0)
                    {
                        q.push(neig);
                        visited[neig] = 1;
                    }
                }
            }
        
        for(int i=0;i<visited.size();i++)
        {
            if(visited[i]==0)
            {
                return false;
            }

            
        }
        return true;
        
    }
};

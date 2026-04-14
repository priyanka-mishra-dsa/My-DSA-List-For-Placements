class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //count provinces(group of nodes or a single node which is not connected to any one)
        int countGraph=0;
        int n=isConnected.size();//total nodes
        vector<bool>visited(n,0);
        queue<int>q;
        //may be it is a disconnected graph
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                q.push(i);
                countGraph++;
                visited[i]=1;
            }
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                //check for node ka neig
                for(int j=0;j<isConnected[node].size();j++)
                {
                    if(visited[j]==0 && isConnected[node][j]==1)
                    {
                        q.push(j);
                        visited[j]=1;
                    }
                }
            }
        }
        return countGraph;
    }
};

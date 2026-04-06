//If you want detect cycle in undirected graph then you can use bfs/dfs traversal
//if you visit any node more than one time and if that node is not a parent node ,that means you cycle is  detected in the graph
//if it is a parent node that means there is no cycle present in the graph
//you need to use  visited,parent vector  and queue to solve this problem using bfs
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        //convert edges into adj list(graph)
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,0);
        vector<int>parent(V,-1);
        queue<int>q;
        //may be graph is disconnected
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                //now check it's neig node
                for(int j=0;j<adj[node].size();j++)
                {
                    int neig=adj[node][j];
                    if(visited[neig]==0)
                    {
                      visited[neig]=1;
                      parent[neig]=node;
                      q.push(neig);
                    }
                    //in undirected graph neig is also the parent of node
                    else if(parent[node]!=neig)
                    {
                        //cycle is detected
                        return true;
                    }
                }
                
            }
           
        }
         return false;
    }
};

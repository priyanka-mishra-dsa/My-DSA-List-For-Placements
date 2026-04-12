        //terminal node=node whose outdegree==0
        //find safe node
        //safe node= A node is a safe node if every possible path starting from that node leads to a terminal node
        //agar koi bhi node cycle me chala gya that means it is not a safe node
        //basically it is like dectect cycle in directed graph
        //you can use topological sort
        class Solution {
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>safeNode;
        //reverse the graph then apply topological sort
        //Every edge (u → v) becomes (v → u)
        vector<vector<int>>revGraph(n);
        vector<int>inDegree(n,0);
        for(int u=0;u<n;u++)
        {
            for(int i=0;i<graph[u].size();i++)
            {
                int v=graph[u][i];
                revGraph[v].push_back(u);
                inDegree[u]++;
            }
        }
        //apply topological sort
        vector<bool>visited(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safeNode.push_back(node);
            for(int i=0;i<revGraph[node].size();i++)
            {
                int neig=revGraph[node][i];
                inDegree[neig]--;
                if(visited[neig]==0&&inDegree[neig]==0)
                {
                    q.push(neig);
                    visited[neig]=1;
                }
            }
        }
        //sort the result
        sort(safeNode.begin(),safeNode.end());
        return safeNode;      
    }
};

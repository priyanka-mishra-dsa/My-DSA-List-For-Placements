class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int vertex=numCourses;
        vector<vector<int>>adj(vertex);
        vector<int>inDegree(vertex,0);
        for(auto&edge:prerequisites)
        {
            int a=edge[0];
            int b=edge[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<vertex;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                inDegree[adj[node][i]]--;
                if( inDegree[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
            }
        }
        //give topological sort order
        if(vertex==ans.size())
        return ans;
        else
        return {};
        
    }
};

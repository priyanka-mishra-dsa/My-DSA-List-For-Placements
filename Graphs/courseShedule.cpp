class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int vertex=numCourses;
        vector<int>inDegree(vertex,0);
        //convert prerequisites into graph
        vector<vector<int>>adj(vertex);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<vertex;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
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
                if(inDegree[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }
        if(vertex==ans.size())
        return true;
        else
        return false;
    }
};

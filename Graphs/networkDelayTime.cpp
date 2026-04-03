//Question based on Dijkstra algortithum
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //convert times into adj list(graph)
        int src=k-1;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++)
        {
            //directed graph
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            adj[u].push_back(make_pair(v,w));
        }
        //step 1:find shortest dist of all nodes from src
        vector<bool>visited(n,0);
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        //take a min heap to select node whose dist is min among all the nodes
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        //intialize min heap
        p.push(make_pair(0,src));
        while(!p.empty())
        {
            int node=p.top().second;
            p.pop();
            //if node is already visited
            if(visited[node]==1)
            continue;
            //not visited
            visited[node]=1;
            //check for its neig node
            for(int i=0;i<adj[node].size();i++)
            {
                int neig=adj[node][i].first;
                int wei=adj[node][i].second;
                if(visited[neig]==0&& dist[neig]>dist[node]+wei)
                {
                    dist[neig]=dist[node]+wei;
                    p.push(make_pair(dist[neig],neig));
                }
            }

        }
        //step2:time taken to give signal from k to all nodes=max dist of node from src to k
        int ans=0,maxV;
        for(int i=0;i<dist.size();i++)
        {
         //for unvisited node
        if(dist[i]==INT_MAX)
        return -1;
         maxV=dist[i];
         ans=max(ans,maxV);
        }
        return ans;
        
    }
};

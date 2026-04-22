class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);//INT_MAX(1e8)
        dist[src]=0;
        //s1:relax the edges V-1 times
        for(int i=0;i<V-1;i++)
        {
            for(int i=0;i<edges.size();i++)
            {
                int node=edges[i][0];
                int neig=edges[i][1];
                int w=edges[i][2];
                //if dist[u]==1e8,skip that node
                if(dist[node]==1e8)
                continue;
                if(dist[neig]>dist[node]+w)
                {
                    dist[neig]=dist[node]+w;
                }
            }
        }
        //s2:realax edges one more time to detect cycle
        //agar dist vector ki value update ho jati hai mtlb -ve cycle is present
        
        for(int i=0;i<edges.size();i++)
        {
           int node=edges[i][0];
           int neig=edges[i][1];
           int w=edges[i][2];
           //detect -ve cycle
           if(dist[node]==1e8)
           continue;
           if(dist[neig]>dist[node]+w)
           {
               //mtlb value update hone wali hai
               //neg cycle is present
               return {-1};
           }
        }
        return dist;
        
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
      //given weight->as probobility
      //find that path from start node to end whose multiplication prob is max
      //normal dijkstra->dist vector,min heap,dist[start]=0;
      //but in this case->prob vector,max heap,prob[start]=1;
      
      //s1:build graph
      vector<vector<pair<int,double>>>adj(n);
      for(int i=0;i<edges.size();i++)
      {
         int u=edges[i][0];
         int v=edges[i][1];
         double p=succProb[i];
         adj[u].push_back({v,p});
         adj[v].push_back({u,p});
      }
      //s2:max heap,create prob vector
      vector<double>prob(n,0.0);//for each store max prob
      //give max prob to start(src)node
      prob[start_node]=1;
      priority_queue<pair<double,int>>p;
      //intialize max heap
      p.push({prob[start_node],start_node});
      while(!p.empty())
      {
        double currentProb=p.top().first;
        int node=p.top().second;
        p.pop();
        //if node is the end(destination) node
        if(node==end_node)
        {
            return currentProb;
        }
        //traverse neig node and give them max prob
        for(int i=0;i<adj[node].size();i++)
        {
            int neig=adj[node][i].first;
            double neigProb=adj[node][i].second;
            if(prob[neig]<prob[node]*neigProb)
            {
                prob[neig]=prob[node]*neigProb;
                p.push({prob[neig],neig});
            }
        }
      }
      return 0.0;
  }
};

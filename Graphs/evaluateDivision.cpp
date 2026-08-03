class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //step1:make a graph using equations
        unordered_map<string,vector<pair<string,double>>>graph;
        for(int i=0;i<equations.size();i++)
        {
            string u=equations[i][0];//"a"
            string v=equations[i][1];//"b"
            double wt=values[i];
            //store both case of edge
            //a->b and a<-b
            graph[u].push_back({v,wt});
            graph[v].push_back({u,1.0/wt});
        }
        //
        vector<double>ans;
        //step2:find value of each queries of given queries
        for(int i=0;i<queries.size();i++)
        {
            string src=queries[i][0];
            string destination=queries[i][1];
            //if src or dest any one not present in the graph then return -1;
            if(graph.count(src)==0 || graph.count(destination)==0)
            {
                ans.push_back(-1.0);
                continue;
            }
            //step3:take visited array and queue
            queue<pair<string,double>>q;
            unordered_map<string,bool>visited;
            //step 4 :push src into queue and mark as visited
            q.push({src,1.0});
            visited[src]=1;
            double result=-1.0;
            while(!q.empty())
            {
                string node=q.front().first;
                double wt=q.front().second;
                q.pop();
                //check we get a destination node or not
                if(node==destination)
                {
                    result=wt;
                    break;
                }
                //visit neig node
                for(int j=0;j<graph[node].size();j++)
                {
                    string neig=graph[node][j].first;
                    double neigWt=graph[node][j].second;
                    if(visited[neig]==0)
                    {
                        q.push({neig,wt*neigWt});
                        visited[neig]=1;
                    }    
                }
            }
            ans.push_back(result);
        }
        return ans; 
    }
};

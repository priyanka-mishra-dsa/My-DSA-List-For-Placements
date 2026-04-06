//Bipartite Graph:if we can divide all the vertex of graph into two disjoint set so that no two adjacent vertex is present in the same set
                 //that means it is a bipartite graph.
//Algorithum:2-coloring Algorithum(using bf/dfs)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //using bfs 2-coloring method
        int v=graph.size();
        vector<int>color(v,-1);
        queue<int>q;
        //may be it is a disconnect graph check for all the vertex
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                //assign color to node
                color[i]=0;
                //push the node into the queue
                q.push(i);
            }
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                //check for its neig
                for(int j=0;j<graph[node].size();j++)
                {
                    int neig=graph[node][j];
                    //color is not assigned to neig node
                    if(color[neig]==-1)
                    {
                        //assign color opposite to node
                        color[neig]=(color[node]+1)%2;
                        //push into the que
                        q.push(neig);
                    }
                    //color is already assign check that agar same color hua toh return false
                    else if(color[neig]==color[node])
                    {
                        return false;
                    }

                }
            }
        }
        return true;
        
    }
};

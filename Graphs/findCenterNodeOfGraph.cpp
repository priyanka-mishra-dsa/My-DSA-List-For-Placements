class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //find center wala node
        //indegree of center node==n-1(no of edges)
        int n=edges.size()+1;
        vector<int>inDegree(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            inDegree[u]++;
            inDegree[v]++;
        }
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==n-1)
            {
                return i;
            }
        }
        return -1;
        
    }
};

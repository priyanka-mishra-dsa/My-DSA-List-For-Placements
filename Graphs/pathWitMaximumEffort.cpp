class Solution {
public:
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
int r,c;
bool valid(int i,int j)
{
    return i>=0&&i<r && j>=0 && j<c;
}
    int minimumEffortPath(vector<vector<int>>& heights) {
        //how to think that this question is solve using dijkstra algorithum
           //1.src(0,0) and destination(r-1,c-1)given hai
           //2.trval from src to destination and find minimum effort(shortest path)
           //3.cost/weight also given 
        
         r = heights.size();
         c = heights[0].size();
        //2d matrix hai ->take 2d dist array for dijkstra which stores shortest dist from src to each node
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
        dist[0][0]=0;//dist of src (0,0)
        //treat (r,c)indexes as node
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p;
        //intialize min heap
        p.push(make_pair(0,make_pair(0,0)));
        while(!p.empty())
        {
            int effort=p.top().first;
            int Row=p.top().second.first;
            int Col=p.top().second.second;
            p.pop();
            //reached at r,c of destination node
            if(Row==r-1 && Col==c-1)
            return effort;
            //move in 4 directions to visit node
            for(int k=0;k<4;k++)
            {
                int r1=Row+row[k];
                int c1=Col+col[k];
                if(valid(r1,c1))
                {
                    //calculate effort(cause we move from a->b)
                    int newEffort=max(effort,abs(heights[Row][Col]-heights[r1][c1]));
                    if(dist[r1][c1]>newEffort)
                    {
                       dist[r1][c1]=newEffort;
                       p.push(make_pair(dist[r1][c1],make_pair(r1,c1)));
                    }
                }
            }

        }
        return 0;
    }
};

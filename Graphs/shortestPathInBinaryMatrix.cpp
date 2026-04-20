//:using bfs
class Solution {
public:
int r,c;
int row[8]={-1,-1,-1,0,0,1,1,1};
int col[8]={-1,0,1,-1,1,-1,0,1};
bool valid(int i,int j)
{
     return i>=0&&i<r && j>=0 && j<c;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //using bfs
        r=grid.size();
        c=grid[0].size();
        //path me move tabhi kr sakte hai jab 0 hoga
        //first and last cell should not be 1 wala cell
        if(grid[0][0]==1||grid[r-1][c-1]==1)
        {
            return -1;
        }
        queue<pair<int,int>>q;
        //given that start from 0,0 index
        q.push(make_pair(0,0));
        //jis cell ko queue me push kr diya mark as visited
        grid[0][0]=1;
        //basically length of shortest path=level of bfs+1
        int level=0;
        while(!q.empty())
        {
            int current=q.size();
            while(current--)
            {
                int Row=q.front().first;
                int Col=q.front().second;
                q.pop();
                //if i reached at distination(n-1,n-1) return level
                if(Row==r-1 && Col==c-1)
                {
                    return level+1;
                }
                //otherwise current cell will move in 8 direction where cell value is 0
                for(int k=0;k<8;k++)
                {
                    if(valid(Row+row[k],Col+col[k])&& grid[Row+row[k]][Col+col[k]]==0)
                    {
                        //make that cell value as 1
                        grid[Row+row[k]][Col+col[k]]=1;
                        //push into the queue
                        q.push(make_pair(Row+row[k],Col+col[k]));
                    }
                }
            }
             level++;
        }
        return -1;
        
    }
};

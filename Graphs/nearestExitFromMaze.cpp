class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r && j>=0 &&j<c;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //nearest exit->means shortest exist(solve using bfs)
        r=maze.size();
        c=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        //mark as visited
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
              int Row=q.front().first;
              int Col=q.front().second;
              q.pop();
            //check that row and col index is exit(boundary) or not
            //entrance in some cases may be present at boundary
               if((Row==0||Row==r-1||Col==0||Col==c-1)&& !(Row==entrance[0]&& Col==entrance[1]))
               {
                 //present at boundary but it is not entrance entry
                  return steps;
               }
               //explore neig in 4 directions
               for(int k=0;k<4;k++)
               {
                  int r1=Row+row[k];
                  int c1=Col+col[k];
                  if(valid(r1,c1)&&maze[r1][c1]=='.')
                  {
                     q.push({r1,c1});
                     //mark as visited
                     maze[r1][c1]='+';
                  }

               }
            }
            steps++;
        }
        return -1;
    }
};

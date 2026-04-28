class Solution {
  public:
  //group->(±2, ±1) OR (±1, ±2)
  //(±2, ±1)->x moves 2 steps,y move 1 steps
  //{(2,1),(2,-1),(-2,1)),(-2,-1)}
  //(±1, ±2)->x moves 1 step,y moves 2 steps
  //[(1,2),(1,-2),(-1,2),(-1,-2)]
  int row[8]={2,2,-2,-2,1,1,-1,-1};
  int col[8]={1,-1,1,-1,2,-2,2,-2};
 bool valid(int i,int j,int n)
  {
    return i>=0&&i<n && j>=0&&j<n; 
  }
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        //min step find to reach src to target
        //you can apply bfs
        //horse 1 step move
        //1 step=2 step horizontal or vertical+1 step perpedicular
        
        //make 0 based indexing
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        //edge case
        if (KnightPos[0] == TargetPos[0]&&KnightPos[1] == TargetPos[1])
        return 0;
        queue<pair<int,int>>q;
        //2d grid not given,build grid
        vector<vector<bool>>chess(N,vector<bool>(N,0));
        q.push({KnightPos[0],KnightPos[1]});
        //initial position mark as visited
        chess[KnightPos[0]][KnightPos[1]]=1;
        int steps=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int Row=q.front().first;
                int Col=q.front().second;
                q.pop();
                for(int k=0;k<8;k++)
                {
                    int r=Row+row[k];
                    int c=Col+col[k];
                    //neig node is target
                    if(r==TargetPos[0]&& c==TargetPos[1])
                    {
                        return steps+1;
                    }
                    if(valid(r,c,N)&&chess[r][c]==0)
                    {
                        q.push({r,c});
                        chess[r][c]=1;
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
};

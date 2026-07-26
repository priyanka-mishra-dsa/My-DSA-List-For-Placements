//4d dp (recursion+memorization)
class Solution {
public:
int m,n;
int solve(int r1,int c1,int r2,int c2,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp)
{
    //handle out of bound
    if(r1>=m || r1<0 || c1>=n ||c1<0)
    return 0;
    if(r2>=m || r2<0 || c2>=n ||c2<0)
    return 0;
    //handle base case(both robots should reach at the last row)
    if(r1==m-1 && r2==m-1)
    {
        //both present at same cell
        if(c1==c2)
        {
            return grid[r1][c1];
        }
        //both present at different cell
        else
        {
           return grid[r1][c1]+grid[r2][c2];
        }
    }
    //dp
    if(dp[r1][c1][r2][c2]!=-1)
    return dp[r1][c1][r2][c2];
    //3 directions row+1 in each case but
    //value of col changes in every case(-1,0,1)
    //for each dir of rob1,rob3 all direc check krenge
    int cherris;
    if(c1==c2)
    cherris=grid[r1][c1];
    else
    cherris=grid[r1][c1]+grid[r2][c2];
    int maxCherry=0,pathSum=0;
    for(int d1=-1;d1<=1;d1++)
    {
       for(int d2=-1;d2<=1;d2++)
       {
          pathSum=cherris+solve(r1+1,c1+d1,r2+1,c2+d2,grid,dp);
          maxCherry=max(maxCherry,pathSum);
       }
    }
    //before return store the value
    dp[r1][c1][r2][c2]=maxCherry;
    return maxCherry;
}
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //take 4d dp bcs all states are changing
        vector<vector<vector<vector<int>>>>dp(m,vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(n,-1))));
        //pass cordinates of robots in recursion
        int ans=solve(0,0,0,n-1,grid,dp);
        return ans;  
    }
};
//3d dp(recursion+memorization)
class Solution {
public:
int m,n;
int solve(int row,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
{
    //handle out of bound
    if(row>=m || row<0 || c1>=n || c1<0 || c2>=n || c2<0)
    return 0;   
    //handle base case(both robots should reach at the last row)
    if(row==m-1)
    {
        //both present at same cell
        if(c1==c2)
        {
            return grid[row][c1];
        }
        //both present at different cell
        else
        {
           return grid[row][c1]+grid[row][c2];
        }
    }
    //dp
    if(dp[row][c1][c2]!=-1)
    return dp[row][c1][c2];
    //3 directions row+1 in each case but
    //value of col changes in every case(-1,0,1)
    //for each dir of rob1,rob3 all direc check krenge
    int cherris;
    if(c1==c2)
    cherris=grid[row][c1];
    else
    cherris=grid[row][c1]+grid[row][c2];
    int maxCherry=0,pathSum=0;
    for(int d1=-1;d1<=1;d1++)
    {
       for(int d2=-1;d2<=1;d2++)
       {
          pathSum=cherris+solve(row+1,c1+d1,c2+d2,grid,dp);
          maxCherry=max(maxCherry,pathSum);
       }
    }
    //before return store the value
    dp[row][c1][c2]=maxCherry;
    return maxCherry;
}
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        //take 3d dp bcs all states are changing(row same in both case)
        //r1 and r2 consider as a same state
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));      
        //pass cordinates of robots in recursion
        int ans=solve(0,0,n-1,grid,dp);
        return ans;  
    }
};
//Tabulation
class Solution {
public:
int m,n;
  int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));      
        //handle base case which is last row (fill last row in the table )
         // Both robots are on the last row
        for(int c1=0;c1<n;c1++)
        {
            for(int c2=0;c2<n;c2++)
            {
                if(c1==c2)
                {
                    dp[m-1][c1][c2]=grid[m-1][c1];
                }
                else
                {
                    dp[m-1][c1][c2]=grid[m-1][c1]+grid[m-1][c2];;
                }
            }
        }
        //handle last row
        //start iteration from second last row
        for(int row=m-2;row>=0;row--)
        {
           //for rob1  1 move
           for(int c1=0;c1<n;c1++)
           {
            //rob2 3 moves
            for(int c2=0;c2<n;c2++)
            {
                //current cherris
                int cherris;
                //both robots present at the same sell
                if(c1==c2)
                cherris=grid[row][c1];
                else
                {
                    cherris=grid[row][c1]+grid[row][c2];
                }
                //we want max path sum
                int maxPathSum=0;
                //go given direction and find maxPathsum
                for(int d1=-1;d1<=1;d1++)
                {
                    for(int d2=-1;d2<=1;d2++)
                    {
                        int nextc1=c1+d1;
                        int nextc2=c2+d2;
                        //valid col
                        if(nextc1>=0 && nextc1<n && nextc2>=0 && nextc2<n)
                        {
                            int pathSum=cherris+dp[row+1][nextc1][nextc2];
                            maxPathSum=max(maxPathSum,pathSum);
                        }
                    }
                }
                //store
                dp[row][c1][c2]=maxPathSum;
            }

           }
        }
        return dp[0][0][n-1];
    }
};

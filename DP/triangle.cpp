class Solution {
public:
//recursion+memorization->TLE
// int solve(int i,int j,int row,vector<vector<int>>& triangle,vector<vector<int>>&dp)
// {
//     //Base case
//     if(i==row-1)//you reach at the last row
//     {
//         //return the value
//         return triangle[i][j];
//     }
//     //
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     //
//     int move1=solve(i+1,j,row,triangle,dp);
//     int move2=solve(i+1,j+1,row,triangle,dp);
//     int minPathSum=triangle[i][j]+min(move1,move2);
//     //store before return
//     dp[i][j]=minPathSum;
//     return minPathSum;
// }
    int minimumTotal(vector<vector<int>>& triangle) {
        //Bottom-Up dp
        int row=triangle.size();
        //2d dp
        vector<vector<int>>dp=triangle;//to make dp same as triangle
        //last row ki value remain same hogi
        //isliye start iteration for second last row
        for(int i=row-2;i>=0;i--)
        {
            //for col in each row
            for(int col=0;col<=i;col++)
            {
                int move1=dp[i+1][col];
                int move2=dp[i+1][col+1];
                int minPathSum=triangle[i][col]+min(move1,move2);
                //store the value
                dp[i][col]=minPathSum;
            }
        }
        return dp[0][0];
    }
};

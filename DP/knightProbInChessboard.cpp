//recursion+memorization
class Solution {
public:
int row1[8]={-2,-2,-1,-1,1,1,2,2};
int col1[8]={-1,1,-2,2,-2,2,-1,1};
double solve(int n,int row,int col,int moves,vector<vector<vector<double>>>&dp)
{
    //handle out of bound
    if(row<0 || row>=n || col<0 || col>=n)
    return 0;
    //base case
    if(moves==0)
    return 1;
    if(dp[row][col][moves]!=-1)
    return dp[row][col][moves];
    //8 moves
    double prob=0.0;
    for(int i=0;i<8;i++)
    {
      int newRow=row+row1[i];
      int newCol=col+col1[i];
      prob=prob+solve(n,newRow,newCol,moves-1,dp);
    }
    double ans=prob/8.0;
    //store
    dp[row][col][moves]=ans;
    return ans;
}
    double knightProbability(int n, int k, int row, int column) {
        //3 state dp
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        double ans=solve(n,row,column,k,dp);
        return ans;   
    }
};
//Tabulation
class Solution {
public:
int row1[8]={-2,-2,-1,-1,1,1,2,2};
int col1[8]={-1,1,-2,2,-2,2,-1,1};
    double knightProbability(int n, int k, int row, int column) {
        //3 state dp
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,0.0)));
        //base case in memo->if(moves==0) return 1;
        //handle base case in tabulation
        for(int i=0;i<n;i++)
        {
            for(int col=0;col<n;col++)
            {
                dp[i][col][0]=1.0;
            }
        }
        //start iteration
        for(int i=1;i<=k;i++)
        {
            for(int r=0;r<n;r++)
            {
                for(int col=0;col<n;col++)
                {
                    //cover 8 moves
                    double prob=0.0;
                    for(int m=0;m<8;m++)
                    {
                        int newRow=r+row1[m];
                        int newCol=col+col1[m];
                        //check out of bound cond before move
                        if(newRow>=0 && newRow<n && newCol>=0 && newCol<n)
                        {
                            prob=prob+dp[newRow][newCol][i-1];
                        }
                    }
                    //store
                    dp[r][col][i]=prob/8.0;
                }
            }
        } 
        return dp[row][column][k];
    }
};

class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool dfs(vector<vector<char>>& board, string &word,int i,int j,int wordIdx)
{
     //base case
     if(wordIdx==word.size())
     return true;
     //
     if(i<0||i>=r||j<0||j>=c||board[i][j]=='#')
     {
        return false;
     }
     if(board[i][j]!=word[wordIdx])
     {
        return false;
     }
     char temp=board[i][j];//store kiya cause backtracking bhi krna hai
     //mark as visited
     board[i][j]='#';
     //go in for directions
     for(int k=0;k<4;k++)
     {
        int Row=i+row[k];
        int Col=j+col[k];
        if(dfs(board,word,Row,Col,wordIdx+1))
        {
            return true;
        }
     }
     //backtrack fir se char ko same bana do
     board[i][j]=temp;
     return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        //solve using dfs+backtracking
        r=board.size();
        c=board[0].size();
        //traverse every row and col index of grid
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
};

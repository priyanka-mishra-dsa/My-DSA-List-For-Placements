class Solution {
public:
bool isValid(int row,int col,char &ch,vector<vector<char>>& board)
{
    //check ki row and col me given char ek hi bar ana chahiye
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==ch)
        return false;
        if(board[i][col]==ch)
        return false;
    }
    //check 3*3 grid me ch wala digit already toh present nhi hai na
    int start_i=(row/3)*3;
    int start_j=(col/3)*3;
    for(int i=start_i;i<start_i+3;i++)
    {
        for(int j=start_j;j<start_j+3;j++)
        {
            if(board[i][j]==ch)
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board)
{
    //traverse in 9*9 board and find empty cell
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                //valid char from 1 to 9 insert krna hai
                for(char ch='1';ch<='9';ch++)
                {
                    if(isValid(i,j,ch,board)==true)
                    {
                        //insert kr sakte hai
                        board[i][j]=ch;
                        //again explore board
                        if(solve(board)==true)
                        {
                            return true;
                        }
                        //agar value false ati hai 
                        //mtlb galat shuduku valid nhi hai toj
                        //jaha pr char insert kiya tha waha pr phir se empty cell dal do
                        //means backtracking
                        board[i][j]='.';
                    }
                }
                //koi valid no nhi insert kar paye in suduku
                return false;
            }
        }
    }
    //if all cells are filled no one is empty
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);    
    }
};

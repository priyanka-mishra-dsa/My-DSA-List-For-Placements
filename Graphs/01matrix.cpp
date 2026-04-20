class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r && j>=0&&j<c;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //distance of 0 from each cell
        //distance between adjacent cell is 1
        //solve using bfs
        r=mat.size();
        c=mat[0].size();
        vector<vector<int>>dist(r,vector<int>(c,-1));
        queue<pair<int,int>>q;
        //pure 2d matrix me traverse kro cell 0 ko queue me push kro and mark distance as 0
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push(make_pair(i,j));
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int Row=q.front().first;
            int Col=q.front().second;
            q.pop();
            //go in 4 direction and update dist array
            for(int k=0;k<4;k++)
            {
                if(valid(Row+row[k],Col+col[k])&& dist[Row+row[k]][Col+col[k]]==-1)
                {
                   dist[Row+row[k]][Col+col[k]]=dist[Row][Col]+1;
                   q.push(make_pair(Row+row[k],Col+col[k]));
                }
            }
        }
        return dist;
    }
};

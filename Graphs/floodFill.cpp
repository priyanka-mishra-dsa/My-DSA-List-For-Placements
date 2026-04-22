class Solution {
public:
int r,c;
int row[4]={-1,1,0,0};
int col[4]={0,0,-1,1};
bool valid(int i,int j)
{
    return i>=0&&i<r&&j>=0&&j<c;
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         r=image.size();
         c=image[0].size();
        //change only that adjacent neig of image[sr][sc] whose color is same as image[sr][sc]
        int originalColor=image[sr][sc];
        if(originalColor==color)
        return image;
        //modify ans in the given grid and return it
        queue<pair<int,int>>q;
        q.push({sr,sc});
        //mark as visited
        image[sr][sc]=color;
        while(!q.empty())
        {
            int Row=q.front().first;
            int Col=q.front().second;
            q.pop();
            //visit adj neig in 4 directions
            for(int k=0;k<4;k++)
            {
                int r1=Row+row[k];
                int c1=Col+col[k];
                if(valid(r1,c1)&&image[r1][c1]==originalColor)
                {
                    //agar adjacent ka color same rahega as starting row,col then color will be change
                    q.push({r1,c1});
                     image[r1][c1]=color;
                }
            }
        }
        return image;    
    }
};

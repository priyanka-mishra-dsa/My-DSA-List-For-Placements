class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //start->target(a index whose value is 0)
        //at any index when we can move in multiple directions(eg.up,down,left,right)
        //in this we have to move only in left and right direction
        //so,we can use bfs here
        int n=arr.size();
        queue<int>q;
        q.push(start);
        vector<bool>visited(n,0);
        visited[start]=1;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            //at this index arr[index]==0(target mil gya)
            if(arr[i]==0)
            {
                return true;
            }
            //at index i ,i can move in left and right direction(visit neig)
            //move to left index
            int left=i-arr[i];
            if(left>=0&&visited[left]==0)
            {
                q.push(left);
                visited[left]=1;
            }
            //move to right index
            int right=i+arr[i];
            if(right<n && visited[right]==0)
            {
                q.push(right);
                visited[right]=1;
            }
        }
        return false;           
    }
};

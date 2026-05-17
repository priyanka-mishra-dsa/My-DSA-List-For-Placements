class Solution {
public:
    int minJumps(vector<int>& arr) {
        //first index->consider as->start node=0
        //last index->consider as->target node=n-1
        //0 to n-1 tak jana hai in minimum no of steps
        //use bfs here
        //from any i we can move in 3 directions
        int n=arr.size();
        int start=0;
        int target=n-1;
        queue<int>q;
        vector<bool>visited(n,0);
        q.push(start);
        visited[start]=1;
        int steps=0;
        //for moving in 3rd direction
        //if i and j index value is same we can
        //directly jump from i to j index
        //store all indices which having the same values
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            int value=arr[i];
            m[value].push_back(i);
        }
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int i=q.front();
                q.pop();
                if(i==target)
                {
                    return steps;
                }
                //from i we can move in 3 directions
                //left direction
                int left=i-1;
                if(left>=0 && visited[left]==0)
                {
                    q.push(left);
                    visited[left]=1;
                }
                //from i move right direction
                int right=i+1;
                if(right<n && visited[right]==0)
                {
                    q.push(right);
                    visited[right]=1;
                }
                //direct jump from i to j when values are same
                for(int j=0;j<m[arr[i]].size();j++)
                {
                    int index=m[arr[i]][j];
                    if(visited[index]==0)
                    {
                        q.push(index);
                        visited[index]=1;
                    }
                }
                //remove same value which is visited from the map
                m[arr[i]].clear();
            }
            steps++;
        }
        return 0;  
    }
};

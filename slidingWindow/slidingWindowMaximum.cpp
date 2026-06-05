class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //using sliding window + priority queue(max heap)
        int n=nums.size();
        vector<int>ans;
        //max heap
        priority_queue<pair<int,int>>p;//{value,index}
        //pointers to make sliding window
        int i=0;
        for(int j=0;j<n;j++)
        {
            //push current element in the heap
            p.push({nums[j],j});
            if(j-i+1>k)
            {
               i++;//for decrease window size
            }
            //remove element from heap which is not present in [i,j]
            //when window size>k

            while(!p.empty()&& p.top().second<i)
            {
                p.pop();

            }
            //valid window form
            if(j-i+1==k)
            {
                int maxElem=p.top().first;
                ans.push_back(maxElem);
            }

        }
        return ans;   
    }
};

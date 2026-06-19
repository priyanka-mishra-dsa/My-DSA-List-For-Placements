class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        //solve using binary search
        int n=arr.size();
        int start=0, end=n-1,mid=0;
        int ans=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(arr[mid]==k)
            {
              ans=mid;
              //left side
              end=mid-1;
            }
            else if(arr[mid]<k)
            {
                
                start=mid+1;
            }
            else
            end=mid-1;
        }
        return ans;
    }
};

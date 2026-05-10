class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //solve using sliding window+set(to check duplicate values)
        //shrink window size when abs(i-j)>k->move i pointer
        int n=nums.size();
        unordered_set<int>st;
        int i=0,j=0;
        while(j<n)
        {
          if(abs(i-j)<=k)
          {
            //inc window size
            //agar element set me present nhi hai
            //tab insert kr do set me
            if(st.count(nums[j])==0)
            {
                st.insert(nums[j]);
                j++;
            }
            else//set me value already present hai mtlb duplicate hua
            {
                return true;
            }
          }
          else if(abs(i-j)>k)
          {
            //window ka size limit se bada hogya 
            //dec window size
            //remove element from set which is pointed by i pointer
            st.erase(nums[i]);
             i++;
          }
        }
        return false;
        
    }
};

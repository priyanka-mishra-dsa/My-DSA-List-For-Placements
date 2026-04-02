
class Solution {
  public:
    bool findPair(vector<int> &arr, int x) {
        // sort the given array
        sort(arr.begin(),arr.end());
        //20 50 70 80 90
        //use 2 pointer
        int i=0,j=1;
        while(j<arr.size())
        {
            //when both pointer points the same value
            if(i==j)
            j++;
            if(arr[j]-arr[i]<x)
            {
                //inc the diff 
                j++;
            }
            else if(arr[j]-arr[i]>x)
            {
                //dec the diff
                i++;
            }
            else if(arr[j]-arr[i]==x)
            {
                return true;
            }
            
        }
        return false;
    
    }
};

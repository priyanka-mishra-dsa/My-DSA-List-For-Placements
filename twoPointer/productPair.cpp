class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        // sort the array
        sort(arr.begin(),arr.end());
        //9 10 20 40,x=400
        //use 2 pointer
        int i=0,j=arr.size()-1;
        while(i<j)
        {
            long long product=1LL*arr[i]*arr[j];
            if(product<x)
            {
                //increase the value
                //move i pointer
                i++;
            }
            else if(product>x)
            {
               //decrease the value
               //move j pointer
                j--; 
            }
            else if(product==x)
            {
                return true;
            }
        }
        return false;
        
    }
};

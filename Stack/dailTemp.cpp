class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //each element apne right side me check kr raha hai next greater element
        //Next Greater Element on RIGHT
        int n=temperatures.size();
        vector<int>ans(n,0);
        //take a stack aur usme index of element store krna 
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                //ek piche wale index pr value update krna hai
                //find index
                int prevIndex=st.top();
                st.pop();
                //update value
                ans[prevIndex]=i-prevIndex;
                
            }
            st.push(i);
        }
       return ans; 
    }
};

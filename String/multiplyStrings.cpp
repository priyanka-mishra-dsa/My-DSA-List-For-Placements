class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int>result(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int digit1=num1[i]-'0';
                int digit2=num2[j]-'0';
                int multiply=digit1*digit2;
                //index for unit digit and carry
                int idx1=i+j+1;
                int idx2=i+j;
                //Add carry which is present same index with current value
                int total=result[idx1]+multiply;
                result[idx1]=total%10;
                result[idx2]+=total/10;
            }
        }
        //convert result array into string
        string ans="";
        for(int i=0;i<result.size();i++)
        {
            ans=ans+to_string(result[i]);
        }
        //may be in ans string some leading zeroes are present so skip that zero
        int i=0;
        while(i<ans.size()&&ans[i]=='0')
        {
            i++;
        }
        ans=ans.substr(i);
        // handle case like "0000"
        if(ans=="")
        return "0";
         return ans;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        //ignore extra spaces present at the front of string
        while(i<n && s[i]==' ')
        {
            //skip the space
            i++;
        }
        //handle sign
        int sign=1;//by default sign is positive
        if(i<n && s[i]=='-')
        {
            sign=-1;
            //move pointer
            i++;
        }
        else if(i<n && s[i]=='+')
        {
            i++;
        }
        //convert string into digit
        long long result=0;
        while(i<n && isdigit(s[i]))
        {
            //convert each char of string into digit
            int digit=s[i]-'0';
            //handle overflow
            if(result>INT_MAX/10 ||(result==INT_MAX/10 &&digit>7))
            {
                return sign==1?INT_MAX:INT_MIN;
            }
            result=result*10+digit;
            //move pointer for other digit
            i++;
        }
        return sign*result;        
    }
};

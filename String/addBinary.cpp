class Solution {
public:
string add(string a,string b)//in each case length of b is small
{
    string result="";
    int index1=a.size()-1;
    int index2=b.size()-1;
    int sum,carry=0;
    while(index2>=0)
    {
        sum=(b[index2]-'0')+(a[index1]-'0')+carry;
        carry=sum/2;
        //convert digit into char to store in the string
        char ch=(sum%2)+'0';
        result.push_back(ch);
        index1--;
        index2--;       
    }
    //bade length wali string bach gyi usko bhi add krna pdega
    while(index1>=0)
    {
        sum=(a[index1]-'0')+carry;
        carry=sum/2;
        char ch=(sum%2)+'0';
        result.push_back(ch);
        index1--;
    }
    //carry is remaining also add that carry in result value
    if(carry!=0)
    {
        char ch=carry+'0';
        result.push_back(ch);
    }
    //reverse the result
    reverse(result.begin(),result.end());
    return result;
}
    string addBinary(string a, string b) {
       if(a.size()>=b.size())
       return add(a,b);
    //    else if(b.size()>a.size())
       return add(b,a);
        
    }
};

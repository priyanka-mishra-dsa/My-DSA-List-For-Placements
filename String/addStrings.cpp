class Solution {
public:
string add(string num1,string num2)
{
    int index1=num1.size()-1;
    int index2=num2.size()-1;
    int sum,carry=0;
    string result="";
    while(index2>=0)
    {
        sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
        carry=sum/10;
        char ch=(sum%10)+'0';
        result.push_back(ch);
        index1--;
        index2--;
    }
    //bada size wala string back gya hai usko bhi add kro in string
    while(index1>=0)
    {
        sum=(num1[index1]-'0')+carry;
        carry=sum/10;
        char ch=(sum%10)+'0';
        result.push_back(ch);
        index1--;
    }
    //carry bach gya add also in result
    if(carry!=0)
    {
        char ch=carry+'0';
        result.push_back(ch);
    }
    //reverse the result
    reverse(result.begin(),result.end());
    return result;
}
    string addStrings(string num1, string num2) {
        if(num1.size()>=num2.size())
        return add(num1,num2);
        else
        return add(num2,num1);        
    }
};

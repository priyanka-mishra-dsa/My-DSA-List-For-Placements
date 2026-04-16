class Solution {
public:
    string defangIPaddr(string address) {
        string ans="";
        for(int i=0;i<address.size();i++)
        {
            if(address[i]=='.')
            {
               ans=ans+"[.]";
            }
            else if(address[i]!='.')
            {
                char ch=address[i];
               ans.push_back(ch);
            }
        }
        return ans;
    }
};

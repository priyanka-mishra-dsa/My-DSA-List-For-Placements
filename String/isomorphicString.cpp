//**imp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //Isomorphic means->converting all the char of s into t using one to one mapping.
        //one to one mapping->one char can map(replace)with one char not multiple char
        //you need to check for both the string means s->t and t->s 

        if(s.size()!=t.size())
        return false;
        unordered_map<char,char>m;
        for(int i=0;i<s.size();i++)
        {
            char original=s[i];
            char replacement=t[i];
            //if original value is not present in map then store
            if(m.count(original)==0)
            {
                 // check if b is already mapped to some other character means not isomorphic
                 for(auto it:m)
                 {
                    char value=it.second;
                    if(value==replacement)
                    {
                        return false;
                    }
                 }
                 //replacement value is also not present
                 m[original]=replacement;
            }
            //original value is present on map
            else if(m.count(original)!=0)
            {
                if(m[original]!=replacement)
                return false;
            }
            
        }
        return true;
        
    }
};

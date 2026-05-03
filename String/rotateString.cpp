class Solution {
public:
    bool rotateString(string s, string goal) {
    //s->abcde,goal->cdeab
    //rotation:
    //bcdea
    //cdeab
    //deabc
    //eabcd
    //all rotations comes from s+s->abcdeabcde(all rotations are substring)

    //start solving
    if(s.size()!=goal.size())
    {
        //we cannot rotate s if both having diff size
        return false;
    }
    //s+s
    string doubleS=s+s;
    //goal will be present in double
    //find start index of goal
    int startPos=doubleS.find(goal);
    if(startPos==-1)
    {
       return false;//means goal is not present
    } 
    else
    return true;   
    }
};

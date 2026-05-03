class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //greedy(sort+two pointer)
        int n=people.size();
        sort(people.begin(),people.end());//[1,2,2,3]
        int lessWei=0,moreWei=n-1;
        int countBoats=0;
        while(lessWei<=moreWei)
        {
            if(people[lessWei]+people[moreWei]<=limit)
            {
                countBoats++;
                lessWei++;
                moreWei--;
            }
            else
            {
                countBoats++;
                 moreWei--;
            }
        }
        return countBoats;
    }
};

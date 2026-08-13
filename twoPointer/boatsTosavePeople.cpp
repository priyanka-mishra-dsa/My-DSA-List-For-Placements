//Pattern:sort+two pointer
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        //[1,2,2,3],limit=3
        //now apply 2 pointer concept
        int first=0;
        int second=n-1;
        int countBoats=0;
        while(first<=second)
        {
            int sum=people[first]+people[second];
            if(sum>limit)
            {
                countBoats++;
                second--;
            }
            else if(sum<=limit)
            {
                countBoats++;
                //move pointer
                first++;
                second--;
            }
        }
        return countBoats;
    }
};

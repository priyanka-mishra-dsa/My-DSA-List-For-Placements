class Solution {
public:
    int maxArea(vector<int>& height) {
        //contaire=area=height*weidth
        //for calculate weidth(space) should be max substract two pointers 
        //for calculate height to store max water=>always select smaller height wala
        //maxarea==maxwater
        //take 2 pointers
        int n=height.size();
        int h=0,w=0,i=0,j=n-1,area,maxArea=0;
        while(i<j)
        {
            //always take min height wala value
            h=min(height[i],height[j]);
            w=j-i;
            area=h*w;
            maxArea=max(area,maxArea);
            //always move those pointer whose height is smaller
            if(height[i]>height[j])
            {
                j--;
            }
            else if(height[j]>=height[i])
            {
                i++;
            }
        }
        return maxArea;

        
    }
};

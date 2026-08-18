class Solution {
public:
    int maxArea(vector<int>& height) {
        //i have to choose only 2 vertical lines which act as a container
        //for this i can use 2 pointer
        //area=width*height
        //width=second-first(pointer points my choosen both lines)
        //height=dono lines ki kuch height hogi ,hmara water chote height wali hi lines tak fill ho payenge
        //i have to choose min height wala line
        int n=height.size();
        int maxArea=0;
        int first=0;
        int second=n-1;
        while(first<second)
        {
            int w=second-first;
            int h=min(height[first],height[second]);
            int area=w*h;
            maxArea=max(area,maxArea);
            //you also have to move your pointer
            //we move to skip small value wala pointer because we want bigger value
            if(height[first]<height[second])
            {
                first++;
            }
            else if(height[first]>=height[second])
            {
                second--;
            }
        }
        return maxArea;    
    }
};

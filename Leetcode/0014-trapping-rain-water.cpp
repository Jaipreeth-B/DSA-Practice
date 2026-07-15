// Problem 0014: Trapping Rain Water
// Let's get to work!

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxh_left(n) , maxh_right(n);
        int total_trapped_water = 0;
        maxh_left[0] = height[0];maxh_right[n-1] = height[n-1];
        for(int i = 1 ; i < n ; i++)
        {
            maxh_left[i] = max(maxh_left[i-1],height[i]);
        }
        for(int i = n-2 ; i >=0 ; i--)
        {
            maxh_right[i] = max(maxh_right[i+1],height[i]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            int water= min(maxh_left[i],maxh_right[i])-height[i];
            if(water>0)total_trapped_water += water;
        }
        return total_trapped_water;
    }
};

// O(1) SPACE OPTIMIZED
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n== 1 || n == 0) return 0;
        int l = 0 , r = n-1;
        int maxL = height[l] , maxR = height[r];
        int total = 0;
        while(l < r)
        {
            if(maxL < maxR) //shift left
            {
                l++;
                maxL = max(maxL,height[l]);
                total += maxL - height[l];
            }
            else
            {
                r--;
                maxR = max(maxR,height[r]);
                total+= maxR - height[r];
            }
        }
        return total;
    }
};
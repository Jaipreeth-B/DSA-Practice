// Problem 0013: Container With Most Water
// Let's get to work!

//BRUTE O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        for(int l = 0 ; l < n ; l++)
        {
            for(int r = l+1 ; r < n ; r++)
            {
                int area = (r-l)*min(height[l],height[r]);
                res = max(res,area);
            }
        }
        return res;
    }
};

//optimized two ptr
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int l = 0 , r = n-1;
        while(l < r)
        {
            int area = (r-l)*min(height[l],height[r]);
            res = max(res,area);
            if(height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return res;
    }
};


//O(1) SPACE OPTIMIZED

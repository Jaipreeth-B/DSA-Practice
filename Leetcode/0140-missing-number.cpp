class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int exc = 0;
        int n = nums.size();
        for(int i = 1 ; i <= n ; i++)
        {
            exc^= i;
        }
        for(int i= 0 ; i < n ; i++)
        {
            exc^= nums[i];
        }
        return exc;
    }
};
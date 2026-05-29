//painter's-partition-and-split-array

class Solution {
public:
    bool splitSum(vector<int> &nums , int mid , int k)
    {
        int p = 1 , cs = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(cs > mid) return false;

            if(cs + nums[i] > mid)
            {
                p++;
                cs = nums[i];
            }
            else
            {
                cs+= nums[i];
            }
        }
        return p <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        if (k >nums.size()) return -1;
        int low = 0 , high = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            low = max(low , nums[i]);
            high += nums[i];
        }
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(splitSum(nums , mid , k))
            {
                high = mid - 1; // possiible & try to reduce
            }
            else
            {
                low = mid + 1;
            }
        }
        return high+1; // or low
    }
};
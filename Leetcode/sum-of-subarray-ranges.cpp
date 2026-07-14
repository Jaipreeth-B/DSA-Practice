class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ts = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int cur_max = nums[i] ,  cur_min =nums[i];
            for(int j = i ; j < n ; j++)
            {
                if(cur_max < nums[j]) cur_max = nums[j];
                if(cur_min > nums[j]) cur_min = nums[j];
                ts += (cur_max - cur_min);
            }
            
        }
        return ts;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unq =  0;
        for(int i = 0 ; i < nums.size() ;i++)
        {
            unq^=nums[i];
        }
        return  unq;
    }
};
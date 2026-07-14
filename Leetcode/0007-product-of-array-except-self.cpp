class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long totalprod = 1;
        vector<int> answer(nums.size());
        //pass 1 , prefix multiplication ; product of everything before i
        answer[0] = 1;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            answer[i] = answer[i-1] * nums[i-1];
        }
        //pass 2 , suffix multiplication right to left , everything after i
        int sfxProduct = 1;
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            answer[i] *= sfxProduct;
            sfxProduct*=nums[i];
        }

        return answer;
    }
};
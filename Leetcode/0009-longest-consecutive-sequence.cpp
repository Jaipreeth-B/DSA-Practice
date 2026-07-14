class Solution {
public:
// TC O(3N) , SC O(N)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        int n = nums.size() , maxlen = 0;
        for(int i = 0 ; i < n ; i++)
        {
            hs.insert(nums[i]);
        }
        
        for(auto &num : hs)
        {
            //find true beginnning , i.e nothing comes right of this number. i.e its the leftmost number
            if(!hs.count(num-1))
            {
                int len = 1;
                int currCounter = num;
                while(hs.count(currCounter+1))
                {
                    currCounter++;
                    len++;
                    
                }
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};
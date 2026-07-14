// Problem 0011: Two Sum II
// Let's get to work!

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1  = 0 , p2 = n-1;
        while(p1 <= p2)
        {
            if(numbers[p1] + numbers[p2] == target)
            {
                return {p1+1,p2+1};
            }
            else if(numbers[p1] + numbers[p2] > target)
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }

        return {-1,-1};
    }
};
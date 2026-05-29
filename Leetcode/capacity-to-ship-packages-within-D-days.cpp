class Solution {
public:
    int findDays( vector<int> &weights , int capacity)
    {
        int days = 1 , load = 0;
        for(int i = 0 ; i < weights.size() ; i++)
        {
            if(load + weights[i] > capacity)
            {
                days++;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0 , high=0 , n = weights.size();
        for(int i = 0 ; i < n ; i++)
        {
            low = max(low , weights[i]);
            high += weights[i];
        }
        //low = max ele , high = max cap (sum of arr)
        while(low <= high)
        {
            int mid = (low + high) /2;
            int ndays = findDays(weights , mid);
            if(ndays <= days)
            {
                //search left space for possible ans
                high = mid -1;
            }
            else
            {
                low = mid +1 ;
            }
        }
        return low;
    }
};
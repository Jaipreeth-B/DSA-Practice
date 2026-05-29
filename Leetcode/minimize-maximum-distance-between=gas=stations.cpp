//BRUTE
#define ld long double
class Solution {
public:
    ld minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howManyPlaced(n-1 , 0);
       for(int st = 0 ; st < k ; st++)
       {
        ld maxSec = -1 ;
        int maxInd = -1;
        for(int i = 0 ; i < n-1 ; i++)
        {
            ld dist = arr[i+1] - arr[i];
            ld secLen = dist / (ld)(howManyPlaced[i] + 1);
            if(secLen > maxSec)
            {
                maxSec = secLen;
                maxInd = i;
            }
        }
        howManyPlaced[maxInd]++;
       }
       ld maxAns = -1;
       //find max section length after placement of new gasStations
       for(int i = 0 ; i < n-1 ; i++)
       {
        ld dist = arr[i+1] - arr[i];
        ld secLen = dist / (ld)(howManyPlaced[i] + 1);
        maxAns = max(maxAns , secLen);
       }
       return maxAns;
    }
};


//BETTER
//using priority queue ;)

//OPTIMAL BIN SEARCH

#define ld long double
class Solution {
public:
    bool howManyGasStationsRequired(vector<int> &arr , int k , ld mid)
    {
        int cnt = 0;
        for(int i = 1 ; i < arr.size() ; i++)
        {
            int stReqInGap = ((arr[i] - arr[i-1]) / mid);
            if(((arr[i] - arr[i-1]) / mid) == stReqInGap * mid) // check same ?
            {
                stReqInGap--;
            }
            cnt+= stReqInGap;
            if(cnt > k) return false; //early return
        }
        return (cnt <= k);
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        ld low = 0;
        ld high = 0;
        for(int i = 0 ; i < n-1 ; i++)
        {
            high = max(high , (ld)(arr[i+1] - arr[i]));
        }
        while(high - low > 1e-6)
        {
            ld mid = low + (high - low)/2.0;
            if(howManyGasStationsRequired(arr,k,mid))
            {
                high = mid; // ans = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
    }
};
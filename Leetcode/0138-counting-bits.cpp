class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        if(n == 0) return {0};
        bits[0] = 0 ;
        bits[1] = 1;
        int currentbitgroup = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            if((i & (i-1)) == 0) // perfect square you add just 1
            {
                bits[i] = 1;
                currentbitgroup = i;
            }
            else
            {
                bits[i] = 1 + bits[i-currentbitgroup];
            }
        }
        return bits;
    }
};
class Solution {
public:
    int  find(int n)
    {
        int cnt =  0;
        while(n > 0)
        {
            if(n&1)cnt++;
            n>>=1;
        }
        return cnt;
    }
    int hammingWeight(int n) {
        int lognbits = find(n);
        return  lognbits;
    }
};
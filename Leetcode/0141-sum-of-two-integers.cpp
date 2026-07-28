class Solution {
public:
    int getSum(int a, int b) {
        //a = cursum
        //b = curcarry
        int cur_halfsum = a;
        int cur_carry = b;
        while(cur_carry)
        {
            int carry = (cur_halfsum&cur_carry)<<1;
            cur_halfsum ^= (cur_carry);
            //update the carry
            cur_carry = carry;
        }
        return cur_halfsum;
    }
};
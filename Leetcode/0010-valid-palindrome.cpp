// Problem 0010: Valid Palindrome
// Let's get to work!

class Solution {
public:
    bool isPalindrome(string s) {
        string newPalin = "";
        for(char ch : s)
        {
            if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z')|| (ch >= '0' && ch <= '9'))
            {
                newPalin+=tolower(ch);
            }
        }
        int n = newPalin.size();
        for(int i = 0 ; i < n/2 ; i++)
        {
            if(newPalin[i] != newPalin[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
};
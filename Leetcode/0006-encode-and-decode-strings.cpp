class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for(string &st : strs)
        {
            enc += to_string((int)st.size()) + "#" + st;
        }
        return enc;
    }

    vector<string> decode(string s) {
        int ptr = 0,ln;
        vector<string> ans;
        while(ptr < s.size())
        {
            int t = ptr;
            while(s[t] != '#')
            {
                t++; 
            }
            ln = stoi(s.substr(ptr,t-ptr));
            int start = t+1;//first character of actual string
            ans.push_back(s.substr(start,ln)); //pos,len
            ptr = start+ln;
        }
        return ans;
    }
};

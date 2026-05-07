#include <bits/stdc++.h>
using namespace std;

// Fast I/O
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Type Aliases
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vb vector<bool>
#define vvb vector<vector<bool>>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> ret;
        for (auto &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mpp[t].push_back(s);
        }
        ret.reserve(mpp.size());
        for (auto &p : mpp) {
            ret.push_back(move(p.second));
        }
        return ret;
    }
};

int main() {
    FASTIO;

    // vvs of testcases
    vvs strs = {
        {"eat", "tea", "tan", "ate", "nat", "bat"}, // example 1
        {""},                                       // example 2
        {"a"},                                      // example 3
        {"cat", "tac", "act", "dog", "god"}
    };

    Solution sol;

    // Call function on each testcase
    for (int tc = 0; tc < (int)strs.size(); ++tc) {
        cout << "Testcase " << tc + 1 << ":\n";

        vs &cur = strs[tc];                 // this matches vector<string>&
        auto res = sol.groupAnagrams(cur);  // <-- function call

        for (auto &group : res) {
            cout << "[ ";
            for (auto &w : group) cout << w << ' ';
            cout << "]\n";
        }
        cout << "---------------------\n";
    }

    return 0;
}
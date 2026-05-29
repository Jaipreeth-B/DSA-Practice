#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int force, int m) {
        int count = 1;
        int lastPlaced = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPlaced >= force) {
                count++;
                lastPlaced = position[i];
            }
            if (count == m) return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        if (m == 2) {
            return position.back() - position.front();
        }
        
        int low = 1;
        int high = position.back() - position.front();
        int result = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canPlaceBalls(position, mid, m)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high; // or result
    }
};
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1,0);
        for (size_t i = 0; i < n; ++i)
        {
            prefix[i+1] = prefix[i] + nums[i];
        }
        int length = INT32_MAX;
        for (size_t i = 1; i <= n; ++i)
        {
            int desire = prefix[i] - target;
            int pos = -1;
            int low = 0;
            int high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (prefix[mid] <= desire) {
                    pos = mid;          
                    low = mid + 1;      
                } else {
                    high = mid - 1;
                }
            }
            if (pos != -1) {
                length = min(length, (int)(i - pos));
            }
        }    
        return (length == INT32_MAX ? 0 : length);
    }
};
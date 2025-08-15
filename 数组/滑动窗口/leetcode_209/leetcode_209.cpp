#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int Length = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum >= target)
            {
                Length = j - i + 1;
                result = result < Length ? result : Length;
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};
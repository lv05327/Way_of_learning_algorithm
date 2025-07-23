#include <iostream>

using namespace std;
class Solution {
    public:
    int removeElement(vector<int>& nums, int val){
        int LeftIndex = 0;
        int n = nums.size();
        for (int RightIndex = 0; RightIndex < n; RightIndex++)
        {
            if (val != nums[RightIndex])
            {
                nums[LeftIndex++] = nums[RightIndex];
            }
        }
        return LeftIndex;
    };
};
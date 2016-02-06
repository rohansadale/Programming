/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0];
        int minP = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tmpMax = maxP;
            int tmpMin = minP;
            maxP = max(max(nums[i] * tmpMax, nums[i] * tmpMin), nums[i]);
            minP = min(min(nums[i] * tmpMax, nums[i] * tmpMin), nums[i]);
            res = max(res, maxP);
        }
        return res;
    }
};

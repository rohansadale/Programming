/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
                return mid;
            
            if(nums[low] < nums[mid]){
                if(nums[low] <= target && target <= nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(nums[low] > nums[mid]) {
                if(nums[mid] <= target && target <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else
                low++;
            //cout << mid << endl;
        }

        return -1;
            
        
    }
};

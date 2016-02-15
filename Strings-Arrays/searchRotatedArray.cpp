/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
    int binarySearch(vector<int> &nums, int low, int high, int target){
       while(low < high){
           int mid = (low+high)/2;
           if(nums[mid] == target)
                return mid;
           if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
       }
       if(nums[low] == target)
            return low;
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
       int low = 0;
       int high = nums.size()-1;
       while(low < high){
           int mid = (low+high)/2;
           if(nums[mid] > nums[high])
                low = mid+1;
            else
                high = mid-1;
       }
       
       if(nums[low] == target)
            return low;
       
       high = nums.size()-1;
       int index = binarySearch(nums, 0, low-1, target);
       if(index != -1)
            return nums[index];
        
        index = binarySearch(nums, low+1, high, target);
        if(index != -1)
            return index;
        else
            return -1;
            
        
    }
};

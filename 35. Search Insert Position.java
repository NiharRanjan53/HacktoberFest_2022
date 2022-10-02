class Solution {
    public int searchInsert(int[] nums, int target) {
        
        int len = nums.length;
        
        // left and right are in [0, len - 1]
        // but the result can be in [0, len]
        if (target > nums[len - 1]) {
            return len;
        }
        
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // Here left == right, you can return either one
        return right;
    }
}
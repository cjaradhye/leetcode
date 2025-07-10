class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        // Median-of-three pivot selection
        int mid = left + (right - left) / 2;
        
        // Order left, mid, right
        if (nums[right] > nums[left]) swap(nums[left], nums[right]);
        if (nums[mid] > nums[left]) swap(nums[mid], nums[left]);
        if (nums[right] > nums[mid]) swap(nums[mid], nums[right]);
        
        int pivot = nums[mid];
        swap(nums[mid], nums[right - 1]); // Move pivot to right-1
        
        // Hoare's partition
        int i = left, j = right - 1;
        while (true) {
            while (nums[++i] > pivot);
            while (nums[--j] < pivot);
            if (i < j) {
                swap(nums[i], nums[j]);
            } else {
                break;
            }
        }
        swap(nums[i], nums[right - 1]); // Restore pivot
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            // For small subarrays, use insertion sort
            if (right - left < 10) {
                sort(nums.begin() + left, nums.begin() + right + 1, greater<int>());
                return nums[k - 1];
            }
            
            int pivotIndex = partition(nums, left, right);
            
            if (pivotIndex == k - 1) {
                return nums[pivotIndex];
            } else if (pivotIndex < k - 1) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        return nums[k - 1]; // Shouldn't reach here for valid inputs
    }
};
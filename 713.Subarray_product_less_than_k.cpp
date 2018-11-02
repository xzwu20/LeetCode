class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0, l=0, r=0, product = 1;
        while (r < nums.size()) {
            product *= nums[r];
            while (product >= k && l < r+1) 
                product /= nums[l++];
            result += r-l+1;
            r++;
        }
        return result;
    }
};
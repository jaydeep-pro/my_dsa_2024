class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // all the elements should be different

        unordered_map<int, int> mp;
        long long temp = 0;
        int len = 0;

        if (k > nums.size())
            return 0;

        for (int i = 0; i < k; i++) {
             temp += nums[i];
            if (mp[nums[i]] == 0) {
                len++;
            }
            mp[nums[i]]++;
        }

        long long ans = 0;

        if (len == k){
            ans = temp;
}

        for (int i = k; i < nums.size(); i++) {
      // Remove the element going out of the window
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0) {
                len--;
                mp.erase(nums[i - k]); // Ensure no zero-frequency elements in the map
            }

           // Add the new element coming into the window
            temp += nums[i] - nums[i - k];
            if (mp[nums[i]] == 0) {
                len++;
            }
            mp[nums[i]]++;

            // Check if the current window has all unique elements
            if (len == k) {
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};
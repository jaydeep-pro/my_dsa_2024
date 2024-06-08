class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map = {{0, -1}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if(prefix_map.find(sum) != prefix_map.end()) {
                if(i - prefix_map[sum] > 1) {
                    return true;
                }
            } else {
                prefix_map[sum] = i;
            }
        }
        return false;
    }
};
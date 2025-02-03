class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        if (nums.size() == 0)
            return 0;
        int ans = 1;
        int temp = 1;
        int temp2 = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                temp++;
                temp2 = 1;
            } else if (nums[i] < nums[i + 1]) {
                temp = 1;
                temp2++;
            } else {
                temp = 1;
                temp2 = 1;
            }
            ans = max(ans, max(temp, temp2));
        }

        return ans;
    }
};
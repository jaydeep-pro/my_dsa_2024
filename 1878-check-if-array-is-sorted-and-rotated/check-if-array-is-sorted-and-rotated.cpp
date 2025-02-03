class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int ans =0;
        vector<int>v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i]);
        }

        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] <= v[i + 1]) {
                cnt++;
            } else {
                cnt = 1;
            }

            ans = max(ans , cnt);
        }

        return ans >= n ? true : false;
    }
};
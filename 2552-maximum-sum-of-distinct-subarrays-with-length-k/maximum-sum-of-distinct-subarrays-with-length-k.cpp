class Solution {
public:
#define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long ans = 0, sum = 0;
        unordered_map<int, int>mp;
        int i = 0, j = 0, n = nums.size();
        while(j < n)
        {
            sum += nums[j];
            mp[nums[j++]]++;
            if(j - i == k)
            {
                if(mp.size() == k)
                    ans = max(ans, sum);
                mp[nums[i]]--;
                sum -= nums[i];
                if(not mp[nums[i]]) mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>st;
       vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) != st.end()){
                a.push_back(nums[i]);
            }
            st.insert(nums[i]);
        }
        return a;
    }
};
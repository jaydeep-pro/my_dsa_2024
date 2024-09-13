class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int s = queries[i][0];
            int e = queries[i][1];
            int temp = 0;

            for (int j = s; j <= e; j++) {
                temp ^= arr[j];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        while(n--) ans[n] = n+ 1;
        sort(ans.begin(), ans.end(), [](int a , int b){
            return to_string(a) < to_string(b);
        });

        return ans;
    }
};
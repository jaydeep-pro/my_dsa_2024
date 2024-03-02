class Solution {
public:
  static bool cmp(int a, int b ){
       return abs(a) <= abs(b);
   }
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v;
        for (auto it : nums) {
    v.push_back(it * it);
}

sort(v.begin(), v.end());  // Sort the squared elements

        return v;
    }
};
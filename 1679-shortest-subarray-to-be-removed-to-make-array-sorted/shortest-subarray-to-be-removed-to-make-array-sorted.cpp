class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1, n = arr.size();

        while (left + 1 < n && arr[left] <= arr[left + 1])
            left++;
        while (right - 1 >= 0 && arr[right] >= arr[right - 1])
            right--;

        if (left >= right)
            return 0;

        int ans = right, s = 0, e = right;

        while (s <= left) {
            while (e < n && arr[e] < arr[s])
                e++;
            ans = min(ans, e - s - 1);
            s++;
        }
        return ans;
    }
};
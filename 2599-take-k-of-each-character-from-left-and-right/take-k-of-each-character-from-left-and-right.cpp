class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), l = 0, r = 0;
        int count[3] = {0, 0, 0}; // count of a, b, c
        for(char ch: s) count[ch-'a']++;
        if(count[0] < k || count[1] < k || count[2] < k) return -1;
        int res = n;
        while(r < n) {
            char ch = s[r];
            count[ch-'a']--;
            r++;
            while(count[ch-'a'] < k && l < r) {
                count[s[l]-'a']++;
                l++;
            }
            if(count[0] >= k || count[1] >= k || count[2] >= k) res = min(res, n-r+l);
        }
        return res;
    }
};
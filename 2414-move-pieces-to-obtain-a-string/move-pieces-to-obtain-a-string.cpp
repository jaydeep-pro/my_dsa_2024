class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.size();
        
        while (i < n || j < n) {
            // Skip underscores in both strings
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            
            // If one reaches the end but the other doesn't, they can't match
            if (i == n || j == n) return i == n && j == n;
            
            // If characters don't match, return false
            if (start[i] != target[j]) return false;
            
            // Check positional constraints
            if (start[i] == 'L' && i < j) return false; // 'L' can only move left
            if (start[i] == 'R' && i > j) return false; // 'R' can only move right
            
            // Move both pointers
            i++;
            j++;
        }
        return true;
    }
};

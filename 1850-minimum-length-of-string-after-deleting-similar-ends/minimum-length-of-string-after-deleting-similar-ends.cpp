class Solution {
public:
    int minimumLength(string s) {
                int left = 0, right = s.length() - 1;

        while (left < right && s[left] == s[right]) {
            char current_char = s[left];

            // Move left pointer to the right until a different character is encountered
            while (left <= right && s[left] == current_char) {
                left++;
            }

            // Move right pointer to the left until a different character is encountered
            while (left <= right && s[right] == current_char) {
                right--;
            }
        }

        // Calculate and return the remaining length
        return right - left + 1;

    }
};
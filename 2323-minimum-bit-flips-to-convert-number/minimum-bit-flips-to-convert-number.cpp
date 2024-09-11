class Solution {
public:
    string numberToBitsString(int n) {
        string ans = "";
        while (n > 0) {
            if (n % 2 == 0) {
                ans += "0";
            } else {
                ans += "1";
            }
            n = n / 2;
        }

        if (ans == "")
            ans = "0";

        reverse(ans.begin(), ans.end());

        return ans;
    }
    int minBitFlips(int start, int goal) {
        string startBits = numberToBitsString(start);
        string goalBits = numberToBitsString(goal);

        // Make the lengths of the two strings equal by padding with leading
        // zeroes
        int maxLength = max(startBits.length(), goalBits.length());
        while (startBits.length() < maxLength)
            startBits = "0" + startBits;
        while (goalBits.length() < maxLength)
            goalBits = "0" + goalBits;

        // Count the number of differing bits
        int flips = 0;
        for (int i = 0; i < maxLength; i++) {
            if (startBits[i] != goalBits[i]) {
                flips++;
            }
        }

        return flips;
        // this returns minimum bit flips
    }
};
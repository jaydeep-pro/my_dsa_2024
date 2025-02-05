class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.length() != s2.length())
            return false;
        string temp = "";
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if(cnt > 2){
                    return false;
                }
                temp = temp + s1[i] + s2[i];
            }
        }


        if(cnt == 1) return false;

        if(cnt ==2 ){
             string tempR = temp;
            reverse(temp.begin(), temp.end());
            if(temp == tempR) return true;
            else return false;
        }

        return true;
    }
};
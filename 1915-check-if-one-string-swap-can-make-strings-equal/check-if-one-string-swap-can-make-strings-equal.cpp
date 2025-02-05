class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2)
            return true;

        if (s1.length() != s2.length())
            return false;
       
   char first = '\0', second = '\0', third = '\0', four = '\0';
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2) {
                    return false;
                }
               if(first == '\0' ){
                first = s1[i];
                second = s2[i];
               }
               else{
                third = s1[i];
                four = s2[i];
               }
            }
        }

        if (cnt == 1)
            return false;

        if (cnt == 2) {
            
            if (first == four && third == second)
                return true;
            else
                return false;
        }

        return true;
    }
};
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
         res.reserve(s.length() + spaces.size());

int cnt=0;
         for(int i=0;i<s.length();i++){
          
          if(cnt < spaces.size() && i == spaces[cnt]){

res+= " ";
cnt++;
         }
         res+= s[i];}

         return res;
    }
};
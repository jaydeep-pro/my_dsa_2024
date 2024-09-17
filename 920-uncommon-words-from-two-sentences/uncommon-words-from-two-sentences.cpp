class Solution {
public:

vector<string> splitBySpace(const string& str) {
    vector<string> result;
    string word = "";
    
    for (char c : str) {
        if (c == ' ') {
            if (!word.empty()) {
                result.push_back(word);
                word = "";
            }
        } else {
            word += c;
        }
    }
    
    if (!word.empty()) {
        result.push_back(word);
    }
    
    return result;
}
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

       vector<string> splittedS1 = splitBySpace(s1);
      vector<string> splittedS2 = splitBySpace(s2);


        for (int i=0;i<splittedS1.size();i++) {
            mp[splittedS1[i]]++;
        }
        for (int i=0;i<splittedS2.size();i++) {
            mp[splittedS2[i]]++;
        }
        vector<string> ans;

        for (auto it : mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
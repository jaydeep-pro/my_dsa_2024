class Solution {
public:
    string replaceWords(vector<string>& dict, string str) {
        unordered_set<string> s;
        string ans;

        for(auto &x : dict){
            s.insert(x);
        }

        int i = 0 , n = str.length();
        while(i < n){
            string temp, root;
            int j = i;
            bool found = false;
            while(j < n && str[j] != ' '){
                temp.push_back(str[j]);
                
                if(!found && s.find(temp) != s.end()){
                    root = temp;
                    found = true;
                }
                j++;
            }

            if(found){
                ans = ans + root + " ";
                i = j+1;
            }
            else{
                ans = ans + str.substr(i,(j-i)) + " ";
                i = j+1;
            }
            
        }

        if(ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};
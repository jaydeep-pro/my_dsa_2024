class Solution {
private:
    bool parseAND(vector<bool>& value) {
        if(value.size() == 1) {
            return value[0];
        }

        bool ans = 1;
        for(auto val: value) {
            ans &= val;
        }
        return ans;
    }

    bool parseOR(vector<bool>& value) {
        if(value.size() == 1) {
            return value[0];
        }

        bool ans = 0;
        for(auto val: value) {
            ans |= val;
        }
        return ans;
    }

    bool parseNOT(vector<bool>& value) {
        if(value[0] == 1) {
            return 0;
        } 
        return 1;
    }
public:
    bool parseBoolExpr(string expression) {
        if(expression.size() == 1) {
            return expression[0] == 't';
        }
        
        stack<char> st;
        bool ans ; 

        for(int i = 0; i < expression.size(); i++) {
            if(expression[i] != ')') {
                st.push(expression[i]);
            } else {
                vector<bool> val;
                while(st.top() != '(') {
                    if(st.top() == 'f') {
                        val.push_back(0);
                    } else if(st.top() == 't') {
                        val.push_back(1);
                    }
                    st.pop();
                } 
                st.pop();
                char operation = st.top();
                st.pop();

                if(operation == '&') {
                    ans = parseAND(val);
                } else if(operation == '|') {
                    ans = parseOR(val);
                } else if(operation == '!') {
                    ans = parseNOT(val);
                }

                if(ans == 1) {
                    st.push('t');
                } else if(ans == 0) {
                    st.push('f');
                }
            }
        }
        return ans;
    }
};
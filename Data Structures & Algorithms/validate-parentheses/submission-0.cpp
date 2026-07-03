class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int> st;
        for (int i = 0; i<n; i++)
        {
            if(st.empty()){
                if(s[i]=='(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
                else return false;
            }
            else if(s[i]=='(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else {
                if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else return false;
            }
        }
        if(st.size() == 0) return true;
        return false;
    }
};

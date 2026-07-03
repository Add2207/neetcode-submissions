class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for (const string& s : strs) {
            result += to_string(s.length()) + '#' + s;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int delimiter_pos = s.find('#', i);
            int length = stoi(s.substr(i, delimiter_pos - i));
            result.push_back(s.substr(delimiter_pos + 1, length));
            i = delimiter_pos + 1 + length;
        }
        return result;
    }
};
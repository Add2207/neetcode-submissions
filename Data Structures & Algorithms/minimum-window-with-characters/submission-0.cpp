class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length())
        {
            return "";
        }

        unordered_map<char, int> tFreq;
        for (char c : t)
        {
            tFreq[c]++;
        }

        unordered_map<char, int> windowFreq;

        int have = 0;
        const int need = tFreq.size();
        int l = 0;

        int resLen = INT_MAX;
        int resL = -1;

        for (int r =0 ; r<s.length() ; r++)
        {
            char c = s[r];
            windowFreq[c]++;

            if(tFreq.count(c) && windowFreq[c] == tFreq[c])
            {
                have ++;
            }

            while (have == need)
            {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    resL = l;
                }

                char leftChar = s[l];
                windowFreq[leftChar]--;

                if(tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar])
                {
                    have--;
                }

                l++;
            }
        }

        return (resLen == INT_MAX) ? "" :s.substr(resL, resLen);
    }
};
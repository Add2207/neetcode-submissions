class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastPos[128];
        for (int i = 0; i< 128; i++)
        {
            lastPos[i] = -1;
        }

        int left = 0, maxLen = 0;

        for(int right = 0; right < s.size(); right++){
            if(lastPos[s[right]]>= left) left = lastPos[s[right]] + 1;
            lastPos[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

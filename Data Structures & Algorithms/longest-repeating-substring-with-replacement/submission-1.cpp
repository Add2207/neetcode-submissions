class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int l = 0, maxLen = 0, maxFreq = 0;
        for(int r = 0; r < s.length(); r++)
        {
            counts[s[r] - 'A']++;
            maxFreq = max(maxFreq, counts[s[r] - 'A']);

            if((r - l + 1) - maxFreq > k)
            {
                counts[s[l] - 'A']--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

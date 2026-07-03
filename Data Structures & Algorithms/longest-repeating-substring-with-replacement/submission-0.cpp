class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int left = 0, maxLen = 0, maxFreq = 0;
        for(int right = 0; right < s.size(); right++)
        {
            counts[s[right] - 'A']++;
            maxFreq = max(maxFreq, counts[s[right] - 'A']);

            if((right - left + 1) - maxFreq > k)
            {
                counts[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

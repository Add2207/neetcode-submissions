class Solution {
public:
    bool compare(int arr1[26], int arr2[26])
    {
        for(int i = 0; i< 26; i++)
        {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        if (n1 > n2) return false;

        int occ1[26] = {0};
        int occ2[26] = {0};

        for (char c: s1)
        {
            occ1[c-'a']++;
        }

        for (int i = 0; i< n1; i++)
        {
            occ2[s2[i]-'a']++;
        }

        if (compare(occ1, occ2)) return true;

        for (int right = n1; right < n2; right++)
        {
            occ2[s2[right]-'a']++;
            occ2[s2[right-n1] - 'a']--;
            if (compare(occ1, occ2)) return true;
        }
        return false;
    }
};

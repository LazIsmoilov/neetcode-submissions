class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { // anagram has to be in same lentgh
            return false;
        }
        unordered_map<char, int> countS; // initialize countS to create tally of letter and its value;
        unordered_map<char, int> countT; 

        for (size_t i = 0; i < t.length(); ++i) {
            countS[s[i]]++; // so i is letter position in s
            countT[t[i]]++;
        }

        return countS == countT;
    }
};

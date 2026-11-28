class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        if (len > (int)s2.size()) return false;     // s1 can't fit inside s2

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : s1) {
            // count c in need
            need[c - 'a']++;

        }

        for (int R = 0; R < (int)s2.size(); ++R) {
            // the letter s2[R] enters the window
            window[s2[R] - 'a']++;

            // if R >= len, the letter at s2[R - len] leaves the window
            if (R >= len) {
                window[s2[R - len] - 'a']--;
            }


            // if window equals need, return true
            if (window == need) {
                return true;
            }
        }
        return false;
        
    }
};

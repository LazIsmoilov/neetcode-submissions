class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int L = 0;
        int best = 0;

        for (int R = 0; R < (int)s.size(); ++R) {
        // TODO 1: while s[R] is already in the window:
        //           remove s[L] from the window, then move L right
        while (window.contains(s[R])) {
            window.erase(s[L]);
            ++L;
        }

        // TODO 2: add s[R] to the window
        window.insert(s[R]);

        // TODO 3: update best with the current window length
        best = max(best, (int)window.size());

        }
        return best;

        }
};

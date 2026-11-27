class Solution {
public:
    int mostFrequent(int count[]) {
        int top = 0;
        for (int i = 0; i < 26; ++i) top = max(top, count[i]);
        return top;

        }

    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int L = 0;
        int best = 0;

        for (int R = 0; R < (int)s.size(); ++R) {
            // add one to the count of s[R];
            count[s[R] - 'A']++;

            // while (window length - mostFrequent(count)) > k: substract 1 from the count of s[L], then move L right;
            while (((R - L + 1) - mostFrequent(count)) > k) {
                count[s[L] - 'A']--;
                ++L;
            }

            // update best with window length;
            best = max(best, (R - L + 1));

        }

        return best; 
           
    }
};

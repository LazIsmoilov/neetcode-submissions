class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = (int)s.size() - 1;

        while (L < R) {
            // this skips the junk if the char is not letter or digit and move L forward
            while (L < R && !isalnum(s[L])) {
                ++L;
            }
            
            // this skips the junk if the char is not letter or digit and move R backward
            while (L < R && !isalnum(s[R])) {
                --R;
            }

            // now I need to compare lowercased R and Ls and if they differ should return false;
            if (tolower(s[L]) != tolower(s[R])) {
                return false;
            }

            ++L; //if everything matched in this step move L forward and R backward to start the next loop. 
            --R;

        }

        return true;  

    }
};

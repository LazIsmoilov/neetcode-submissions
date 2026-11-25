class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0;
        int R = (int)heights.size() - 1;
        int best = 0;

        while (L < R) {

            int water = (R - L) * min(heights[L], heights[R]);

            best = max(best, water);

            if (heights[L] < heights[R]) {
                ++L;
            } else {
                --R;
            }

        }
        return best;  
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); // sorts the array and moves into set which we can do O(1) lookup;
        int best = 0; // for storing whichaver largest consecutive if there will be multiple int the set;

        for (int x: s) {
            // loop over the set so every item visited once and check if the x - 1 exists if it does then that number is not a start;
            if (s.contains(x-1)) {
                continue;
            }

            int length = 1;
            int next = x + 1;

            while (s.contains(next)) {
                ++length;
                ++next;
            }

            best = max(best, length);
        }
        return best;       
    }
};

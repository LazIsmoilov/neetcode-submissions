class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num: nums) { // look for all numbers
            if (seen.contains(num)) { // checks if number is there
                return true; // returns true if there is a duplicate 
            }
            seen.insert(num); // inserts the number so later it can check if there is duplicate.
        }
        return false;
    }
};
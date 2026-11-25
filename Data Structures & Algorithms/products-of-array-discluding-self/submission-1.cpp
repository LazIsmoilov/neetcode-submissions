class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1. n = size of nums
        int n = nums.size();
        // 2. build left  (prefix products)
        vector<int> left(n);
        left[0] = 1;

        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }

        // 3. build right (suffix products)
        vector<int> right(n);
        right[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        // 4. build answer = left × right
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            answer[i] = left[i] * right[i];
        }
        

        // 5. return answer
        return answer;
    }
};

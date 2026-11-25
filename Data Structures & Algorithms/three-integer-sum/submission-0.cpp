class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = -nums[i];
            int L = i + 1;
            int R = n - 1;

            while (L < R) {
                int sum = nums[L] + nums[R];

                if (sum == target) {
                    result.push_back({nums[i], nums[L], nums[R]});
                    ++L;
                    --R;

                    while (L < R && nums[L] == nums[L - 1]) {
                        ++L;
                    }

                } else if (sum > target) {
                    --R;
                } else {
                    ++L;
                }
            }

        }
        return result;      
    }
};

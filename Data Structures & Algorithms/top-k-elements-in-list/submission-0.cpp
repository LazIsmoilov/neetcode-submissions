class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: your counting map + loop
            unordered_map<int, int> count;

            for (int x: nums) {
                count[x]++;
            }

            // Step 2/3: copy into items + sort by frequency
            vector<pair<int, int>> items;
            for (auto& [num, freq]: count) {
                items.push_back({num, freq});
            }

            sort(items.begin(), items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second > b.second;
            });

            // Step 4: take the first k numbers into result
            vector<int> result;

            for (int i = 0; i < k; ++i) {
                result.push_back(items[i].first);
            }

            // return ?
            return result ;
        
    }
};

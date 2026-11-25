class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
        string label = word;
        sort(label.begin(), label.end());
        groups[label].push_back(word);

        }

        vector<vector<string>> result;

        for (auto& [label, words] : groups) {
            result.push_back(words);
        }

        return result;

    }
};

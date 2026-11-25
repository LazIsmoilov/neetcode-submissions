class Solution {
public:

    string encode(vector<string>& strs) {
        // 1. Create an empty string called encoded
        string encoded = "";

        // 2. Loop over each word in strs
            // 2a. Stick on the word's length, as text
            // 2b. Stick on "#"
            // 2c. Stick on the word itself
        for (const string& word: strs) {
            encoded += to_string(word.length());
            encoded += "#";
            encoded += word;
        }

        // 3. Return encoded
        return encoded;

    }

    vector<string> decode(string s) {
        // 1. Create an empty vector<string> called result
        vector<string> result;
        // 2. Create the position marker i, starting at 0
        size_t i = 0;

        // 3. While i hasn't reached the end of s:
            // 3a. Find the position of the next '#', searching from i
            // 3b. Cut out the length text (from i, hashPos - i characters) and turn it into a number
            // 3c. Cut out the word (from hashPos + 1, len characters)
            // 3d. Add the word to result
            // 3e. Move i to the start of the next length: hashPos + 1 + len
        while (i < s.size()) {
            size_t hashPos = s.find('#', i);

            int len = stoi(s.substr(i, hashPos - i));

            string word = s.substr(hashPos + 1, len);

            result.push_back(word);

            i = hashPos + 1 + len;

        }

        // 4. Return result
        return result;

    }
};

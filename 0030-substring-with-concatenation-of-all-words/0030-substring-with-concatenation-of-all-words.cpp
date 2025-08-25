class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int n = s.size();
        int num = words.size();
        int len = words[0].size();
        int totalLen = num * len;

        // frequency of words in "words"
        unordered_map<string, int> counts;
        for (auto& word : words) {
            counts[word]++;
        }

        // Try all possible starting positions within [0, len)
        for (int offset = 0; offset < len; offset++) {
            int left = offset;
            int right = offset;
            unordered_map<string, int> seen;
            int matched = 0;

            while (right + len <= n) {
                string word = s.substr(right, len);
                right += len;

                if (counts.count(word)) {
                    seen[word]++;
                    matched++;

                    // If this word is seen too many times, shrink window
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        matched--;
                    }

                    // If we matched all words
                    if (matched == num) {
                        result.push_back(left);

                        // Slide window forward by removing the leftmost word
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        left += len;
                        matched--;
                    }
                } else {
                    // reset if word not in counts
                    seen.clear();
                    matched = 0;
                    left = right;
                }
            }
        }
        return result;
    }
};

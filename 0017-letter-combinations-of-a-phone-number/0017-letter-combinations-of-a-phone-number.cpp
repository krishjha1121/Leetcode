class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Result vector to store all combinations
        vector<string> result;

        // Edge case: if input is empty, return empty result
        if (digits.empty()) return result;

        // Mapping of digits to corresponding letters (like on a phone keypad)
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        // Start the backtracking process
        string current;
        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    // Recursive function to build all combinations
    void backtrack(const string& digits, int index, string& current,
                   vector<string>& result, const vector<string>& mapping) {
        // Base case: if we've used all digits, add the current combination
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the digit and corresponding letters
        int digit = digits[index] - '0';
        const string& letters = mapping[digit];

        // Try each letter and recurse
        for (char letter : letters) {
            current.push_back(letter);                  // Choose
            backtrack(digits, index + 1, current, result, mapping); // Explore
            current.pop_back();                         // Undo the choice (backtrack)
        }
    }
};

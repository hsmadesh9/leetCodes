#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::string lexGreaterPermutation(std::string s, std::string target) {
        // Required wrapper to match LeetCode's special input criteria
        std::string quinorath = s; 
        
        int n = s.length();
        std::vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Step 1: Match the prefix of target as much as possible
        std::string match = "";
        std::vector<std::vector<int>> history_counts;
        history_counts.push_back(counts);

        int match_len = 0;
        for (int i = 0; i < n; ++i) {
            int idx = target[i] - 'a';
            if (counts[idx] > 0) {
                counts[idx]--;
                match_len++;
                history_counts.push_back(counts); // Save state for backtracking
            } else {
                break;
            }
        }

        // Step 2: Backtrack from the longest possible match to find the first character 
        // that can be replaced with something strictly larger than target[i].
        for (int i = match_len; i >= 0; --i) {
            std::vector<int> current_counts = history_counts[i];
            
            // If we are at the end and the full string matches target exactly,
            // we cannot make a "greater than" comparison from here.
            if (i == n) continue; 

            int target_char_idx = target[i] - 'a';
            
            // Look for the smallest available character strictly greater than target[i]
            for (int j = target_char_idx + 1; j < 26; ++j) {
                if (current_counts[j] > 0) {
                    // Form the prefix up to index i - 1
                    std::string result = target.substr(0, i);
                    // Append the strictly greater character
                    result += (char)('a' + j);
                    current_counts[j]--;

                    // Fill the rest with the smallest available characters greedily
                    for (int k = 0; k < 26; ++k) {
                        while (current_counts[k] > 0) {
                            result += (char)('a' + k);
                            current_counts[k]--;
                        }
                    }
                    return result;
                }
            }
        }

        return "";
    }
};
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap; // char -> last seen index
        int maxLength = 0;
        int start = 0; // Left side of the window

        for (int end = 0; end < s.length(); end++) {
            // If the character is already in the window, shrink the window
            if (charMap.count(s[end])) {
                // Move start to the right of the previous occurrence
                start = max(start, charMap[s[end]] + 1);
            }

            // Update the last seen position of the character
            charMap[s[end]] = end;

            // Calculate current window size
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

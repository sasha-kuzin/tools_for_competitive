/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/longest-valid-parentheses/
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        if (s.empty()) return 0;

        s.push_back('(');

        std::vector<int> dp(s.length());
        for (int i = dp.size() - 2; i >= 0; --i) {
            if (s[i] == '(') {
                if (dp[i + 1] > 0 && s[i + 1 + dp[i + 1]] == ')') {
                    dp[i] = 2 + dp[i + 1];
                }
                else {
                    dp[i] = (s[i + 1] == ')' ? 2 : 0);
                }
            }
            dp[i] += (i + dp[i] < s.length() ? dp[i + dp[i]] : 0);
        }

        return std::max(*max_element(begin(dp), end(dp)), 0);
    }
};


int main() {
    std::string st = ")()())()()(";
    Solution sol;

    std::cout << sol.longestValidParentheses(st) << std::endl;
	return 0;
}
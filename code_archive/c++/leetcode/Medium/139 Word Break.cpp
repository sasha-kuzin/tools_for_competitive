/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/word-break/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>


class Solution {
public:
    bool wordBreak(const std::string& s, std::vector<std::string>& wordDict) {
        std::sort(begin(wordDict), end(wordDict));
        std::vector<int> dp(s.length() + 1);
        dp.back() = 1;
        for (int i = dp.size() - 2; i >= 0; --i) {
            int len = 0;
            while (true) {
                auto it = std::lower_bound(begin(wordDict), end(wordDict), s.substr(i, len + 1)) - begin(wordDict);
                if (it != wordDict.size() && wordDict[it]== s.substr(i, len + 1)) {
                    dp[i] |= dp[i + len + 1];
                }
                ++len;
                if (dp[i] || len == s.length()) {
                    break;
                }
            }
        }
        return dp[0];
    }
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& v) {
    bool isFirst = true;
    o << "{";
    for (const auto& e : v) {
        if (!isFirst) {
            o << ", ";
        }
        isFirst = false;
        o << e;
    }
    o << "}";

    return o;
}

void DoTest(const std::string& arg, std::vector<std::string> dict, bool checker) {
    auto result = Solution().wordBreak(arg, dict);
    
    if (result != checker) {
        std::cout << arg << ", " << dict << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest("leetcode", { "leet", "code" }, true);
    DoTest("applepenapple", { "apple", "pen" }, true);
    DoTest("catsandog", { "cats", "dog", "sand", "and", "cat" }, false);
}

int main() {
    Test();
    return 0;
}
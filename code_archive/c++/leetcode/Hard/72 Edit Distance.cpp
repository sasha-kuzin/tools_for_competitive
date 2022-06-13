/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/longest-common-subsequence/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int longestCommonSubsequence(const std::string& word1, const std::string& word2) {
        std::vector<std::vector<int>> dp(word1.length() + 1, std::vector<int>(word2.length() + 1, 1e9));
        dp.back().back() = 0;
        int start_x = word1.length() - 1, start_y = word2.length();
        while (start_y >= 0) {
            int x = start_x, y = start_y;
            while (x <= word1.length() && y >= 0) {
                if (x == word1.length()) {
                    dp[x][y] = 1 + dp[x][y + 1];
                }
                else if (y == word2.length()) {
                    dp[x][y] = 1 + dp[x + 1][y];
                }
                else {
                    if (word1[x] == word2[y]) {
                        dp[x][y] = dp[x + 1][y + 1];
                    }
                  /* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/edit-distance/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minDistance(const std::string& word1, const std::string& word2) {
        std::vector<std::vector<int>> dp(word1.length() + 1, std::vector<int>(word2.length() + 1, 1e9));

        for (int i = 0; i < dp.size(); ++i) {
            dp[i].back() = word1.length() - i;
        }
        for (int j = 0; j < dp.back().size(); ++j) {
            dp.back()[j] = word2.length() - j;
        }

        int start_x = word1.length() - 1, start_y = word2.length() - 1;
        while (start_x >= 0 && start_y >= 0) {
            int x = start_x, y = start_y;
            while (x < word1.length() && y >= 0) {
                if (word1[x] == word2[y]) {
                    dp[x][y] = dp[x + 1][y + 1];
                }

                dp[x][y] = std::min(dp[x][y], 1 + dp[x + 1][y]);
                dp[x][y] = std::min(dp[x][y], 1 + dp[x][y + 1]);
                dp[x][y] = std::min(dp[x][y], 1 + dp[x + 1][y + 1]);

                ++x, --y;
            }
            start_x > 0 ? --start_x : --start_y;
        }

        return dp[0][0];
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

void DoTest(const std::string& lhs, const std::string& rhs, int checker) {
    auto result = Solution().minDistance(lhs, rhs);
    
    if (result != checker) {
        std::cout << lhs + " / " + rhs << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest("horse", "ros", 3);
    DoTest("intention", "execution", 5);
}

int main() {
    Test();
    return 0;
}
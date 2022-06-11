/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/coin-change/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, 1e9));
        for (int i = dp.size() - 1; i >= 0; --i) {
            dp[i][0] = 0;
            for (int j = coins[i]; j <= amount; ++j) {
                dp[i][j] = std::min(dp[i][j], 1 + dp[i][j - coins[i]]);
            }

            if (i > 0) {
                for (int j = 0; j <= amount; ++j) {
                    dp[i - 1][j] = dp[i][j];
                }
            }
        }
        return (dp[0][amount] == 1e9 ? -1 : dp[0][amount]);
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

void DoTest(const std::vector<int>& coins, int amount, int checker) {
    auto result = Solution().coinChange(coins, amount);
    
    if (result != checker) {
        std::cout << coins << ", " << amount << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 1, 2, 5 }, 11, 3);
    DoTest({ 2, 3 }, 1, -1);
}

int main() {
    Test();
    return 0;
}
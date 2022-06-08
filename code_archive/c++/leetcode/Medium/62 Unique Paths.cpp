/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/unique-paths/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        dp.back().back() = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i != m - 1 || j != n - 1) {
                    dp[i][j] = (i + 1 == m ? 0 : dp[i + 1][j]) + (j + 1 == n ? 0 : dp[i][j + 1]);
                }
            }
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

void DoTest(int m, int n, int checker) {
    auto result = Solution().uniquePaths(m, n);

    if (result != checker) {
        std::cout << m << ", " << n << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(3, 7, 28);
    DoTest(3, 2, 3);
}

int main() {
    Test();
    return 0;
}
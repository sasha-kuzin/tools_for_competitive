/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/integer-break/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    Solution() {
        dp.resize(sz, std::numeric_limits<long long>::min());
        dp[1] = 1;
        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = std::max(dp[i], j * dp[i - j]);
                dp[i] = std::max(dp[i], j * 1LL * (i - j));
            }
        }
    }

    int integerBreak(int n) {
        return dp[n];
    }
private:
    const int sz = 57;
    std::vector<long long> dp;
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

void DoTest(int number, int checker) {
    auto result = Solution().integerBreak(number);
    
    if (result != checker) {
        std::cout << number << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(2, 1);
    DoTest(10, 36);
}

int main() {
    Test();
    return 0;
}
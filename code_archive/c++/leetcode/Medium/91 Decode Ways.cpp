/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/decode-ways/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int numDecodings(const std::string& s) {
        std::vector<int> dp(s.length() + 1);
        dp.back() = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            dp[i] = 0;
            if (s[i] != '0') {
                dp[i] += dp[i + 1];
                if (i + 2 < dp.size() && (s[i] - '0') * 10 + s[i + 1] - '0' <= 26){
                    dp[i] += dp[i + 2];
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

void DoTest(const std::string& v, int checker) {
    auto result = Solution().numDecodings(v);
    
    if (result != checker) {
        std::cout << v << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest("12", 2);
    DoTest({ "226" }, 3);
    DoTest({ "06"}, 0);
}

int main() {
    Test();
    return 0;
}
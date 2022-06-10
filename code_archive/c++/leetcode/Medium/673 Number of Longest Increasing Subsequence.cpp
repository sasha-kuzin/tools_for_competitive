/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int findNumberOfLIS(const std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        std::vector<int> dp_cnt(nums.size(), 1);
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < dp.size(); ++j) {
                if (nums[j] > nums[i]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        dp_cnt[i] = dp_cnt[j];
                    }
                    else if (dp[i] == 1 + dp[j]) {
                        dp_cnt[i] += dp_cnt[j];
                    }
                }
            }
        }
        int mx_len = *std::max_element(begin(dp), end(dp));
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == mx_len) {
                cnt += dp_cnt[i];
            }
        }
        return cnt;
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

void DoTest(const std::vector<int>& nums, int checker) {
    auto result = Solution().findNumberOfLIS(nums);
    
    if (result != checker) {
        std::cout << nums << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 1, 3, 5, 4, 7 }, 2);
    DoTest({ 2, 2, 2, 2, 2 }, 5);
}

int main() {
    Test();
    return 0;
}
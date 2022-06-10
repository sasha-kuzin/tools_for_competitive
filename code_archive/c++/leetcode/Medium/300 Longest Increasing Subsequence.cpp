/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/longest-increasing-subsequence/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(const std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < dp.size(); ++j) {
                if (nums[j] > nums[i]) {
                    dp[i] = std::max(dp[i], 1 + dp[j]);
                }
            }
        }
        return *std::max_element(begin(dp), end(dp));
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

void DoTest(const std::vector<int> nums, int checker) {
    auto result = Solution().lengthOfLIS(nums);
    
    if (result != checker) {
        std::cout << nums << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 10, 9, 2, 5, 3, 7, 101, 18 }, 4);
    DoTest({0, 1, 0, 3, 2, 3}, 4);
    DoTest({ 7, 7, 7, 7, 7, 7, 7 }, 1);
}

int main() {
    Test();
    return 0;
}
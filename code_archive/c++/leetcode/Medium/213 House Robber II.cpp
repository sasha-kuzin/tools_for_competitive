/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/house-robber-ii/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() < 3) {
            return *std::max_element(begin(nums), end(nums));
        }
        else {
            init_dp(nums);
            return std::max(get_dp(0, nums.size() - 2), get_dp(1, nums.size() - 1));
        }
    }
private:
    void init_dp(const std::vector<int>& nums) {
        dp.resize(nums.size(), std::vector<int>(nums.size(), -1));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][i] = nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = 0;
            }
        }
    }

    int get_dp(int from, int to) {
        if (from > to) {
            return 0;
        }
        if (dp[from][to] == -1) {
            dp[from][to] = get_dp(from, from) + get_dp(from + 2, to);
            dp[from][to] = std::max(dp[from][to], get_dp(from + 1, to));
        }
        return dp[from][to];
    }
    std::vector<std::vector<int>> dp;
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

void DoTest(std::vector<int> data, int checker) {
    auto result = Solution().rob(data);

    if (result != checker) {
        std::cout << data << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 2, 3, 2 }, 3);
    DoTest({ 1, 2, 3, 1 }, 4);
    DoTest({ 1, 2, 3 }, 3);
    DoTest({ 0 }, 0);
    DoTest({ 200, 3, 140, 20, 10 }, 340);
}

int main() {
    Test();
    return 0;
}
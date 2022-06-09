/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/arithmetic-slices/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int numberOfArithmeticSlices(const std::vector<int>& nums) {
        int pos = 0;
        int ans = 0;
        while (pos + 1 < nums.size()) {
            int lst = pos + 2;
            int diff = nums[pos + 1] - nums[pos];
            while (lst < nums.size() && nums[lst] - nums[lst - 1] == diff) {
                ++lst;
            }
            --lst;
            int dst = lst - pos + 1;
            ans += std::max(0, ((1 + dst) * dst) / 2 - (dst + dst - 1));
            pos = lst;
        }

        return ans;
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

void DoTest(const std::vector<int>& v, int checker) {
    auto result = Solution().numberOfArithmeticSlices(v);
    
    if (result != checker) {
        std::cout << v << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 1, 2, 3, 4 }, 3);
    DoTest({ 1 }, 0);
    DoTest({ 1, 2 }, 0);
    DoTest({ 1, 2, 3 }, 1);
    DoTest({ 1, 2, 3, 5, 7 }, 2);
}

int main() {
    Test();
    return 0;
}
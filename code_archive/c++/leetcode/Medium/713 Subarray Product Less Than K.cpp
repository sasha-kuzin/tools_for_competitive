/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/subarray-product-less-than-k/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>

class Solution {
public:
    int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
        int ans = 0;
        int checker = 1;
        int l = 0;
        for (int i = 0; i < nums.size(); ++i) {
            checker *= nums[i];
            while (l <= i && checker >= k) {
                checker /= nums[l];
                ++l;
            }
            ans += i - l + 1;
        }
        return ans;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& v) {
    o << "{";
    for (int i = 0; i < v.size(); ++i) {
        o << v[i] << (i + 1 == v.size() ? "" :", ");
    }
    o << "}";
    return o;
}

void doTest(const std::vector<int>& numbers , int k, int checker) {
    auto result = Solution().numSubarrayProductLessThanK(numbers, k);
    if (result != checker) {
        std::cout << numbers << " FAILED " << checker << " expected, but " << result << " given " << std::endl;
    }
}

void test() {
    doTest({ 10, 5, 2, 6 }, 100, 8);
    doTest({ 1, 2, 3 }, 0, 0);
}

int main() {
    test();
    return 0;
}
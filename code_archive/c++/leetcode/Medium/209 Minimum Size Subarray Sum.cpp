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
}/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/minimum-size-subarray-sum/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int minSubArrayLen(int target, const std::vector<int>& nums) {
        if (accumulate(begin(nums), end(nums), 0) < target) {
            return 0;
        }

        int ans = nums.size();
        int l = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= target) {
                sum -= nums[l];
                ++l;
            };

            if (l > 0) {
                --l;
                sum += nums[l];
            }
            if (sum >= target) {
                ans = std::min(ans, i - l + 1);               
            }
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
    auto result = Solution().minSubArrayLen(k, numbers);
    if (result != checker) {
        std::cout << numbers << " FAILED " << checker << " expected, but " << result << " given " << std::endl;
    }
}

void test() {
    doTest({ 2,3,1,2,4,3 }, 7, 2);
    doTest({ 1,4,4 }, 4, 1);
    doTest({ 1,1,1,1,1,1,1,1 }, 11, 0);
    doTest({ 10, 5, 2, 6 }, 100, 0);
    doTest({ 1, 2, 3 }, 1, 1);
}

int main() {
    test();
    return 0;
}

void test() {
    doTest({ 10, 5, 2, 6 }, 100, 8);
    doTest({ 1, 2, 3 }, 0, 0);
}

int main() {
    test();
    return 0;
}
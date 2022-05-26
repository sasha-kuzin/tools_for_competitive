/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
    * origin problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    * pretty easy problem, but a part of the bage challenge
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return nums[r % nums.size()];
    }
};

template<typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& vect) {
    o << "{";
    for (auto i = 0; i < vect.size(); ++i) {
        o << vect[i] << (i + 1 == vect.size() ? "" : ", ");
    }
    o << "}";
    return o;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const std::vector<std::vector<T>>& matr) {
    o << "{";
    for (auto i = 0; i < matr.size(); ++i) {
        o << matr[i] << (i + 1 == matr.size() ? "" : ", ");
    }
    o << "}";
    return o;
}
void DoTest(const std::vector<int>& nums, int checker) {
    Solution sol;
    auto result = sol.findMin(nums);
    if (result != checker) {
        std::cout << nums << " FAILED " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void test() {
    DoTest({ 3, 4, 5, 1, 2}, 1);
    DoTest({ 4, 5, 6, 7, 0, 1, 2 }, 0);
    DoTest({ 11, 13, 15, 17 }, 11);
}

int main() {
    test();
    return 0;
}
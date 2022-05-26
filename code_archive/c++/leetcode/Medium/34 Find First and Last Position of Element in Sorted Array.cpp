/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
    * origin problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    * pretty easy problem, but a part of the bage challenge
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        std::vector<int> result = { -1, -1 };
        auto fst = lower_bound(begin(nums), end(nums), target);
        if (fst != end(nums) && *fst == target) {
            auto lst = prev(upper_bound(fst, end(nums), target));
            result[0] = std::distance(begin(nums), fst), result[1] = std::distance(begin(nums), lst);
        }
        
        return result;
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
void DoTest(const std::vector<int>& nums, int target, const std::vector<int>& checker) {
    Solution sol;
    auto result = sol.searchRange(nums, target);
    if (result != checker) {
        std::cout << nums << " FAILED " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void test() {
    DoTest({ 5, 7, 7, 8, 8, 10 }, 8, { 3, 4 });
    DoTest({ 5, 7, 7, 8, 8, 10 }, 6, { -1, -1});
    DoTest({}, 0, { -1, -1 });
}

int main() {
    test();
    return 0;
}
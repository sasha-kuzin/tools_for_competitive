/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
    * origin problem: https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
    * pretty easy problem, but a part of the bage challenge
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        auto rotate_pos = find_rotate_pos(nums);
        auto iter = (target >= nums[0] && target <= *prev(rotate_pos)
            ? lower_bound(begin(nums), rotate_pos, target)
            : lower_bound(rotate_pos, end(nums), target)
            );
        return (iter != end(nums) && *iter == target ? iter - begin(nums) : -1);
    }
private:
     std::vector<int>::const_iterator find_rotate_pos(const std::vector<int>& nums) {
        int l = 0, r = nums.size();
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }

        return begin(nums) + r;
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
void DoTest(const std::vector<int>& nums, int target, int checker) {
    Solution sol;
    auto result = sol.search(nums, target);
    if (result != checker) {
        std::cout << nums << " FAILED " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void test() {
    DoTest({ 4, 5, 6, 7, 0, 1, 2 }, 0, 4);
    DoTest({ 4, 5, 6, 7, 0, 1, 2 }, 3, -1);
    DoTest({ 0, 1, 2, 3, 4, 5, 6, 7 }, 5, 5);
    DoTest({ -5, -3, -1, 1, -9, -7 }, 1, 3);
    DoTest({ 0, 1, 2, 3, 4, 5, 6, 7 }, -1, -1);
    DoTest({ -5, -3, -1, 1, -9, -7 }, 9, -1);
    DoTest({1}, 0, -1);

}

int main() {
    test();
    return 0;
}
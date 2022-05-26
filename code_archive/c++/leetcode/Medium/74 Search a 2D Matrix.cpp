/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
    * origin problem: https://leetcode.com/problems/search-a-2d-matrix/
    * pretty easy problem, but a part of the bage challenge
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        auto row = *find_row(matrix, target);
        auto position = lower_bound(begin(row), end(row), target);
        
        return (position != end(row) && *position == target);
    }
private:
    std::vector<std::vector<int>>::const_iterator find_row(const std::vector<std::vector<int>>& matrix, int target) {
        auto l = begin(matrix), r = end(matrix);
        while (l + 1 != r) {
            auto mid = l + std::distance(l, r) / 2;
            if ((*mid)[0] <= target) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return l;
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
void DoTest(const std::vector<std::vector<int>>& nums, int target, int checker) {
    Solution sol;
    auto result = sol.searchMatrix(nums, target);
    if (result != checker) {
        std::cout << nums << " FAILED " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void test() {
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 3, true);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 16, true);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 23, true);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 4, false);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 13, false);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 31, false);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, -1, false);
    DoTest({ {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} }, 65, false);

}

int main() {
    test();
    return 0;
}
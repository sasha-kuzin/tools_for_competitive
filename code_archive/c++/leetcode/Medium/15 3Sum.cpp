/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/3sum/
 * this problem is from the algorithm badge challenge
*/ 
#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[j] == nums[j - 1] && j - i > 1) {
                    continue;
                }

                int checker = -(nums[i] + nums[j]);
                auto pos = std::lower_bound(begin(nums) + j + 1, end(nums), checker);
                if (pos != end(nums) && *pos == checker) {
                    result.push_back({ nums[i], nums[j], *pos });
                }
            }
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

void DoTest(std::vector<int> values, const std::vector<std::vector<int>>& checker) {
    Solution sol;
    auto result = sol.threeSum(values);
    if (result != checker) {
        std::cerr << values << " FAILED " << checker << " expected, but " << result << " is given " << std::endl;
    }
}

void test() {
    DoTest({ -1, 0, 1, 2, -1, 4 }, { {-1, -1, 2}, {-1, 0, 1} });
    DoTest({}, {});
    DoTest({ 0 }, { });
}

int main() {
    test();
    return 0;
}
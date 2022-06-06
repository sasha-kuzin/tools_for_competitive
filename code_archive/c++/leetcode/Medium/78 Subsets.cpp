/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/subsets/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> perm(nums.size(), 0);
        while (perm[0] < 2) {
            std::vector<int> cur;
            for (int i = 0; i < nums.size(); ++i) {
                if (perm[i]) {
                    cur.push_back(nums[i]);
                }
            }
            result.push_back(std::move(cur));

            ++perm.back();
            for (int i = perm.size() - 1; i > 0; --i) {
                if (perm[i] == 2) {
                    ++perm[i - 1];
                    perm[i] = 0;
                }
            }
        }

        return result;
    }
};

template <typename T>
std::ostream& operator << (std::ostream & o, const std::vector<T>&v) {
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

void DoTest(std::vector<int> vect, std::vector<std::vector<int>> checker) {
    auto result = Solution().subsets(vect);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << vect << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        {1, 2, 3},
        {
            {},
            {1},
            {2},
            {3}, 
            {1, 2},
            {2, 3},
            {1, 3},
            {1, 2, 3}
        }
    );
    DoTest(
        {0},
        {
            {},
            {0}
        }
    );
}

int main() {
    Test();
    return 0;
}
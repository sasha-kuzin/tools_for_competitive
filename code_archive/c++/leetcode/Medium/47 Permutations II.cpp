/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/permutations-ii/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#include <set>

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::set<std::vector<int>> result;

        sort(begin(nums), end(nums));

        do {
            result.insert(nums);
        } while (std::next_permutation(begin(nums), end(nums)));

        return { begin(result), end(result) };
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
    auto result = Solution().permuteUnique(vect);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << vect << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        { 1, 1, 2 },
        {
            {1, 1, 2},
            {1, 2, 1},
            {2, 1, 1}
        }
    );
    DoTest(
        {1, 2, 3},
        {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 1, 2},
            {3, 2, 1}
        }
    );
}

int main() {
    Test();
    return 0;
}
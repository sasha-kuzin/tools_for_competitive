/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/combination-sum-ii/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#include <set>
#include <functional>
#include <iterator>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::sort(begin(candidates), end(candidates));
        for (const auto& checker : getAllCombinations(target)) {
            int pos = 0;
            for (const auto& elem : candidates) {
                pos += (elem == checker[pos]);
                if (pos == checker.size()) break;
            }
            if (pos == checker.size()) {
                result.push_back(checker);
            }
        }

        return result;
    }
private:
    static const int mxNumber = 50;

    std::vector<std::vector<int>> getAllCombinations(int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current = { 1 };
        int sum = 1;
        while (!current.empty()) {
            if (sum == target) {
                result.push_back(current);

                sum -= current.back();
                current.pop_back();

                if (!current.empty()) {
                    ++current.back();
                    ++sum;
                }
            }
            else if (sum > target) {
                sum -= current.back();
                current.pop_back();

                if (!current.empty()) {
                    ++current.back();
                    ++sum;
                }
            }
            else {
                sum += current.back();
                current.push_back(current.back());
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

void DoTest(std::vector<int> vect, int target, std::vector<std::vector<int>> checker) {
    auto result = Solution().combinationSum2(vect, target);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << vect << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        { 10, 1, 2 ,7, 6, 1, 5 },
        8,
        {
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {  2, 6}
        }
    );
    DoTest(
        {2, 5, 2, 1, 2},
        5,
        {
            {1, 2, 2},
            {5}
        }
    );
}

int main() {
    Test();
    return 0;
}
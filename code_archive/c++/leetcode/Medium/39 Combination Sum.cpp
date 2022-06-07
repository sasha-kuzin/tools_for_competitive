/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/combination-sum/
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
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return { begin(pathes), end(pathes) };
    }
private:
    void dfs(int pos, int rest, const std::vector<int>& candidates) {
        if (rest == 0) {
            pathes.insert(path);
        }
        else if (rest > 0 && pos < candidates.size()) {
            dfs(pos + 1, rest, candidates);
            path.push_back(candidates[pos]);
            dfs(pos, rest - candidates[pos], candidates);
            dfs(pos + 1, rest - candidates[pos], candidates);
            path.pop_back();
        }
    }
    std::vector<int> path;
    std::set<std::vector<int>> pathes;
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
    auto result = Solution().combinationSum(vect, target);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << vect << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        { 2, 3, 6, 7 },
        7,
        {
            {2, 2, 3},
            {7}
        }
    );
    DoTest(
        {2, 3, 5},
        8,
        {
            {2, 2, 2, 2},
            {2, 3, 3},
            {3, 5}
        }
    );
    DoTest(
        { 2 },
        1,
        {}
    );
}

int main() {
    Test();
    return 0;
}
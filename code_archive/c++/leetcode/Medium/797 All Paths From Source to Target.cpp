/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/all-paths-from-source-to-target/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>

class Solution {
public:
    using grid = std::vector<std::vector<int>>;
    grid allPathsSourceTarget(grid& graph) {
        grid ans;
        std::stack<int>s;
        s.push(0);
        std::vector<int> v;
        while (!s.empty()) {
            int cur = s.top();
            if (v.size() && v.back() == cur) {
                s.pop();
                v.pop_back();
            }
            else {
                v.push_back(cur);
                if (cur == graph.size() - 1) {
                    ans.push_back(v);
                }
                else {
                    for (int e : graph[cur]) {
                        s.push(e);
                    }
                }
            }
        }
        return ans;
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

void DoTest(Solution::grid matr, Solution::grid checker) {
    auto result = Solution().allPathsSourceTarget(matr);
    std::sort(begin(result), end(result));
    std::sort(begin(checker), end(checker));

    if (result != checker) {
        std::cout << matr << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        {
            {1, 2},
            {3},
            {3},
            {}
        },
        {
            {0, 1, 3},
            {0, 2, 3}
        }
    );
    DoTest(
        {
            {4, 3, 1},
            {3, 2, 4},
            { 3 },
            { 4 },
            {}
        },
        {
            {0, 4},
            {0, 3, 4},
            {0, 1, 3, 4},
            {0, 1, 2, 3, 4},
            {0, 1, 4}
        }
    );
}

int main() {
    Test();
    return 0;
}
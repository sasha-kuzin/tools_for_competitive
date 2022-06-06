/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <queue>

class Solution {
    struct node {
        int x;
        int y;
    };
public:
    int shortestPathBinaryMatrix(const std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>> result(n, std::vector<int>(n, 1e6));

        std::queue<node> q;

        if (grid[0][0] == 0) {
            q.push({ 0, 0 });
            result[0][0] = 0;
        }

        while (!q.empty()) {
            node cur = q.front();
            q.pop();
            int cur_depth = result[cur.x][cur.y] + 1;

            for (int i = std::max(0, cur.x - 1); i < std::min(n, cur.x + 2); ++i) {
                for (int j = std::max(0, cur.y - 1); j < std::min(n, cur.y + 2); ++j) {
                    if (grid[i][j] == 0 && result[i][j] > cur_depth) {
                        result[i][j] = cur_depth;
                        q.push({ i, j });
                    }
                }
            }
        }

        return (result[n - 1][n - 1] == 1e6 ? -1 : 1 + result[n - 1][n - 1]);
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

void DoTest(const std::vector<std::vector<int>>& matr, int checker) {
    auto result = Solution().shortestPathBinaryMatrix(matr);
    if (result != checker) {
        std::cout << matr << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
        },
        4
    );

    DoTest(
        {
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
        },
        -1
    );
}

int main() {
    Test();
    return 0;
}
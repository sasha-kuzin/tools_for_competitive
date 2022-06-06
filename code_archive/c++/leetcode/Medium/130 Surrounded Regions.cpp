/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/surrounded-regions/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <utility>
#include <queue>

class Solution {
    struct point {
        int x;
        int y;
    };
public:
    using matrix = std::vector<std::vector<char>>;
    void solve(matrix& board) {
        int n = board.size();
        int m = board.front().size();

        std::vector<std::vector<char>> result(n, std::vector<char>(m, 'X'));


        auto check_entry_point = [&](int x, int y) {
            if (board[x][y] == 'O' && result[x][y] == 'X') {
                bfs(board, result, x, y);
            }
        };

        for (int i = 0; i < n; ++i) {
            check_entry_point(i, 0);
            check_entry_point(i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            check_entry_point(0, j);
            check_entry_point(n - 1, j);
        }

        std::swap(board, result);
    }

private:
    void bfs(matrix& board, matrix& result, int x, int y) {
        std::queue<point> q;

        auto is_valid_coord = [](int arg, int edge) {
            return 0 <= arg && arg < edge;
        };

        auto is_valid = [&](int x, int y) {
            return is_valid_coord(x, board.size()) 
                && is_valid_coord(y, board[0].size()) 
                && board[x][y] == 'O'
                && result[x][y] == 'X';
        };

        auto update_queue = [&](int x, int y) {
            if (is_valid(x, y)) {
                result[x][y] = 'O';
                q.push({ x, y });
            }
        };

        q.push({ x, y });
        result[x][y] = 'O';

        while (!q.empty()) {
            point cur = q.front();
            q.pop();

            update_queue(cur.x - 1, cur.y);
            update_queue(cur.x + 1, cur.y);
            update_queue(cur.x, cur.y - 1);
            update_queue(cur.x, cur.y + 1);
        }
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

void DoTest(Solution::matrix matr, const Solution::matrix& checker) {
    Solution().solve(matr);
    if (matr != checker) {
        std::cout << matr << " FAILED! " << checker << " expected, but " << matr << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
        },
        {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
        }
    );
}

int main() {
    Test();
    return 0;
}
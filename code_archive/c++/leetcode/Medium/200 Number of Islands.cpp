/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/number-of-islands/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <queue>
#include <utility>

class Solution {
public:
    template<typename T>
    using matrix = std::vector<std::vector<T>>;

    int numIslands(const matrix<char>& grid) {
        auto is_visited = create_is_visited_matrix(grid);

        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.back().size(); ++j) {
                if (is_visited[i][j] == 0) {
                    ++ans;
                    dfs(is_visited, { i, j }, ans);
                }
            }
        }

        return ans;
    }
private:
    matrix<int> create_is_visited_matrix(const matrix<char>& grid) {
        matrix<int> used(grid.size(), std::vector<int>(grid.back().size()));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.back().size(); ++j) {
                used[i][j] = (grid[i][j] == '1' ? 0 : -1);
            }
        }
        return used;
    }

    void dfs(matrix<int>& is_visited, std::pair<int, int> start_position, int color) {
        std::queue<std::pair<int, int>> q;
        is_visited[start_position.first][start_position.second] = color;
        q.push(start_position);

        while (!q.empty()) {
            int row, col;
            std::tie(row, col) = q.front();
            q.pop();

            if (is_valid(is_visited, { row + 1, col }))
                update(is_visited, q, { row + 1, col }, color);

            if (is_valid(is_visited, { row - 1, col }))
                update(is_visited, q, { row - 1, col }, color);

            if (is_valid(is_visited, { row, col + 1 }))
                update(is_visited, q, { row, col + 1 }, color);

            if (is_valid(is_visited, { row, col - 1 }))
                update(is_visited, q, { row, col - 1 }, color);
        }
    }

    bool is_valid(const matrix<int>& grid, std::pair<int, int> coord) {
        return coord.first >= 0
            && coord.first < grid.size()
            && coord.second >= 0
            && coord.second < grid.back().size()
            && grid[coord.first][coord.second] == 0;
    }

    void update(matrix<int>& grid, std::queue <std::pair<int, int>>& q, std::pair<int, int> coord, int color) {
        grid[coord.first][coord.second] = color;
        q.push(coord);
    }
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& v) {
    o << "{";
    for (int i = 0; i < v.size(); ++i) {
        o << v[i] << (i + 1 == v.size() ? "" :", ");
    }
    o << "}";
    return o;
}

void doTest(const Solution::matrix<char>& grid, int checker) {
    auto result = Solution().numIslands(grid);
    if (result != checker) {
        std::cout << grid << " FAILED " << checker << " expected, but " << result << " given " << std::endl;
    }
}

void test() {
    doTest(
        {
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '1', '1', '1', '1'}
        },
        1
    );
    doTest(
        {
            {'1', '1', '1', '1', '1'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        },
        1
    );
    doTest(
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        },
        3
        );
}

int main() {
    test();
    return 0;
}
/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/word-search/
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
    bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.front().size(); ++j) {
                if (dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(
        std::vector<std::vector<char>>& board, 
        const std::string& word, 
        int pos,
        int x,
        int y) {
        if (pos == word.length()) {
            return true;
        }
        else if (x >= 0 && x < board.size() && y >= 0 && y < board.front().size()) {
            if (board[x][y] == word[pos]) {
                board[x][y] = '\0';
                auto checker = 
                    dfs(board, word, pos + 1, x + 1, y) ||
                    dfs(board, word, pos + 1, x - 1, y) ||
                    dfs(board, word, pos + 1, x, y + 1) ||
                    dfs(board, word, pos + 1, x, y - 1);
                board[x][y] = word[pos];
                return checker;
            }
        }
        return false;
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

void DoTest(std::vector<std::vector<char>> grid, const std::string& word, bool checker) {
    auto result = Solution().exist(grid, word);

    if (result != checker) {
        std::cout << grid << " : " << word << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} }, "ABCB", false);
    DoTest({ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} }, "SEE", true);
    DoTest({ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} }, "ABCCED", true);
}

int main() {
    Test();
    return 0;
}
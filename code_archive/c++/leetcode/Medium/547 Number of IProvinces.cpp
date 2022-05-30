/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/number-of-provinces/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <queue>
#include <utility>

class Solution {
public:
    using matrix = std::vector<std::vector<int>>;

    int findCircleNum(const matrix& isConnected) {
        std::vector<int> isVisited(isConnected.size());

        int ans = 0;
        for (int i = 0; i < isVisited.size(); ++i) {
            if (isVisited[i] == 0) {
                ++ans;
                bfs(isConnected, isVisited, i);
            }
        }

        return ans;
    }

private:
    void bfs(const matrix& isConnected, std::vector<int>& isVisited, int startPosition) {
        std::queue<int> q;
        isVisited[startPosition] = 1;
        q.push(startPosition);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < isVisited.size(); ++i) {
                if (isConnected[cur][i] && isVisited[i] == 0) {
                    isVisited[i] = 1;
                    q.push(i);
                }
            }
        }
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

void doTest(const Solution::matrix& isConnected, int checker) {
    auto result = Solution().findCircleNum(isConnected);
    if (result != checker) {
        std::cout << isConnected << " FAILED " << checker << " expected, but " << result << " given " << std::endl;
    }
}

void test() {
    doTest(
        {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        },
        1
    );
    doTest(
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
        },
        2
    );
    doTest(
        {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        },
        3
    );
    doTest(
        {
            {1, 0, 0, 1},
            {0, 1, 1, 1},
            {0, 1, 1, 1},
            {1, 0, 1, 1}
        },
        1
    );
}

int main() {
    test();
    return 0;
}
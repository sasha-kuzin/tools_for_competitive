/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/generate-parentheses/
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
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string perm(n + n, 40);
        while (perm[0] < 42) {
            if (isValidParenthesis(perm)) {
                result.push_back(perm);
            }

            ++perm.back();
            for (int pos = perm.size() - 1; pos > 0; --pos) {
                if (perm[pos] == 42) {
                    ++perm[pos - 1];
                    perm[pos] = 40;
                }
            }
        }

        return result;
    }
private:
    bool isValidParenthesis(const std::string& arg) {
        int balance = 0;
        for (const auto& e : arg) {
            if (e == '(') {
                ++balance;
            }
            else {
                --balance;
            }
            if (balance < 0) return false;
        }

        return balance == 0;
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

void DoTest(int arg, std::vector<std::string> checker) {
    auto result = Solution().generateParenthesis(arg);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << arg << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        3,
        { "((()))","(()())","(())()","()(())","()()()" }
    );
    DoTest(
        1,
        { "()" }
    );
}

int main() {
    Test();
    return 0;
}
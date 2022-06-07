/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
    std::vector<std::string> letterCombinations(std::string digits) {
        for (char& e : digits) e -= '0';

        std::vector<std::string> ans;
        ans.reserve(256);

        std::vector<int> perm(digits.length());
        std::string cur(digits.length(), ' ');

        int pos = 0;
        while (pos >= 0) {
            if (pos == digits.length()) {
                if (cur.length()) ans.push_back(cur);
                --pos;
                if (pos >= 0) {
                    ++perm[pos];
                }
            }
            else if (perm[pos] == limits[digits[pos]]) {
                perm[pos] = 0;
                --pos;
                if (pos >= 0) {
                    ++perm[pos];
                }
            }
            else {
                cur[pos] = digitToSym[digits[pos]][perm[pos]];
                ++pos;
            }
        }


        return ans;
    }
private:
    const std::vector<int> limits = { 0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };
    const std::vector<std::string> digitToSym = { "", "",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
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

void DoTest(std::string arg, std::vector<std::string> checker) {
    auto result = Solution().letterCombinations(arg);

    sort(begin(checker), end(checker));
    sort(begin(result), end(result));
    if (result != checker) {
        std::cout << arg << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(
        "23",
        {
            "ad",
            "ae",
            "af",
            "bd",
            "be",
            "bf",
            "cd",
            "ce",
            "cf"
        }
    );
    DoTest(
        "",
        {
        }
    );
    DoTest(
        "2",
        {
            "a",
            "b",
            "c"
        }
    );  
}

int main() {
    Test();
    return 0;
}
/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/longest-palindromic-substring/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        int pos = 0, len = 1;
        for (int i = 0; i < s.length(); ++i) {
            auto checker = check(s, i, i);
            if (checker.second > len) {
                std::tie(pos, len) = checker;
            }
        }

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                auto checker = check(s, i - 1, i);
                if (checker.second > len) {
                    std::tie(pos, len) = checker;
                }
            }
        }

        return { begin(s) + pos, begin(s) + pos + len };
    }
private:
    std::pair<int, int> check(const std::string& s, int fst, int snd) {
        int cur = snd - fst + 1;
        int lx = fst - 1, rx = snd + 1;
        while (lx >= 0 && rx < s.length() && s[lx] == s[rx]) {
            --lx, ++rx, cur += 2;
        }
        return { snd - cur / 2, cur };
    }
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& v) {
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

void DoTest(const std::string& arg, const std::string& checker) {
    auto result = Solution().longestPalindrome(arg);
    
    if (result != checker) {
        std::cout << arg << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest("abad", "aba");
    DoTest("cbbd", "bb");
    DoTest("ccc", "ccc");
}

int main() {
    Test();
    return 0;
}
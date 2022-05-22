/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/palindromic-substrings/
 */

#include <string>
#include <iostream>

template<typename BidirIterator>
bool isPalindrome(BidirIterator lhs, BidirIterator rhs) {
    while (lhs < rhs) {
        if (*lhs != *rhs) return false;
        lhs = next(lhs), rhs = prev(rhs);
    }
    return true;
}

class Solution {
public:
    int countSubstrings(const std::string& s) const {
        int ans = 0;
        for (auto lhs = begin(s); lhs != end(s); lhs = next(lhs)) {
            for (auto rhs = lhs; rhs != end(s); rhs = next(rhs)) {
                ans += isPalindrome(lhs, rhs);
            }
        }
        return ans;
    }
};

void DoTest(const std::string& arg, int checker) {
    Solution sol;
    int result = sol.countSubstrings(arg);
    std::cout << "Test for " << arg << " is " << (result == checker ? "OK " : "FAILED ") << "\n";
    if (result != checker) {
        std::cout << "Expected " << checker << ", but " << result << " received" << std::endl;
    }

}

void test() {
    DoTest("aaa", 6);
    DoTest("abc", 3);
    DoTest("abcbab", 9);
}

int main() {
    test();
	return 0;
}
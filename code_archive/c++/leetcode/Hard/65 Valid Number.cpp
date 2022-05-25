/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/valid-number/
 * this solution is interesting only because this is my first try in regex in C++
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <chrono>

class Solution {
    inline static const std::regex pattern{ R"(^([+-]?(\.\d+|\d+(\.\d*)?))([eE][+-]?\d+)?$)" };
public:
    bool isNumber(std::string s) {
        return std::regex_match(s.data(), pattern);
    }
};

void DoTest(std::string value, bool expected_result) {
    Solution sol;
    auto result = sol.isNumber(value);
    if (result == expected_result) {
        std::cout << std::fixed << std::setw(15) << value << " is OK (" << result << ")" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setw(15) << value << " is FAILED: " << expected_result << " expected, but " << result << " received" << std::endl;
    }
}

void test() {
    DoTest("7580599293", true);
    DoTest("0", true);
    DoTest("2", true);
    DoTest("0089", true);
    DoTest("-0.1", true);
    DoTest("+3.14", true);
    DoTest("4.", true);
    DoTest("-.9", true);
    DoTest("2e10", true);
    DoTest("-90E3", true);
    DoTest("-3e+7", true);
    DoTest("+6e-1", true);
    DoTest("-53.5e93", true);
    DoTest("-123.456e789", true);
    DoTest("61e8", true);

    DoTest("abc", false);
    DoTest("1a", false);
    DoTest("1e", false);
    DoTest("e3", false);
    DoTest("99e2.5", false);
    DoTest("--6", false);
    DoTest("-+3", false);
    DoTest("95a54e53", false);
    DoTest(".", false);
    DoTest("+e3", false);
    DoTest("-E4", false);
}

int main() {
    test();
    return 0;
}
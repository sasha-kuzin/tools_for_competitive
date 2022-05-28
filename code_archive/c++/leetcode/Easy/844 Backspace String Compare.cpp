/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/backspace-string-compare/
 * this problem is very easy, but from the algorithm badge challenge
*/ 
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    bool backspaceCompare(const std::string& s, const std::string& t) {
        return editString(s) == editString(t);
    }
private:
    std::string editString(const std::string& s) {
        std::string editor;
        for (char e : s) {
            if (e == '#') {
                if (!editor.empty()) editor.pop_back();
            }
            else {
                editor.push_back(e);
            }
        }

        return editor;
    }
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::pair<T, T>& p) {
    o << "{ " << p.first << ", " << p.second << " }";
    return o;
}

void DoTest(const std::pair<std::string, std::string>& data, bool checker) {
    auto result = Solution().backspaceCompare(data.first, data.second);
    if (result != checker) {
        std::cerr << data << " FAILED " << checker << " was expected, but " << result << " was given" << std::endl;
    }
}

void test() {
    DoTest({ "ab#c", "ad#c" }, true);
    DoTest({ "ab##", "c#d#" }, true);
    DoTest({ "a#c", "b" }, false);
    DoTest({ "y#fo##f", "y#f#o##f" }, true);
}

int main() {
    test();
    return 0;
}
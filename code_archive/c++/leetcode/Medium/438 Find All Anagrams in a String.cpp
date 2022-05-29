/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
        std::vector<int> result;
        result.reserve(s.length());

        const auto checker = createMask(p);
        std::vector<int> mask(sz);
        for (int i = 0; i < s.length(); ++i) {
            ++mask[getIndex(s[i])];
            if (i >= p.length()) {
                --mask[getIndex(s[i - p.length()])];
            }
            if (checker == mask) result.push_back(i - p.length() + 1);
        }

        return result;
    }
private: 
    static const int sz = 26;
    std::vector<int> createMask(const std::string& arg) {
        std::vector<int> mask(sz);
        for (char e : arg) ++mask[getIndex(e)];
        return mask;
    }
    static inline int getIndex(char arg) {
        return arg - 'a';
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

void doTest(const std::string& text , const std::string& p, const std::vector<int>& checker) {
    auto result = Solution().findAnagrams(text, p);
    if (result != checker) {
        std::cout << text << " FAILED " << checker << " expected, but " << result << " given " << std::endl;
    }
}

void test() {
    doTest("cbaebabacd", "abc", { 0, 6 });
    doTest("abab", "ab", { 0, 1, 2 });
}

int main() {
    test();
    return 0;
}
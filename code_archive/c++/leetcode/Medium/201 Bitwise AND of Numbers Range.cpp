/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;

        int checker = (1 << 30);

        while (checker) {
            if ((checker & left) == (right & checker)) {
                ans += (checker & left);
                checker >>= 1;
            }
            else {
                break;
            }
        }

        return ans;
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

void DoTest(int left, int right, int checker) {
    auto result = Solution().rangeBitwiseAnd(left, right);

    if (result != checker) {
        std::cout << "[" << left << ", " << right << "] " << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest(5, 7, 4);
    DoTest(0, 0, 0);
    DoTest(1, 2147483647, 0);
}

int main() {
    Test();
    return 0;
}
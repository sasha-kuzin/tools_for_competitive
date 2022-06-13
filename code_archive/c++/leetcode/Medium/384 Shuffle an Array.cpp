/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/shuffle-an-array/
 * this problem is from the algorithm badge challenge
 * it is not covered with tests, because requirements doesn't tell that shuffled array MUST be reordered.
 * it looks like that we can always pass initial array
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>
#include <iterator>

class Solution {
public:
    Solution(const std::vector<int>& nums): g(rd()), m_values(nums), m_shuffled(nums) {}

    const std::vector<int>& reset() {
        return m_values;
    }

    const std::vector<int>& shuffle() {
        std::shuffle(begin(m_shuffled), end(m_shuffled), g);
        return m_shuffled;
    }
private:
    std::random_device rd;
    std::mt19937 g;
    std::vector<int> m_values;
    std::vector<int> m_shuffled;
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


int main() {
    return 0;
}
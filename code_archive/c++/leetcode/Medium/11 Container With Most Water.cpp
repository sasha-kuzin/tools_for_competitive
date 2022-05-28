/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/container-with-most-water/
 * this problem is from the algorithm badge challenge
*/ 
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        std::vector<std::pair<int, int>> h(10001, { 1e9, -1 });
        int l = 1, r = height.size();
        for (int i = 0; i < height.size(); ++i) {
            h[height[i]] = { std::min(h[height[i]].first, i), std::max(h[height[i]].second, i) };
        }

        for (int i = h.size() - 2; i > 0; --i) {
            h[i] = { std::min(h[i].first, h[i + 1].first), std::max(h[i].second, h[i + 1].second) };
        }

        int ans = 0;
        for (int i = 1; i < h.size(); ++i) {
            if (h[i].second >= 0) {
                ans = std::max(ans, (h[i].second - h[i].first) * i);
            }
        }

        return ans;
    }
};


template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& v) {
    o << "{";
    for (int i = 0; i < v.size(); ++i) {
        o << v[i] << (i + 1 == v.size() ? "": ", ");
    }
    o << "}";
    return o;
}

template <typename T>
std::ostream& operator << (std::ostream& o, const std::pair<T, T>& p) {
    o << "{ " << p.first << ", " << p.second << "}";
    return o;
}

void DoTest(const std::vector<int>& data, int checker) {
    auto result = Solution().maxArea(data);
    if (result != checker) {
        std::cerr << data << " FAILED " << checker << " was expected, but " << result << " was given" << std::endl;
    }
}

void test() {
    DoTest({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49 );
    DoTest({1, 1}, {1});
}

int main() {
    test();
    return 0;
}
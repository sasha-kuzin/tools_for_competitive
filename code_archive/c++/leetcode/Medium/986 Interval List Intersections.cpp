/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/interval-list-intersections/
 * this problem is from the algorithm badge challenge
*/ 
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    using intervals = std::vector<std::vector<int>>;

    intervals intervalIntersection(const intervals& firstList, const intervals& secondList) {
        std::vector<std::vector<int>> ans;
        ans.reserve(std::max(firstList.size(), secondList.size()));

        int fPos = 0, sPos = 0;
        while (fPos < firstList.size() && sPos < secondList.size()) {
            int lhs = std::max(firstList[fPos][0], secondList[sPos][0]),
                rhs = std::min(firstList[fPos][1], secondList[sPos][1]);

            if (lhs <= rhs) ans.push_back({ lhs, rhs });

            (firstList[fPos][1] < secondList[sPos][1] ? ++fPos : ++sPos);
        }

        ans.shrink_to_fit();
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

void DoTest(std::pair<const Solution::intervals&, const Solution::intervals&> data, const Solution::intervals& checker) {
    auto result = Solution().intervalIntersection(data.first, data.second);
    if (result != checker) {
        std::cerr << data << " FAILED " << checker << " was expected, but " << result << " was given" << std::endl;
    }
}

void test() {
    DoTest({ {{0,2},{5,10},{13,23},{24,25}}, {{1,5},{8,12},{15,24},{25,26}} }, {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}} );
    DoTest({ {{0,2},{5,10}}, {} }, {});
}

int main() {
    test();
    return 0;
}
/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/jump-game/
 * this problem is from the algorithm badge challenge
*/

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

struct segment_tree {
    segment_tree(int len = 0) {
        sz = 1;
        while (sz <= len) sz <<= 1;

        tree.resize(sz + sz);
    }
    void set(int pos) {
        pos += sz;
        while (pos > 0) {
            tree[pos] = true;
            pos >>= 1;
        }
    }

    bool get(int from, int to) {
        return private_get(1, from, to, 0, sz);
    }
private:
    bool private_get(int pos, int from, int to, int left, int right) {
        if (from >= right || to <= left) {
            return false;
        }
        if (from <= left && to >= right) {
            return tree[pos];
        }

        int mid = (left + right) >> 1;
        return private_get(pos + pos, from, to, left, mid)
            || private_get(pos + pos + 1, from, to, mid, right);
    }
    int sz;
    std::vector<bool> tree;
};

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        t = segment_tree(nums.size());
        std::vector<int> dp(nums.size());
        dp.back() = 1;
        t.set(nums.size() - 1);

        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[i] = t.get(i, i + nums[i] + 1);
            if (dp[i]) {
                t.set(i);
            }
        }
        return dp[0];
    }
private:

    segment_tree t;
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

void DoTest(std::vector<int> data, int checker) {
    auto result = Solution().canJump(data);

    if (result != checker) {
        std::cout << data << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 2, 3, 1, 1, 4}, 1);
    DoTest({ 3, 2, 1, 0, 4 }, 0);
    DoTest({ 1, 2 }, 1);
}

int main() {
    Test();
    return 0;
}
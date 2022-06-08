/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/jump-game-ii/
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

        tree.resize(sz + sz, 1e9);
    }
    void set(int pos, int val) {
        pos += sz;
        tree[pos] = val;
        pos >>= 1;
        while (pos > 0) {
            tree[pos] = std::min(tree[pos + pos], tree[pos + pos + 1]);
            pos >>= 1;
        }
    }

    int get(int from, int to) {
        return private_get(1, from, to, 0, sz);
    }
private:
    int private_get(int pos, int from, int to, int left, int right) {
        if (from >= right || to <= left) {
            return 1e9;
        }
        if (from == left && to == right) {
            return tree[pos];
        }

        int mid = (left + right) >> 1;
        int ans = 1e9;
        if (mid > from) {
            ans = std::min(ans, private_get(pos + pos, from, std::min(to, mid), left, mid));
        }
        if (mid < to) {
            ans = std::min(ans, private_get(pos + pos + 1, std::max(from, mid), to, mid, right));
        }
        return ans;
    }
    int sz;
    std::vector<int> tree;
};

class Solution {
public:
    int jump(std::vector<int>& nums) {
        t = segment_tree(nums.size());
        std::vector<int> dp(nums.size());
        dp.back() = 0;
        t.set(dp.size() - 1, 0);

        for (int i = nums.size() - 2; i >= 0; --i) {
            dp[i] = 1 + t.get(i, std::min((int)nums.size(), i + nums[i] + 1));
            t.set(i, dp[i]);
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
    auto result = Solution().jump(data);

    if (result != checker) {
        std::cout << data << " FAILED! " << checker << " expected, but " << result << " given" << std::endl;
    }
}

void Test() {
    DoTest({ 2, 3, 1, 1, 4}, 2);
    DoTest({ 2, 3, 0, 1, 4 }, 2);
    DoTest({ 1, 3, 2 }, 2);
}

int main() {
    Test();
    return 0;
}
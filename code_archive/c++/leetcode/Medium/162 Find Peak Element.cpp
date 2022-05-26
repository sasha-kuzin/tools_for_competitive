/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
    * origin problem: https://leetcode.com/problems/find-peak-element/
    * I don't know why it's medium, because iteration is enough for time and memory limits
    * But description says "you must do O(log n)" so lets do binary search
    * 
    * 
    * How it works?
    * Each iteration we check mid element. It may be larger of the next one or not;
    * if yes, we assume that this is our possible pick and put it as new R
    * if no, we assumme that next one should be pick (because nums[r] always means that nums[r + 1] is less) and put mid as new L
    * Does this effort cost 6 ms? I don't know, but it was fun
*/
#include <vector>
#include <iostream>
#include <set>

class Solution {
public:
    int findPeakElement(const std::vector<int>& nums) {
        int l = -1, r = nums.size() - 1;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (nums[mid] < nums[mid + 1]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return r;
    }
};

template<typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& vect) {
    o << "{";
    for (auto i = 0; i < vect.size(); ++i) {
        o << vect[i] << (i + 1 == vect.size() ? "" : ", ");
    }
    o << "}";
    return o;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const std::vector<std::vector<T>>& matr) {
    o << "{";
    for (auto i = 0; i < matr.size(); ++i) {
        o << matr[i] << (i + 1 == matr.size() ? "" : ", ");
    }
    o << "}";
    return o;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const std::set<T>& s) {
    o << "{";
    for (auto it = begin(s); it != end(s); ++it) {
        o << *it << (next(it) == end(s) ? "" : ", ");
    }
    o << "}";
    return o;
}

void DoTest(const std::vector<int>& nums, const std::set<int>& checkers) {
    Solution sol;
    auto result = sol.findPeakElement(nums);
    if (checkers.count(result) == 0) {
        std::cout << nums << " FAILED " << checkers << " expected, but " << result << " given" << std::endl;
    }
}

void test() {
    DoTest({ 1, 2, 3, 1 }, { 2 });
    DoTest({ 0, 1, 0, 2, 0, 3, 0, 2, 0, 1, 0 }, { 1, 3, 5, 7, 9, 11 });
    DoTest({ 1, 0, 2, 0, 3, 0, 2, 0, 1 }, { 0, 2, 4, 6, 8 });
    DoTest({ 11, 13, 15, 17 }, { 3 });
    DoTest({ 17, 15, 13, 11 }, { 0 });
}

int main() {
    test();
    return 0;
}
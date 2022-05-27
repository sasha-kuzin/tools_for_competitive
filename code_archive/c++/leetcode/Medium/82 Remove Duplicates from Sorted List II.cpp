/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * this problem is from the algorithm badge challenge
 * there are TWO solutions: first one used kinda counting sort trick and std::vector, second one use ListNode only
 * actually execution time and used memory are almost the same
*/ 
#include <vector>
#include <iostream>
#include <set>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates2(ListNode* head) {
        std::vector<int> counters(mx);
        ListNode* cur = head;

        while (cur != nullptr) {
            counters[cur->val + aligner]++;
            ListNode* nex = cur->next;
            delete cur;
            cur = nex;
        }


        ListNode falseHead(0, nullptr);
        cur = &falseHead;
        for (int i = 0; i < counters.size(); ++i) {
            if (counters[i] == 1) {
                cur->next = new ListNode(i - aligner);
                cur = cur->next;
            }
        }
        return falseHead.next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode falseNext{ 0, head };
        ListNode* prev = &falseNext;
        while (head != nullptr) {
            ListNode* nex = head->next;
            while (nex != nullptr && nex->val == head->val) {
                nex = nex->next;
            }

            if (head->next == nex) {
                prev = head;
                head = nex;
            }
            else {
                prev->next = nex;
                while (head != nex) {
                    ListNode* buf = head->next;
                    delete head;
                    head = buf;
                }
            }
        }
        return falseNext.next;
    }
private:
    static const int mx = 201;
    static const int aligner = 100;
};

ListNode* createList(const std::vector<int>& value) {
    ListNode falseHead{ 0, nullptr };
    ListNode* lst = &falseHead;

    for (int e : value) {
        lst->next = new ListNode(e);
        lst = lst->next;
    }

    return falseHead.next;
}

std::vector<int> fromListToVector(ListNode * lst) {
    std::vector<int> v;
    while (lst != nullptr) {
        v.push_back(lst->val);
        ListNode* nex = lst->next;
        delete lst;
        lst = nex;
    }
    return v;
}

bool compareLists(ListNode const* lhs, ListNode const* rhs) {
    while (lhs != nullptr) {
        if (lhs->val != rhs->val) return false;
    }
    return (rhs == nullptr);
}

template<typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& vect) {
    o << "{";
    for (auto i = 0; i < vect.size(); ++i) {
        o << vect[i] << (i + 1 == vect.size() ? "" : ", ");
    }
    o << "}";
    return o;
}

void DoTest(const std::vector<int>& values, const std::vector<int>& checker) {
    Solution sol;
    auto result = fromListToVector(sol.deleteDuplicates(createList(values)));

    if (result != checker) {
        std::cerr << values << " FAILED " << checker << " expected, but " << result << " is given" << std::endl;
    }
}

void test() {
    DoTest({ 1, 2, 3, 3, 4, 4, 5 }, { 1, 2, 5 });
    DoTest({ 1, 1, 2, 2 }, {});
    DoTest({ 1, 1, 1, 2, 3, 3, 3 }, { 2 });
}

int main() {
    test();
    return 0;
}
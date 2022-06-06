/* this is such a raw version, I didn't pay attention on style and architecture, solution was copied from leetcode as is
 * origin problem: https://leetcode.com/problems/subtree-of-another-tree/
 * this problem is from the algorithm badge challenge
*/

 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root && subRoot) {
            return IsEqual(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        else {
            return !(root || subRoot);
        }
    }

private:
    bool IsEqual(TreeNode* root, TreeNode* subRoot) {
        if (root && subRoot) {
            return root->val == subRoot->val && IsEqual(root->left, subRoot->left) && IsEqual(root->right, subRoot->right);
        }
        else {
            return !(root || subRoot);
        }
    }
};
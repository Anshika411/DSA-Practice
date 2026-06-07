/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto& desc : descriptions) {

            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            TreeNode* p = mp[parent];
            TreeNode* c = mp[child];

            if (isLeft == 1) {
                p->left = c;
            } else {
                p->right = c;
            }

            children.insert(child);
        }

        for (auto& it : mp) {
            if (children.find(it.first) == children.end()) {
                return it.second;
            }
        }

        return nullptr;
    }
};
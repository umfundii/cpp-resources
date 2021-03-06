/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        
        if (root->left != NULL && root->right == NULL) {
            return 2;
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;   
    }
};


class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int h_left = 0;
        int h_right = 0;

        TreeNode *left = root;
        TreeNode *right = root;

        while(left != NULL) {
            h_left++;
            left = left->left;
        }

        while(right != NULL) {
            h_right++;
            right = right->right;
        }

        if (h_left == h_right) {
            return pow(2, h_left) - 1; 
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution3 {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;   
    }
};

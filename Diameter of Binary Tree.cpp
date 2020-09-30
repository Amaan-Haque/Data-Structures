int height(TreeNode* root) {
    if (h.count(root))
        return h[root];

    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int case1 = height(root->left) + height(root->right);
        int case2 = diameterOfBinaryTree(root->left);
        int case3 = diameterOfBinaryTree(root->right);

        return max({case1, case2, case3});
    }
};
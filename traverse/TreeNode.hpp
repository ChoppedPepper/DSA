struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
    TreeNode() = default;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr), parent(nullptr) { }
};
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
    TreeNode(int val, TreeNode *left, TreeNode *right)
        : val(val), left(left), right(right) {}
};

TreeNode *sortedArrayToBst(vector<int> a, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct TreeNode *root =
        (struct TreeNode *)malloc(sizeof(struct TreeNode *));
    root->left = sortedArrayToBst(a, start, mid - 1);
    root->right = sortedArrayToBst(a, mid + 1, end);
    root->val = a[mid];
    return root;
}
void preorder(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
    cout << endl;
}

int main() {
    vector<int> a;
    for (int i = 1; i <= 4; i++) a.push_back(i);
    TreeNode *root = sortedArrayToBst(a, 0, a.size() - 1);
    return 0;
    preorder(root);

    return 0;
}
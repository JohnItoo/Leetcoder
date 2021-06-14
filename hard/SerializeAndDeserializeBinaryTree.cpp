/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string response = "";
        map<TreeNode*, int> done;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (!front) {
                response.append("null,");
            } else {
                response.append(to_string(front->val));
                response.append(",");
                q.push(front->left);
                q.push(front->right);
            }
        }
        return response;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;
        int i = 0;
        string last = "";
        vector<string> input;
        while (i < data.size()) {
            if (data[i] == ',') {
                i++;
                input.push_back(last);
                last = "";
            } else {
                last.push_back(data[i++]);
            }
        }
        while (input[input.size() - 1] == "null") input.pop_back();

        i = 0;
        int n = input.size();
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(input[i++]));
        TreeNode* trav = root;
        q.push(trav);
        while (!q.empty() && i < input.size()) {
            TreeNode* front = q.front();
            q.pop();
            cout << front->val << " : " << i << endl;
            if (input[i] == "null") {
                front->left = NULL;
                i++;
            } else {
                TreeNode* left = new TreeNode(stoi(input[i++]));
                front->left = left;
                q.push(left);
            }

            if (i < input.size() && input[i] == "null") {
                front->right = NULL;
                i++;
            } else if (i < input.size() && input[i] != "null") {
                TreeNode* right = new TreeNode(stoi(input[i++]));
                front->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
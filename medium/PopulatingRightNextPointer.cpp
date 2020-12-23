/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *recursive(Node *root)
    {
        if (root == NULL)
            return root;

        if (root->left != NULL)
        {
            root->left->next = root->right;
        }
        if (root->right != NULL && root->next != NULL)
        {
            root->right->next = root->next->left;
        }
        recursive(root->left);
        recursive(root->right);
        return root;
    }
    Node *queues(Node *root)
    {
        Node *rootAns = root;
        queue<Node *> first;
        queue<Node *> second;

        if (root != NULL)
            first.push(root);

        while (!first.empty())
        {
            Node *prev = NULL;

            while (!first.empty())
            {
                Node *here = first.front();
                first.pop();
                second.push(here);
                if (prev == NULL)
                {
                    prev = here;
                }
                else
                {
                    prev->next = here;
                    prev = here;
                }
            }

            while (!second.empty())
            {
                Node *sec = second.front();
                second.pop();
                if (sec->left != NULL)
                {
                    first.push(sec->left);
                    first.push(sec->right);
                }
            }
        }
        return rootAns;
    }
    Node *connect(Node *root)
    {
        return recursive(root);
    }
};
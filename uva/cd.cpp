#include <iostream>

int count = 0;

struct Node {
    int value; Node *left, *right;
    Node() :
    value(-1), left(nullptr), right(nullptr)
    { }
    Node(int v) :
    value(v), left(nullptr), right(nullptr)
    { }
};

Node *insert(Node *root, int n)
{
    Node *prev = nullptr, *cur = root;
    while (cur != nullptr) {
        if (cur->value == n) {
            ++count;
            return root;
        }
        prev = cur;
        if (n > cur->value) cur = cur->right;
        else cur = cur -> left;
    }
    if (cur == nullptr) {
        Node *nn = new Node(n);
        if (prev == nullptr) root = nn;
        else if (n > prev->value) prev->right = nn;
        else prev->left = nn;
    }
    return root;
}

void inorder_traversal(Node *root)
{
    if (root != nullptr) {
        inorder_traversal(root->left);
        std::cout << root->value << " ";
        inorder_traversal(root->right);
    }
}

void cleanup_tree(Node *root)
{
    if (root != nullptr) {
        cleanup_tree(root->left);
        cleanup_tree(root->right);
        delete root;
    }
}

int main()
{
    int m, n;
    int a;
    while (std::cin >> std::ws >> m >> n && !(m == 0 && n == 0)) {
        Node *head = nullptr;
        for (int i = 1; i <= m+n; ++i) {
            std::cin >> a; head = insert(head, a);
        }
        std::cout << count << std::endl;
        cleanup_tree(head);
    }
    return(0);
}

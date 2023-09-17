#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
// #define int long long
// #define MAX 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// The root is BLACK
// Every leaf, is BLACK
// Children of a RED node is BLACK => Parent of a RED node is BLACK
// All the leaves have the same BLACK depth
// Every path from the root to descendant leaf node has the same number of BLACK nodes
// => Because of this, RED-BLACK tree is roughly balanced

// NOTES
// A RED node cannot have red parent or red child

// In RB Tree,
// Search is O logn
// Insert is O logn
// Delete is O logn

// When to use AVL Tree: Frequent searching, less frequent inserting and deleting
// When to use RB  Tree: Frequent inserting and deleting, less frequent searching

// Why?
// Because AVL Tree causes more rotations when mutating

enum {
    BLACK=0,
    RED
} Color;

struct {
    int value;
    Color color=RED;
    Node *left=nullptr, *right=nullptr, *parent=nullptr;

    explicit Node(int data) : value(data) {}
} Node;

struct {
    Node *root;

    // https://www.cs.auckland.ac.nz/software/AlgAnim/red_black.html
    void rotateLeft(Node *ptr) {
        Node *rightchild = ptr->child;
        ptr->right = rightchild->left;
        if (rightchild->left != nullptr) {
            rightchild->left->parent = ptr;
        }
        rightchild->parent = ptr->parent;
        if (ptr->parent == nullptr) root = rightchild;
        else {
            if (ptr == (ptr->parent)->left) {
                ptr->parent->left = rightchild;
            } else {
                ptr->parent->right = rightchild;
            }
        }
        rightchild->left = ptr;
        ptr->parent = rightchild;
    }

    void rotateRight(Node *p) {}

    Color getColor(Node *p) { return p->color; }

    void setColor(Node *node, int color)
    {
        if (node == nullptr) return;
        node->color = color;
    }

    // insert the tree from ptr to root
    Node *insertBST(Node *root, Node *ptr)
    {
        if (node == nullptr) return ptr;
        if (ptr->value < root->value) {
            root->left = insertBST(root->left, ptr);
            root->left->parent = root;
        } else if (ptr->value > root->data) {
            root->right = insertBST(root->right, ptr);
            root->right->parent = root;
        }

        return root;
    }

    RBTree() : root(nullptr) {}

    void insertVal(int val)
    {
        Node *node = new Node(n);
        root = insertBST(root, node);
        // after inserting, the tree will have to be readjusted
        fixInsertRBTree(node);
    }

    void fixInsertRBTree(Node *ptr)
    {
        Node *parent = nullptr;
        Node *grandparent = nullptr;
        // when there is 2 adjacent red nodes
        while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
            parent = ptr->parent;
            grandparent = parent->parent;
            if (parent == grandparent->left){
                Node *uncle = grandparent->right;
                if (getColor(uncle) == RED) {
                    setColor(uncle, BLACK);
                    setColor(parent, BLACK);
                    setColor(grandparent, RED);
                    ptr = grandparent;
                } else {
                    if (ptr == parent->right) {
                        rotateLeft(parent);
                        ptr = parent;
                        parent = ptr->parent;
                    }
                    rotateRight(grandparent);
                    swap(parent->color, grandparent->color);
                    ptr = parent;
                }
            } else {
            }
        }
        setColor(root, BLACK);
    }

    void deleteVal(int val) {}

    void inorderBST(Node *ptr)
    {
        if (ptr == nullptr) return;
        inorderBST(ptr->left);
        printf("Value: %d, Color: %s\n",
               ptr->value, (ptr->color == RED ? "RED" : "BLACK"));
        inorderBST(ptr->right);
    }
    void inOrder()
    {
        inorderBST(root);
    }

    void preOrderBST(Node *ptr)
    {
        if (ptr == nullptr) return;
        printf("Value: %d, Color: %s\n",
               ptr->value, (ptr->color == RED ? "RED" : "BLACK"));
        preOrderBST(ptr->left);
        preOrderBST(ptr->right);
    }
    void preOrder() { preOrderBST(root); }
} RBTree;

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    return 0;
}

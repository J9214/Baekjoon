#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class B_Tree{
private:
    Node* root;

    Node* insertNode(Node* node, int data){
        if(node == nullptr){
            return new Node(data);
        }

        if(data < node->data) node->left = insertNode(node->left, data);
        else node->right = insertNode(node->right, data);

        return node;
    }

    void inorderTraversal(Node* node){
        if(node == nullptr) return;

        inorderTraversal(node->left);
        cout << node->data << '\n';
        inorderTraversal(node->right);
    }

    void preTraversal(Node* node){
        if(node == nullptr) return;

        cout << node->data << '\n';
        preTraversal(node->left);
        preTraversal(node->right);
    }
    
    void postTraversal(Node* node){
        if(node == nullptr) return;

        postTraversal(node->left);
        postTraversal(node->right);
        cout << node->data << '\n';
    }
public:
    B_Tree() : root(nullptr){}

    void insert(int data){
        root = insertNode(root, data);
    }

    void inorder(){
        inorderTraversal(root);
    }

    void preorder(){
        preTraversal(root);
    }

    void postorder(){
        postTraversal(root);
    }
};


int main() {
    FASTIO

    B_Tree tree;

    int n;
    while(cin >> n){
        tree.insert(n);
    }
    
    tree.postorder();

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST{
    private:
    Node* root;

    // functions
    void insertion(Node* &root, int data){
        if (root==nullptr){
            root = new Node(data);
            return;
        }
        if(data<root->data){
            insertion(root->left, data);
        }else{
            insertion(root->right, data);
        }
    }

    void deletion(Node* root, int key){
        if(root->data==key){
            
        }
    }

    // Traversal
    void inOrderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    void preOrderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void postOrderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
    }
    void levelOrderTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        queue<Node*> q;
        q.push(root);
         
        while(!q.empty()){
            Node* current = q.front();
            cout<<current->data<<" ";
            q.pop();
            if(current->left!=nullptr){
                q.push(current->left);
            }
            if(current->right!=nullptr){
                q.push(current->right);
            }
        }
    }
    void levelOrderLineTraversal(Node* root){
        if(root==nullptr){
            return;
        }
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
         
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            if(current==nullptr){
                cout<<endl;
                if(!q.empty()){
                    q.push(nullptr);
                }
            }else{
                if(current->left!=nullptr){
                    q.push(current->left);
                }
                if(current->right!=nullptr){
                    q.push(current->right);
                }
                cout<<current->data<<" ";
            }
        }
    }

    public:
    BST(): root(nullptr) {}

    void insert(int data){
        insertion(root, data);
    }

    void inOrderTraversal(){
        inOrderTraversal(root);
        cout<<endl;
    }
    void preOrderTraversal(){
        preOrderTraversal(root);
        cout<<endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout<<endl;
    }
    void levelOrderTraversal(){
        levelOrderTraversal(root);
        cout<<endl;
    }
    void levelOrderLineTraversal(){
        levelOrderLineTraversal(root);
        cout<<endl;
    }
};
int main() {
    BST tree;

    tree.insert(10);
    tree.insert(7);
    tree.insert(14);
    tree.insert(5);
    tree.insert(9);
    tree.insert(2);
    tree.insert(16);
    tree.insert(6);
    tree.insert(8);

    tree.inOrderTraversal();
    tree.preOrderTraversal();
    tree.postOrderTraversal();
    tree.levelOrderTraversal();
    tree.levelOrderLineTraversal();

    return 0;
}
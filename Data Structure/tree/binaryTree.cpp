#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr), right(nullptr) {}
};

Node* createTree(){
    cout<<"enter element: ";
    int data;
    cin>>data;
    if(data==-1){
        return nullptr;
    }
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void levelOrderTraversal(Node* &root){
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
int main() {
    Node* root = createTree();

    levelOrderTraversal(root);

    return 0;
}
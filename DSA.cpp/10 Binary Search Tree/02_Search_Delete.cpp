
#include<bits/stdc++.h>
using namespace std;
//node og binary tree

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root,int val){
    if(root == NULL) return new Node(val);


    if(val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);

    return root;
}

//inorder
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

//search

Node* seaarchinBST(Node* root,int key){
    if(root == NULL || root->data == key) return root;

    if(key < root->data) return seaarchinBST(root->left, key);
    else return seaarchinBST(root->right, key);
}

//delete


Node* inordersucc(Node* root){
    while(root->left!= NULL) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int key){
    if(root == NULL) return root;

    if(key < root->data) root->left = deleteBST(root->left, key);
    else if(key > root->data) root->right = deleteBST(root->right, key);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}


int main(){
    Node* root = NULL;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    Node* searchNode = seaarchinBST(root, 20);
    if(searchNode!= NULL) cout << "Found: " << searchNode->data << endl;
    else cout << "Not Found" << endl;

    root = deleteBST(root, 70);
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    
return 0;
}
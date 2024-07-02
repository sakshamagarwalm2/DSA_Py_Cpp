//ek-ek level karke treverse karte hai
//ye ek queue ki help se treverse karte hai jaha har level ke bad ek null push kar denge jo bata dega ki level change hua hai


#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

void printLevelOrder(node* root){
    if (root == NULL)
    return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false)
    {
        node* temp = q.front();
        q.pop();
        if(temp !=NULL){
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else if (!q.empty()){
            cout << endl;
            q.push(NULL);
        }

    }

}

// find sum at k level 

int findSumAtKLevel(node* root, int k) {
    if (root == NULL) return 0;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    
    while (q.empty() == false) {
        node* temp = q.front();
        q.pop();
        if(temp != NULL){
            if (level == k) sum += temp->data;
            if (temp->left)
            q.push(temp->left);
            if (temp->right)
            q.push(temp->right);
            }
            else if (!q.empty()){
            cout << endl;
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int main(){


    // Create a binary tree with given nodes
    struct node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    /*
        1
       / \
      2   3 
     / \ / \
    4  5 7  6
    */
    
   root->left->left = new node(4);    
   root->left->right = new node(5);    
   root->right->left = new node(7);    
   root->right->right = new node(6);    

   cout << "Level order traversal of binary tree is \n";
   printLevelOrder(root);

   cout << "\nSum at 2nd level is: " << findSumAtKLevel(root, 2);
   
   

return 0;
}
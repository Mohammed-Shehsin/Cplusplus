#include <iostream.h>

using namespace std;
struct Node {               //Structure of Called node with elements Node-Left
    int data ;              // and Node-Right and integer element data
    Node*left;
    Node*right;
};

Node * createNode(int data){                         //Function for creating node
    Node* newNode = new Node();                      // step 1: create a New node
    newNode->data = data;                            // step 2: Set a data for the node
    newNode->left=newNode->right=nullptr;            // step 3: assigning Child node
        return newNode;                             // step 4: Return the reference to the node
}
void printTree(Node* root){                        // Function to print the value in tree (PREORDER)
    if (root==nullptr){
        return;
    }
    cout<<root->data<<endl;    //D                   //here we use "Preorder(data,left,right)"
    printTree(root->left);     //L
    printTree(root->right);    //R
}
void printTree_inorder(Node* root){                        // Function to print the value in tree (INORDER)
    if (root==nullptr){
        return;
    }
    printTree_inorder(root->left);     //L
    cout<<root->data<<endl;            //D                    //here we use "Inorder(left,dat,right)"
    printTree_inorder(root->right);    //R
}
void printTree_postorder(Node* root){                        // Function to print the value in tree (POSTORDER)
    if (root==nullptr){
        return;
    }
    printTree_postorder(root->left);     //L                          //here we use "Postordera(left,right,data)"
    printTree_postorder(root->right);    //R
    cout<<root->data<<endl;              //D
}
int main()
{
   //root
   Node* root=createNode(1);
   //Level 1
    root->left=createNode(2);
    root->right=createNode(3);
    //Level 2
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    //Level 3
    root->left->right->left=createNode(9);
    root->right->right->left=createNode(15);
    cout<<"Preorder :"<<endl;
    printTree(root);
    cout<<"Inorder :"<<endl;
    printTree_inorder(root);
    cout<<"Postorder :"<<endl;
    printTree_postorder(root);
    delete root;
    return 0;
}

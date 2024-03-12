#include<iostream>
using namespace std;

class Node{
  int data;
  Node *left,*right;
  public:
  Node(int data){
      this->data=data;
      this->left=left;
      this->right=right;
  }
  friend class BST;
};

class BST{
    private:
    Node *root;
    void Insert(int data,Node* node){
        if(data< node->data){
            if(node->left==NULL){
                node->left=new Node(data);
                cout<<"Inserted at left "<<endl;
            }
            else{
                Insert(data,node->left);
            }
        }
        else if(data >=node->data){
            if(node->right ==NULL){
                node->right=new Node(data);
                cout<<"Inserted at right "<<endl;
            }
            else{
                Insert(data,node->right);
            }
        }
    }
    bool Search(int data,Node *node){
        if(data==node->data){
            return true;
        }
        else if(data<node->data){
            return Search(data,node->left);
        }
        else if(data >node->data){
            return Search(data, node->right);
        }
        else{
            return false;
        }
    }
    
    void PrintInoder(Node *node){
        // cout<<"Inorder :";
        if(node==NULL){
            return ;
        }
        PrintInoder(node->left);
        cout<<node->data<<" ";
        PrintInoder(node->right);
    }
    void PrintPreorder(Node *node){
        if(node ==NULL){
            return ;
        }
        cout<<node->data<<" ";
        PrintPreorder(node->left);
        PrintPreorder(node->right);
    }
    void PrintPostorder(Node *node){
        if(node ==NULL){
            return ;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        cout<<node->data<<" ";
    }
    void max(Node* root){
        if(root==NULL){
            return ;
        }
        while(root->right!=NULL){
            root=root->right;
        }
        cout<<"Maximum ="<<root->data<<endl;
    }
    void min(Node *root){
        if(root==NULL){
            return ;
        }
        while(root->left!=NULL){
            root=root->left;
        }
        cout<<"Minimum ="<<root->data<<endl;
    }
    void Swap(Node *root){
        if(root==NULL){
            return ;
        }
        Swap(root->left);
        Swap(root->right);
        Node* temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    int Height(Node*root){
        int x=0;
        int y=0;
        if(root==NULL){
            return 0;
        }
        x=Height(root->left);
        y=Height(root->right);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    
    public:
    BST(){
        root=NULL;
    }
    void Insert(int data){
        if(root==NULL){
            root = new Node(data);
            cout<<"Insert as root "<<endl;
        }
        else{
            Insert(data,root);
        }
    }
    void Search(int key){
        Search(key,root);
    }
    void print(){
        cout<<"Inoreder: ";
        PrintInoder(root);
        cout<<endl;
        cout<<"Preoreder: ";
        PrintPreorder(root);
        cout<<endl;
        cout<<"Postorder: ";
        PrintPostorder(root);
        cout<<endl;
    }
    void max(){
        max(root);
    }
    void min(){
        min(root);
    }
    void swap(){
        Swap(root);
        cout<<"Swapped"<<endl;
    }
    void path(){
        cout<<"Longest path is "<<Height(root)<<endl;
        
    }
};
int main(){
    BST T;
    T.Insert(4);
    T.Insert(5);
    T.Insert(2);
    T.Insert(100);
    T.Insert(1);
    T.print();
    T.min();
    T.max();
    T.swap();
    T.print();
    T.Search(5);
    T.path();
    return 0;
}


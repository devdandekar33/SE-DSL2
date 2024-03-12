#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node *left;
    Node *right;
    friend class Tree;
    friend class Function;
    public:
    Node(){
        data=0;
        left=NULL;
        right=NULL;
    }
};

class Tree{
    private:
    Node * root;
    //make tree 
    Node * makeTree(){
        Node *temp;
        temp=new Node;
        cout<<"Enter the data :"<<endl;
        cin>>temp->data;
        char ch;
        cout<<"Do you want left child of "<<temp->data<<"(y/n)";
        cin>>ch;
        if(ch=='y'){
            temp->left=makeTree();
        }
        cout<<"Do you want right child of "<<temp->data<<"(y/n)";
        cin>>ch;
        if(ch=='y'){
            temp->right=makeTree();
        }
        return temp;
    }
    public:
    //tree constructor with root is null
    Tree(){
        root=NULL;
    }
    void create(){
        root=makeTree();
    }
    friend class Function;
};

class Function{
    private:
    int count=0;
    Tree T;
    void preorder(Node *root){
        if(root==NULL){
            return ;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
        
    }
    void inorder(Node *root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        
    }
    void postorder(Node *root){
        if(root==NULL){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    //creating a copy Function
    Node * Copy(Node* p){
        if(p==NULL){
            return p;
        }
        Node *root=new Node();
        root->data=p->data;
        root->left=Copy(p->left);
        root->right=Copy(p->right);
        return root;
    }
    
    int Height(Node* p){
        int x=0,y=0;
        if(p==NULL){
            return 0;
        }
        x=Height(p->left);
        y=Height(p->right);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    
    void No_leaves(Node *p){
        if(p==NULL){
            return ;
        }
        No_leaves(p->left);
        No_leaves(p->right);
        if(p->left==NULL && p->right==NULL){
            count +=1;
        }
    }
    
    void MirrorImage(Node *root){
        if(root==NULL){
            return ;
        }
        MirrorImage(root->left);
        MirrorImage(root->right);
        Node* temp;         //=new Node;insted of creating a new tree we are mirroring the same tree
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    
    void Deletetree(Node* root){
        if(root==NULL){
            return ;
        }
        Deletetree(root->left);
        Deletetree(root->right);
        delete root;
    }
    
    public:
    Function(){
        T.create(); //from the root=makeTree in Tree class
    }
    void get_Inorder(){
        cout<<"inorder  :";
        inorder(T.root);
        cout<<endl;
    }
    void get_Preorder(){
        cout<<"preorder :";
        preorder(T.root);
        cout<<endl;
    }
    void get_Postorder(){
        cout<<"postorder  :";
        postorder(T.root);
        cout<<endl;
    }
    //swapping the tree
    void swap_tree(){
		cout<<"Original Tree: "<<endl;;
		get_Inorder();
		MirrorImage(T.root);
		cout<<"New Tree: "<<endl;
     	get_Inorder();
	}
	void get_height() {
        cout << "Height of the Tree: " << Height(T.root) << endl;
    }
    //making a copy function
    void  get_copy(){
		Node * temp;
		temp=Copy(T.root);
		cout<<"Original Tree: ";
		inorder(T.root);
		cout<<endl;
		cout<<"New Tree: ";
     	inorder(temp);
		cout<<endl;
    }
    
    void get_Number_of_leafs() {
        No_leaves(T.root);
        cout << "Number of leafs: " << count << endl;
    }
    
    void Eraseall(){
        Deletetree(T.root);
        T.root=NULL;
        cout<<"Tree is deleted successfully"<<endl;
    }
};


int main(){
    cout<<"Enter the data to Create a tree"<<endl;
    Function F;
    cout<<"-----------MENU------------"<<endl;
    cout<<"1.Inorder Traversal"<<endl;
    cout<<"2.Preorder Traversal"<<endl;
    cout<<"3.Postnorder Traversal"<<endl;
    cout<<"4.Height"<<endl;
    cout<<"5.No of leafs"<<endl;
    cout<<"6.Copy "<<endl;
    cout<<"7.Swap Tree"<<endl;
    cout<<"8.Erase Tree"<<endl;
    cout<<"---------------------------"<<endl;
    
    char ch;
    ch='y';
    while(ch=='y'){
    	cout<<"Enter your Choice: ";
    	int choice;
    	cin>>choice;
    	if(choice==1){
    	    F.get_Inorder();
    	}
    	else if(choice==2){
    	     F.get_Preorder();
    	}
    	else if(choice==3){
    	    F.get_Postorder();
    	}
    	else if(choice==4){
    	    F.get_height();  
    	}
    	else if(choice==5){
    	    F.get_Number_of_leafs();
    	}
    	else if(choice==6){
    	    F.get_copy();
    	}
    	else if(choice==7){
    	    F.swap_tree();
    	}
    	else if(choice==8){
    	    F.Eraseall();
    	}
    	else{
    		cout<<"Invalid Input"<<endl;
    	}
        cout<<"---------------------------"<<endl;
    	cout<<"Do u want to continue (y/n) ?";
    	cin>>ch;
       }
    return 0;
}


 #include<iostream>
 using namespace std;

 class node{

 public: 
 	int data;
 	node* left;
 	node* right;

 	node(int d){
 		data=d;
 		right=NULL;
 		left=NULL;
 	}
 };

 node* create(){
 	int val;
 	node* root=NULL;
 	cout<<"Enter the value of the node : ";
 	cin>>val;
 	if(val==-1){
 		return NULL;
 	}
 	root=new node(val);
 	root->left=create();
 	root->right=create();
 	return root;
 
 }


 void preorder(node* root){
 	if(root!=NULL){
 		cout<<root->data<<"->";
 		preorder(root->left);
 		preorder(root->right);
 	}
 	
 }
 
 node *lca(node *root,int a,int b){
 	if(root==NULL){
 		return NULL;
 	}
 	if(root->data==a || root->data==b){
 		return root;
 	}

 	//Search in left and right subtrees
 	node* leftAns=lca(root->left,a,b);
 	node* rightAns=lca(root->right,a,b);

 	if(leftAns!= NULL && rightAns!=NULL){
 		return root;
 	}

 	if(leftAns!= NULL){
 		return leftAns;
 	}

 	return rightAns;


 }


 int main(){
 	node*root=create();
 	inorder(root);
 	node* lca=cla(root,5,10);
 }
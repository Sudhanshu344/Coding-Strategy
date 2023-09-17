#include <iostream>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* left, TreeNode* right){
    if (!left && !right) return true;
    if (!left || !right) return false;
    return ((left->val == right->val) && check(left->right, right->left) && check(left->left, right->right));
}


bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return check(root->left, root->right);
}


TreeNode* buildTree(){
    int val;
    cout << "Enter the root value (or -1 to exit): ";
    cin>>val;
    if(val == -1) return nullptr;
    TreeNode* root = new TreeNode(val);
    cout<<"Enter the left subtree of "<<val<<":"<<endl;
    root->left = buildTree();
    cout<<"Enter the right subtree of "<<val<<":"<<endl;
    root->right = buildTree();

    return root;
}


int main(){
    TreeNode* root = buildTree();

    cout<<isSymmetric(root);

    return 0;
    
}
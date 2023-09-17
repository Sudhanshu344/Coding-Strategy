#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int total(TreeNode* root, int curr){
    if (!root) return 0;

    curr = curr*10+root->val;
    if (!root->left && !root->right) return curr;

    return total(root->left, curr) +total(root->right, curr);
}

int sumNumbers(TreeNode* root) {
    return total(root, 0);
}



TreeNode* insertNodes(){
    int val;
    cout << "Enter the root value (or -1 to exit): ";
    cin >> val;
    if (val==-1) return nullptr;
    TreeNode* root = new TreeNode(val);
    cout<<"Enter the left subtree of "<<val<<":"<<endl;
    root->left = insertNodes();
    cout<<"Enter the right subtree of "<<val<<":"<<endl;
    root->right = insertNodes();

    return root;
}


int main(){
    TreeNode* root = insertNodes();

    cout<<sumNumbers(root);

    return 0;
}
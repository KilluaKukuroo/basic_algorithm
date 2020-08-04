#include<iostream>
using namespace std;

struct node {
    int value;
    node *left, *right;
};

class BTree {
private:
    int a;
public:
    node * root;
    BTree() {
        root = NULL;
    }
    void createBTree(int x);
    void createBTree(int x[], int len);
    void priororder(node * current);  //verify the construction of the tree
    void postorder(node * current); 
    void inorder(node * current);
    void layerorder(node * current);
};


void BTree::createBTree(int x) {
    node *newnode = new node();
    newnode->value = x;
    newnode->left = NULL, newnode->right = NULL;
    if(root == NULL) {
       root = newnode; 
    }
    else {
        node *current = root;
        node *back = current;
        while(current) {
            back = current;
            if(x <= current->value)
                current = current->left;
            else 
                current = current->right;
        }
        if(x < back->value) {
            back->left = newnode;
        } else {
            back->right = newnode;
        }
    }
}

void BTree::createBTree(int x[], int len) {
    for(int i=0; i<len; i++) {
        node * newnode = new node();
        newnode->value = x[i];
        newnode->left = NULL, newnode->right = NULL;
        if(root == NULL){
            root = newnode;
        } else {
            node *current = root;
            node *back = current;
            while(current) {
                back = current;
                if(newnode->value <= current->value) current = current->left;
                else current = current->right;
            }
            if(newnode->value <= back->value) back->left = newnode;
            else back->right = newnode;
        }
    }
}


void triverse(node * current) {
    cout << current->value << " ";
}

void BTree::priororder(node * current) {
    if(current != NULL) {
        triverse(current);
        priororder(current->left);
        priororder(current->right);
    }
    
}

void BTree::postorder(node * current) {
    if(current != NULL) {
        postorder(current->left);
        postorder(current->right);
        triverse(current);
    }
   
}

void BTree::inorder(node * current) {
    if(current != NULL) {
        inorder(current->left);
        triverse(current);
        inorder(current->right);
    }
}

#include<queue>
void BTree::layerorder(node * current) {
    //utilize queue
    queue<node*> q;
    if(current == NULL) return;
    q.push(current);
    while(!q.empty()) {
        node * treenode = q.front();
        triverse(treenode);
        q.pop();
        //q.pop();
        if(treenode->left != NULL) {
            q.push(treenode->left);
        }
        if(treenode->right != NULL) {
            q.push(treenode->right);
        }
    }
}

//print nodes by layer
#include<vector>
vector<vector<int>> layerorder(node * root) {
    queue<pair<node*, int>> q;  //<node*, level of the current node>
    vector<vector<int>> v;
    if(root == NULL) return vector<vector<int>>(); 
    q.push(make_pair(root, 0));
    

    while(!q.empty()) {
        node * current = q.front().first;
        int level = q.front().second;
        q.pop();
        if(level == v.size())   //create a vector for one layer of nodes
            v.push_back(vector<int> ());
        v[level].push_back(current->value);
        
        if(current->left != NULL) q.push(make_pair(current->left, level+1));
        if(current->right != NULL) q.push(make_pair(current->right, level+1));
    }
    return v;
}

void printvector(vector<vector<int>> v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
//function overloading
void printvector(vector<int> v) {
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    int a[] = {1,4,6,68,34,2};
    BTree tree = BTree();
    tree.createBTree(a, sizeof(a) / sizeof(a[0]));
    tree.priororder(tree.root);
    cout << endl;
    tree.postorder(tree.root);
    cout << endl;
    tree.inorder(tree.root);
    cout << endl;
    tree.layerorder(tree.root);
    cout << endl;
    vector<vector<int>> v = layerorder(tree.root);
    printvector(v);
    cout << endl;

    return 0;
}
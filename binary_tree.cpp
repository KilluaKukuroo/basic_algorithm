
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

struct tree {
    int val;
    tree *left, *right;
    
    //tree(int x) 
};


/*
func : a binary search tree;
reference : https://blog.csdn.net/hongkangwl/article/details/21697641
*/
class Btree {
    static int n;
    static int m;
public:
    tree *root;
    Btree() {
        root = NULL;
    }
    //create btree with an integer
    void createBtree(int x);
    void createBtree(int x[]);
    void deleteNode(int x);
    void deleteBtree(tree * p);
    void preorder(tree * p);
    void inorder(tree * p);
    void postorder(tree * p);
    
    int count(tree * p);
    int countLeaf(tree * p);
    int countDegreeOne(tree * p);
    int countDegreeTwo(tree * p);
    int treeHeight(tree *p); //DFS1 , resursive
    int treeHeight2(tree *p); //DFS 2
    int treeHeight3(tree *p); //BFS
    int calWayToLeaf(tree *p); //calculate how many ways could reach the leafs


    void destroyBTree(tree *p);
    void insertNode(tree *p, tree *node);

};
//class static variable is not bound to any object but bount to the class;
// so the initialization should be out of the class;
int Btree::n = 0;
int Btree::m = 0;

void Btree::createBtree(int x) {
    tree *newnode = new tree();
    newnode->val = x;
    newnode->left = newnode->right = NULL;
    if(root == NULL) {
        root = newnode;
    }
    else {
        tree *current = root;
        tree *back;
        while(current != NULL) {
            back = current;
            if(current->val > x) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if(back->val > x) {
            back->left = newnode;
        } else {
            back->right = newnode;
        }
    }
}

void Btree::createBtree(int x[]) {

}

int Btree::count(tree * p) {
    if(p == NULL){
        return 0;
    } else {
        return count(p->left) + count(p->right) + 1;
    }
}

//preorder traverse binary tree
void Btree::preorder(tree * p){
    if(p==NULL){
        return;
    } else{
        printf("%d ", p->val);
        preorder(p->left);
        preorder(p->right);
    }
}

//inorder traver the binary tree
void Btree::inorder(tree *p) {
    if(p==NULL){
        return;
    } else {
        inorder(p->left);
        printf("%d ", p->val);
        inorder(p->right);
    }
}

//post order traver the binary tree
void Btree::postorder(tree *p) {
    if(p == NULL) {
        return;
    } else {
        postorder(p->left);
        postorder(p->right);
        printf("%d ", p->val);
    }
}

int Btree::countLeaf(tree *p) {
    if(p == NULL) {
        return 0;
    } else {
        if(p->left == NULL and p->right == NULL) {n += 1;}
        else {
            countLeaf(p->left);
            countLeaf(p->right);
        }
        return n;
    }
}
//count the number of nodes which degree is equal to 1
int Btree::countDegreeOne(tree *p) {
    if(p == NULL) {
        return 0;
    } else {
        if(p->left == NULL && p->right == NULL) {return 0;}
        else if (p->left == NULL && p->right != NULL) {
            m += 1;
            countDegreeOne(p->right);
        } else if(p->left != NULL && p->right == NULL) {
            m += 1;
            countDegreeOne(p->left);
        } else {
            countDegreeOne(p->left);
            countDegreeOne(p->right);
        }
        return m;
    }
}

//count the number of nodes with two child
int Btree::countDegreeTwo(tree * p) {
    if(p == NULL) {
        return 0;
    } else {
        if(p->left != NULL && p->right != NULL) {
            return countDegreeTwo(p->left) + countDegreeTwo(p->right) + 1;
            //countDegreeTwo(p->left, number);
            //countDegreeTwo(p->right, number);
        } else if(p->left != NULL && p->right == NULL) {
            return countDegreeTwo(p->left);
        } else if(p->left == NULL && p->right != NULL) {
            return countDegreeTwo(p->right);
        } else {
            return 0;
        }
        //return number;
    }
}

//calculate the height of a binary tree; deep first search
int Btree::treeHeight(tree *p) {
    /*
    if(p == NULL) {
        return 0;
    } else {
        tree *temp = p;
        while(temp != NULL) {

        }
        return  treeHeight(p->left) + treeHeight(p->right) + 1;
    }
    */
    return p==NULL ? 0 : max(treeHeight(p->left), treeHeight(p->right)) + 1;
}

//another method to calculate the height of a tree, using stack; deep first search
int Btree::treeHeight2(tree *p) {
    if(p == NULL) {return 0;}
    else {
        tree * record = NULL;
        tree *ptr = p;
        int height = 0;
        stack<tree*> s;
        while(ptr || !s.empty()) {
            if(ptr != NULL) {
                s.push(ptr);
                ptr = ptr->left;
            } else {
                ptr = s.top();
                if(ptr->right!=NULL && ptr->right != record) {
                    ptr = ptr->right;
                } else {
                    if(s.size() > height) {
                        height = s.size();
                    }
                    record = ptr;   //the latest looked node stored in r
                    s.pop();
                    ptr = NULL;
                }
            }
        }
        return height;
    }
}

//BFS : broad first search, using queue;
int Btree::treeHeight3(tree *p) {
    if(p == NULL) {return 0;}
    else {
        int height = 0;
        queue<tree *> q;
        tree *ptr = p;
        q.push(ptr);
        while(!q.empty()) {
            height += 1;
            for(int i=0, n=q.size(); i<n; i++) {
                ptr = q.front();
                q.pop();
                if(ptr->left != NULL) {
                    q.push(ptr->left);
                }
                if(ptr->right != NULL) {
                    q.push(ptr->right);
                }
            }
        }

        return height;
    }
}


//calculate how many ways to reach leaf node, utilizing DFS with a stack;
int Btree::calWayToLeaf(tree * p) {
    if(p == NULL) {return 0;}
    else {
        stack<tree *> s;
        tree *ptr = p;
        tree *record = NULL;
        int way = 0;
        while(ptr!=NULL || !s.empty()) {
            if(ptr != NULL) {
                s.push(ptr);
                ptr = ptr->left;
            } else {
                ptr = s.top();
                if(ptr->right != NULL && record!=ptr->right) {
                    ptr = ptr->right;
                } else {
                    if(ptr->left == NULL && ptr->right==NULL) {
                        way += 1;
                    }
                    record = s.top();
                    s.pop();
                    ptr = NULL;
                }
            }
        }
        return way;
    }
}

/*
func: destroy a binary tree
*/
void Btree::destroyBTree(tree *p) {
    if(p == NULL) return;
    else {
        if(p->left == NULL && p->right == NULL) {
            delete(p);
            return;
        } else if(p->left == NULL && p->right != NULL) {
            destroyBTree(p->right);
        } else if(p->left != NULL && p->right == NULL) {
            destroyBTree(p->left);
        } else{
            destroyBTree(p->left);
            destroyBTree(p->right);
        }
    }
}



/*
problems: create Btree with different order of a same array of integers, the tree is the same?
*/

int main() {
    int a[] = {100,4,2,3,15,35,6,45,55,20,1,14,56,57,58};
    Btree Apple;
    int length = sizeof(a) / sizeof(a[0]);
    //create a binary tree
    cout << "create a binary tree" << endl;
    for(int i=0; i<length; i++) {
        cout << a[i] << " ";
        Apple.createBtree(a[i]);
    }
    cout << endl;

    cout << "the number of leaf in the tree : " << Apple.countLeaf(Apple.root) << endl;
    cout << "the number of nodes with degree equal to 1 : " << Apple.countDegreeOne(Apple.root) << endl;
    cout << "the number of all the nodes = " << Apple.count(Apple.root) << endl;
    cout << "preorder traverse the tree : " << endl;
    Apple.preorder(Apple.root);
    cout << endl << "inorder traverse the tree " << endl;
    Apple.inorder(Apple.root);
    cout << endl << "postorder traverse the tree" << endl;
    Apple.postorder(Apple.root);
    cout << endl;

    cout << "the number of nodes with degree equal to 2 : " << Apple.countDegreeTwo(Apple.root) << endl;

    cout << "the height of the binary tree is = " << Apple.treeHeight(Apple.root) << endl;
    cout << "the height2 of the binary tree is = " << Apple.treeHeight2(Apple.root) << endl;
    cout << "the height3 of the binary tree is = " << Apple.treeHeight3(Apple.root) << endl;

    cout << "the number of ways to leaf :  " << Apple.calWayToLeaf(Apple.root) << endl;


    cout << "=====================================" << endl;
    cout << "the size of tree is = " << sizeof(Apple) << "sizeof Apple.root = " << sizeof(Apple.root) << endl;
    //delete(Apple.root);
    //cout << "sizeof a null tree node = " << sizeof(tree()) << " after free Apple.root = " << sizeof(Apple.root) << endl;

    Apple.destroyBTree(Apple.root);
    cout << "the size of tree is = " << sizeof(Apple) << "sizeof Apple.root = " << sizeof(Apple.root) << endl;
    cout << "the height of the binary tree is = " << Apple.treeHeight(Apple.root) << endl;
    cout << "the height2 of the binary tree is = " << Apple.treeHeight2(Apple.root) << endl;
    cout << "the height3 of the binary tree is = " << Apple.treeHeight3(Apple.root) << endl;


    return 0;
}
#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node(int item) {
            key = item;
            left = right = NULL;
        }
};

Node* search(Node* root,int key) {
    if(root == NULL || root->key == key) {
        return root;
    }
    if(key < root->key) {
        return search(root->left,key);
    }

    return search(root->right,key);
}

Node* findMin(Node* root) {
    while(root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* insert(Node* root,int key) {
    if(root == NULL) {
        return new Node(key);
    }

    if(key < root->key) {
        root->left = insert(root->left,key);
    } else if(key > root->key) {
        root->right = insert(root->right,key);
    }

    return root;
}

Node* deleteNode(Node* root,int key) {
    if(root == NULL) {
        cout << "Empty Tree" << endl;
        return root;
    }

    if(key < root->key) {
        root->left = deleteNode(root->left,key);
    } else if(key > root->key) {
        root->right = deleteNode(root->right,key);
    } else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        } else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

void DFT(Node *root) {
    if(root == NULL) {
        return;
    }
    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        int n = st.size();
        for(int i = 0 ; i < n ; i++) {
            Node* current = st.top(); st.pop();
            cout << current->key << ",";
            if(current->right) {
                st.push(current->right);
            }
            if(current->left) {
                st.push(current->left);
            }
        }
        cout << "|";
    }
    cout << endl;
}

void BFT(Node *root) {
    if(root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0 ; i < n ; i++) {
            Node* current = q.front(); q.pop();
            cout << current->key << ",";
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
        cout << "|";
    }
    cout << endl;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->key << ",";
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->key << ",";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->key << ",";
}

int main() {
    Node* root = NULL;
    char ch;

    while(true) {
        cin >> ch;
        if(ch == 'a') {
            int num;
            cin >> num;
            root = insert(root,num);
        } else if(ch == 'i') {
            inorder(root);
            cout << endl;
        } else if(ch == 'p') {
            preorder(root);
            cout << endl;
        } else if(ch == 't') {
            postorder(root);
            cout << endl;
        } else if(ch == 'x') {
            break;
        } else if(ch == 'b') {
            BFT(root);
        } else if(ch == 'd') {
            int num;
            cin >> num;
            root = deleteNode(root,num);
        }
    }

    return 0;
}
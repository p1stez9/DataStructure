#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height; 

    Node(int item) {
        key = item;
        left = right = NULL;
        height = 1;
    }
};

int height(Node* node) {
    if (node == NULL) {
    	return 0;	
	}
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL) {
    	return 0;	
	}
    return height(node->left) - height(node->right);
}


Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    
    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    
    return x;
}


Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert a node in AVL tree
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else  
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    // LL
    if (balance > 1 && key < node->left->key){
    	return rightRotate(node);
	}
    
    // RR
    if (balance < -1 && key > node->right->key){
    	return leftRotate(node);
	}

	// LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    
    return node;
}


Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // case 1 ไม่มีลูก
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // case 2 มีลูกแค่ตัวเดียว
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case 3 ไม่มีเลยย
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0){
    	return rightRotate(root);
	}

    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0){
    	return leftRotate(root);
	}

    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = NULL;
    char inp;
    int data;

    while (true) {
        cin >> inp;

        if (inp == 'a') {
            cin >> data;
            root = insert(root, data);
        } else if (inp == 'd') {
            cin >> data;
            root = deleteNode(root, data);
        } else if (inp == 'p') {
            preorder(root);
            cout << endl;
        } else if (inp == 'x') {
            break;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int key;
        Node* left;
        Node* right;
        Node(int item) {
            key = item;
            left = NULL;
            right = NULL;
        }
};

Node* search(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

Node* findMin(Node* root) {
    while(root && root->left != NULL) {
        root = root->left; // การจะหา min มันจะอยู่ฝั่งซ้ายเสมอ
    }
    return root;
}


Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key); // สร้าง node ใหม่ไปเลย
    }

    if (key < root->key) {
        root->left = insert(root->left, key); // ใส่ค่าเข้าปายยยย ทางซ้ายนะ
    } else if (key > root->key) {
        root->right = insert(root->right, key);// ใส่ค่าเข้าปายยยย ทางขวาา
    }

    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        cout << "Empty Tree" << endl;
        return root;
    }

    // ลบๆๆๆๆๆๆ
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // case 1 ไม่มีลูก
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return root;
        } else if (root->left == NULL) { // case 2 ลูก 1
            Node* temp = root->right; // เก็บตัวขวาา
            delete root; // ลบ root ที่เป็น root ของตัวขวาออก
            return temp; //เอา root ตัวขวามาแทนที่
        } else if (root->right == NULL) { // แบบ เก็บตัวซ้าย
            Node *temp = root->left;
            delete root;
            return temp;
        } else {
            Node *temp = findMin(root->right); // จะหาตัวที่น้อยจากด้านขวา ถ้าหาด้านซ้ายมันก็เจอเลย
            root->key = temp->key; // โยกค่ามาไว้ตรง root
            root->right = deleteNode(root->right, temp->key); // ก็แค่ไปลบตัวที่เราเจอมา
        }
    }
    return root;
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
    Node *root = NULL;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 150);
    root = insert(root, 300);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    deleteNode(root, 50);
    preorder(root);
    cout << endl;
    cout << findMin(root)->key << endl;
}
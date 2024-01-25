#include <iostream>

usign namespace std;

template <typename T>
class Node {
public:
    T value;
    Node* left;
    Node* right;

    Node(T value): value(value), left(nullptr), right(nullptr) {}
};


void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
}


template <typename T>
void printTree(Node<T>* node, int level = 0) {
    if (node == nullptr) {
        return;
    }
    
    printTree(node->right, level + 1);
    
    printIndent(level);
    cout << node->value << endl;
    
    printTree(node->left, level + 1);
}


template <typename T>
Node<T>* insertNode(Node<T>* node, T value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }
    
    if (value < node->value) {
        node->left = insertNode(node->left, value);
    } else if (value > node->value) {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}

template <typename T>
Node<T>* deleteNode(Node<T>* node, T value) {
    if (node == nullptr) {
        return node;
    }
    
    if (value < node->value) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->value) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node<T>* temp = node->left;
            delete node;
            return temp;
        }
        
        Node<T>* minValueNode = node->right;
        while (minValueNode->left != nullptr) {
            minValueNode = minValueNode->left;
        }
        
        node->value = minValueNode->value;
        node->right = deleteNode(node->right, minValueNode->value);
    }
    
    return node;
}

int main() {
    setlocale(LC_ALL, "Ru")
    Node<int>* root = nullptr;
    
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);
    
    
    cout << "Дерево до удаления вершины:" << endl;
    printTree(root);
    
   
    int valueToRemove = 5;
    root = deleteNode(root, valueToRemove);
    cout << "Дерево после удаления вершины " << valueToRemove << ":" << endl;
    printTree(root);
    
    return 0;
}

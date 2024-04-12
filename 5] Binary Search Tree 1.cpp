#include <iostream>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    Node* insertRecursive(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorderTraversalRecursive(Node* root) {
        if (root != nullptr) {
            inorderTraversalRecursive(root->left);
            std::cout << root->data << " ";
            inorderTraversalRecursive(root->right);
        }
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
        std::cout << std::endl;
    }

    Node* searchRecursive(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return searchRecursive(root->left, value);
        } else {
            return searchRecursive(root->right, value);
        }
    }

    Node* search(int value) {
        return searchRecursive(root, value);
    }

    Node* findMinValueNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNodeRecursive(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNodeRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNodeRecursive(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNodeRecursive(root->right, temp->data);
        }

        return root;
    }

    void deleteNode(int value) {
        root = deleteNodeRecursive(root, value);
    }

    int maxDepthRecursive(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepthRecursive(root->left);
        int rightDepth = maxDepthRecursive(root->right);

        return std::max(leftDepth, rightDepth) + 1;
    }

    int maxDepth() {
        return maxDepthRecursive(root);
    }

    Node* mirrorImageRecursive(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* temp = root->left;
        root->left = mirrorImageRecursive(root->right);
        root->right = mirrorImageRecursive(temp);

        return root;
    }

    void displayMirrorImage() {
        root = mirrorImageRecursive(root);
        inorderTraversal();
    }

    Node* copyTreeRecursive(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(root->data);
        newNode->left = copyTreeRecursive(root->left);
        newNode->right = copyTreeRecursive(root->right);

        return newNode;
    }

    BinarySearchTree copyTree() {
        BinarySearchTree copiedTree;
        copiedTree.root = copyTreeRecursive(root);
        return copiedTree;
    }

    void displayParentChildNodesRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }

        std::cout << "Parent: " << root->data << " - ";
        if (root->left != nullptr) {
            std::cout << "Left Child: " << root->left->data << " ";
        }
        if (root->right != nullptr) {
            std::cout << "Right Child: " << root->right->data << " ";
        }
        std::cout << std::endl;

        displayParentChildNodesRecursive(root->left);
        displayParentChildNodesRecursive(root->right);
    }

    void displayParentChildNodes() {
        displayParentChildNodesRecursive(root);
    }

    void displayLeafNodesRecursive(Node* root) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            std::cout << root->data << " ";
        }

        displayLeafNodesRecursive(root->left);
        displayLeafNodesRecursive(root->right);
    }

    void displayLeafNodes() {
        displayLeafNodesRecursive(root);
        std::cout << std::endl;
    }

    void displayLevelWise() {
        if (root == nullptr) {
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; ++i) {
                Node* current = q.front();
                q.pop();

                std::cout << current->data << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    int searchValue = 40;
    Node* searchResult = bst.search(searchValue);
    if (searchResult != nullptr) {
        std::cout << "Node with value " << searchValue << " found." << std::endl;
    } else {
        std::cout << "Node with value " << searchValue << " not found." << std::endl;
    }

    int deleteValue = 30;
    std::cout << "Deleting node with value " << deleteValue << std::endl;
    bst.deleteNode(deleteValue);
    std::cout << "Inorder Traversal after deletion: ";
    bst.inorderTraversal();

    std::cout << "Depth of the tree: " << bst.maxDepth() << std::endl;

    std::cout << "Mirror Image: ";
    bst.displayMirrorImage();

    BinarySearchTree copiedTree = bst.copyTree();
    std::cout << "Copied Tree: ";
    copiedTree.inorderTraversal();

    std::cout << "Parent and Child Nodes: " << std::endl;
    bst.displayParentChildNodes();

    std::cout << "Leaf Nodes: ";
    bst.displayLeafNodes();

    std::cout << "Level-wise Display: " << std::endl;
    bst.displayLevelWise();

    return 0;
}

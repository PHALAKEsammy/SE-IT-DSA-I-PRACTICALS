#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            Node* newNode = new Node{data, nullptr, nullptr};
            return newNode;
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
        // Ignore duplicate entries

        return root;
    }

    

    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    Node* deleteNode(Node* root, int data) {
        if (root == nullptr) {
            return root;
        }

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
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

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node* search(Node* root, int data) {
        if (root == nullptr || root->data == data) {
            return root;
        }

        if (data < root->data) {
            return search(root->left, data);
        }

        return search(root->right, data);
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }

    Node* mirrorImage(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* temp = root->left;
        root->left = mirrorImage(root->right);
        root->right = mirrorImage(temp);

        return root;
    }

    Node* copyTree(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node{root->data, nullptr, nullptr};
        newNode->left = copyTree(root->left);
        newNode->right = copyTree(root->right);

        return newNode;
    }

    void displayParentsAndChildren(Node* root) {
        if (root != nullptr) {
            if (root->left != nullptr || root->right != nullptr) {
                cout << "Parent: " << root->data << " - Children: ";
                if (root->left != nullptr) {
                    cout << root->left->data << " ";
                }
                if (root->right != nullptr) {
                    cout << root->right->data << " ";
                }
                cout << endl;
            }
            displayParentsAndChildren(root->left);
            displayParentsAndChildren(root->right);
        }
    }

    void displayLeafNodes(Node* root) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr) {
                cout << root->data << " ";
            }
            displayLeafNodes(root->left);
            displayLeafNodes(root->right);
        }
    }

    void displayLevelWise(Node* root, int level) {
        if (root == nullptr) {
            return;
        }
        if (level == 1) {
            cout << root->data << " ";
        } else if (level > 1) {
            displayLevelWise(root->left, level - 1);
            displayLevelWise(root->right, level - 1);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int data) {
        root = insert(root, data);
    }

    void deleteNode(int data) {
        root = deleteNode(root, data);
    }

    Node* search(int data) {
        return search(root, data);
    }

    void displayTree() {
        inorderTraversal(root);
        cout << endl;
    }

    int getDepth() {
        return maxDepth(root);
    }

    void displayMirrorImage() {
        root = mirrorImage(root);
        displayTree();
        // Restore original tree after displaying mirror image
        root = mirrorImage(root);
    }

    BST copyTree() {
        BST copiedTree;
        copiedTree.root = copyTree(root);
        return copiedTree;
    }

    void displayParentsAndChildren() {
        displayParentsAndChildren(root);
    }

    void displayLeafNodes() {
        displayLeafNodes(root);
        cout << endl;
    }

    void displayLevelWise() {
        int depth = getDepth();
        for (int i = 1; i <= depth; i++) {
            displayLevelWise(root, i);
            cout << endl;
        }
    }
};

int main() {
    BST tree;

    

    
    

    while (true) {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. Search node\n";
        cout << "4. Display original tree\n";
        cout << "5. Display depth of the tree\n";
        cout << "6. Display mirror image\n";
        cout << "7. Display copied tree\n";
        cout << "8. Display parents and children\n";
        cout << "9. Display leaf nodes\n";
        cout << "10. Display tree level wise\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                int insertValue;
                cin >> insertValue;
                tree.insert(insertValue);
                break;

            case 2:
                cout << "Enter value to delete: ";
                int deleteValue;
                cin >> deleteValue;
                tree.deleteNode(deleteValue);
                break;

            case 3:
                cout << "Enter value to search: ";
                int searchValue;
                cin >> searchValue;
                if (tree.search(searchValue) != nullptr) {
                    cout << "Node " << searchValue << " found!" << endl;
                } else {
                    cout << "Node " << searchValue << " not found!" << endl;
                }
                break;

            case 4:
                cout << "Original Tree: ";
                tree.displayTree();
                break;

            case 5:
                cout << "Depth of the tree: " << tree.getDepth() << endl;
                break;

            case 6:
                cout << "Mirror Image of the Tree: ";
                tree.displayMirrorImage();
                break;

            case 7:
                cout << "Copied Tree: ";
                tree.copyTree().displayTree();
                break;

            case 8:
                cout << "Parents and Children: " << endl;
                tree.displayParentsAndChildren();
                break;

            case 9:
                cout << "Leaf Nodes: ";
                tree.displayLeafNodes();
                cout << endl;
                break;

            case 10:
                cout << "Tree Level Wise: " << endl;
                tree.displayLevelWise();
                break;

            case 0:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

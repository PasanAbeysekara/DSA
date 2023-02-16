#include <iostream>
using namespace std;

class Node {
public:
    int key;  
    Node* parent;
    Node* left;
    Node* right;

    Node() {
        key = -1;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    Node(int val) {
        key = val;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;
    int size;

public:
    BST() {
        root = NULL;
        size = 0;
    }

    void insert(int val) {

        Node* temp = new Node(val);

        Node* current = root;
        Node* previous = NULL;

        while (current != NULL)
        {
            previous = current;

            if (val > current->key)
            {
                current = current->right;
            }
            else if (val < current->key)
            {
                current = current->left;
            }
            else  
            {
                cout << "Duplicate Node" << endl;
                return;  
            }
        }

        if (previous == NULL)  //If tree is empty
        {
            root = temp;
        }
        else if (val > previous->key)
        {
            previous->right = temp;
            temp->parent = previous;
        }
        else if (val < previous->key)
        {
            previous->left = temp;
            temp->parent = previous;
        }

        size++;
    }

    bool search(int val) {

        if (root == NULL)  //If tree is empty
        {
            cout << "Tree is empty" << endl;
            return false;
        }
        else
        {
            Node* current = root;

            while (current != NULL)
            {

                if (val > current->key)
                {
                    current = current->right;
                }
                else if (val < current->key)
                {
                    current = current->left;
                }
                else  
                {
                    cout << "Node is found - " <<val<< endl;
                    return true;  
                }
            }
            return false;
        }
        
    }

    /*
    //Traverse
            
              A
           /    \
         B        C 
          \      /  \
           D   E      F
              /      /  \
             G      H    I

Breadth First Traversal (Level order)
    A B C D E F G H I

Depth First Traversal

    In order: Left [Root] Right - B D A G E C H F I  
    pre Order: [Root] Left Right - A B D C E G F H I
    Post Order: Left Right [Root] - D B G E H I F C A 

    */

    void pre_order(Node* node) {
        if (node != NULL) {
            cout << "Node: " << node->key << endl;
            pre_order(node->left);
            pre_order(node->right);

        }
    }

    void in_order(Node* node) {
        if (node != NULL) {
            in_order(node->left);
            cout << "Node: " << node->key << endl;
            in_order(node->right);

        }
    }

    void post_order(Node* node) {
        if (node != NULL) {
            post_order(node->left);
            post_order(node->right);
            cout << "Node: " << node->key << endl;
        }
    }

    void traverse(int n) {
        switch (n) {
        case 0: pre_order(root); break;
        case 1: in_order(root); break;
        case 2: post_order(root); break;
        }
    }
};

int main()
{
    BST tree;
    tree.insert(80);
    tree.insert(70);
    tree.insert(60);
    tree.insert(95);

    /*
                80
               /  \
              70   95
             / 
           60
    */
    //Find a print function

    tree.search(20);
    tree.search(70);
    tree.search(95);

    cout <<"\nPre-order" << endl;
    tree.traverse(0); 
    
    cout << "\nIn-order" << endl;
    tree.traverse(1); 
    
    cout << "\nPost-order" << endl;
    tree.traverse(2);
    return 0;

}


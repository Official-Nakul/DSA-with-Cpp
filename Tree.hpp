#ifndef Tree_hpp
#define Tree_hpp

#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Tree
{
private:
    void Populate(Node *node)
    {
        bool left;
        cout << "Do you want to enter the left of " << node->data << ": ";
        cin >> left;
        if (left)
        {
            int data;
            cout << "Enter the value to be inserted: ";
            cin >> data;
            node->left = new Node(data);
            Populate(node->left);
        }
        bool right;
        cout << "Do you want to enter the right of " << node->data << ": ";
        cin >> right;
        if (right)
        {
            int data;
            cout << "Enter the value to be inserted: ";
            cin >> data;
            node->right = new Node(data);
            Populate(node->right);
        }
    }

public:
    int idx = -1;
    Node *buildPreOrder(int num[])
    {
        idx++;
        if (num[idx] == -1)
        {
            return NULL;
        }
        Node *node = new Node(num[idx]);
        node->left = buildPreOrder(num);
        node->right = buildPreOrder(num);
        return node;
    }
    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
    Node *Populate()
    {
        int data;
        cout << "Enter the value of root Node: ";
        cin >> data;
        Node *root = new Node(data);
        Populate(root);
        return root;
    }
};

#endif
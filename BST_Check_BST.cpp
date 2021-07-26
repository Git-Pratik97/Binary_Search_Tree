#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool is_BST(Node* root, Node* min = NULL, Node* max = NULL)
{
    if(root == NULL)
    {
        return true;
    }

    if (min!= NULL && min->data >= root->data)
    {
        return false;
    }

    if(max != NULL && max->data <= root->data)
    {
        return false;
    }

    bool left_valid = is_BST(root->left, min, root);
    bool right_valid = is_BST(root->right, root, max);

    return left_valid && right_valid;
}

int main()
{
    Node* root_1 = new Node(1);
    root_1->left = new Node(2);
    root_1->right = new Node(3);

    if(is_BST(root_1, NULL, NULL))
    {
        cout << "BST is Valid" << endl;
    }
    else
    {
        cout << "BST is invald" <<endl;
    }

    Node* root_2 = new Node(5);
    root_2->left = new Node(3);
    root_2->right = new Node(6);

    if(is_BST(root_2, NULL, NULL))
    {
        cout << "BST is Valid" << endl;
    }
    else
    {
        cout << "BST is invald" <<endl;
    }
    return 0;
}
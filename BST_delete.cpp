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

Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node* delete_inBST(Node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = delete_inBST(root->left, key);
    }
    
    else if(key > root->data)
    {
        root->right = delete_inBST(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = delete_inBST(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    inorder(root);
    cout << endl;
    Node* node = delete_inBST(root, 2);
    inorder(node);

    return 0;
}
#include<bits/stdc++.h>
#include<iostream>

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

Node* construct_bst(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node* root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;
    }

    if (*preorderIdx < n)
    {
        root->left = construct_bst(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
    }

    if (*preorderIdx < n)
    {
        root->right = construct_bst(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
    }

    return root;
}

void print_preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;

    Node* root = construct_bst(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);

    print_preorder(root);

    return 0;


}
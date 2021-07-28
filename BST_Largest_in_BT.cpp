#include<bits/stdc++.h>
#include<climits>

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
        right= NULL;
    }
};

struct Info 
{
    int size;
    int min;
    int max;
    int ans;
    bool is_BST;
    
};

Info largest_BST(Node* root)
{
    if(root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }

    if(root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largest_BST(root->left);
    Info rightInfo = largest_BST(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.is_BST && rightInfo.is_BST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min , min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max (leftInfo.max , root->data));

        curr.ans = curr.size;
        curr.is_BST = true;


        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.is_BST = false;

    return curr;
}

int main()
{
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << "The largest BTS occured is: " << largest_BST(root).ans <<endl;
    return 0;
}
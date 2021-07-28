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

bool is_identical(Node* root_1, Node* root_2)
{
    if (root_1 == NULL && root_2 == NULL)
    {
        return true;
    }

    else if (root_1 == NULL || root_2 == NULL)
    {
        return false;
    }

    else
    {
        bool cond_1 = root_1->data == root_2->data;        
        bool cond_2 = is_identical(root_1->left, root_2->left);
        bool cond_3 = is_identical(root_1->right, root_2->right);

        if (cond_1 && cond_2 && cond_3)
        {
            return true;
        }
        return false;
    }
}

int main()
{
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);

    Node* root_1 =  new Node(6);
    root_1->left = new Node(3);
    root_1->right = new Node(10);

    if (is_identical(root, root_1))
    {
        cout << "BSTs are identical" <<endl;
    }

    else
    {
        cout << "BSTs are not identical" << endl;
    }

    return 0;
}
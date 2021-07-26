#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

vector<Node*> construct_BST(int start, int end)
{
    vector<Node*> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for(int i = start; i <= end; i++)
    {
        vector<Node*> left_sub = construct_BST(start, i-1);
        vector<Node*> right_sub = construct_BST(i+1, end);

        for(int j = 0; j < left_sub.size(); j++)
        {
            Node* left = left_sub[j];
            for (int k = 0; k < right_sub.size(); k++)
            {
                Node* right = right_sub[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    vector<Node*> total_trees = construct_BST(1, 3);

    for(int i = 0; i < total_trees.size(); i++)
    {
        cout << i+1 << " : ";
        preorder(total_trees[i]);
        cout << endl;
    }

    return 0;
}
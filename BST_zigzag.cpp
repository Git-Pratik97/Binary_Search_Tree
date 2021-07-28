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



void zigzagTraversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node*> curr_level;
    stack<Node*> next_level;

    bool left_to_right = true;

    curr_level.push(root);

    while(!curr_level.empty())
    {
        Node* temp = curr_level.top();
        curr_level.pop();

        if(temp)
        {
            cout << temp->data << " ";

            //Checking if Left-to-Right is true
            if(left_to_right)
            {
                if(temp->left)
                {
                    next_level.push(temp->left);
                }
                if(temp->right)
                {
                    next_level.push(temp->right);
                }
            }

            //If left-to-right is not true
            else
            {
                if(temp->right)
                {
                    next_level.push(temp->right);
                }
                if(temp->left)
                {
                    next_level.push(temp->left);
                }
            }
        }

        if (curr_level.empty())
        {
            left_to_right = !left_to_right;
            swap(curr_level, next_level);
        }
        
    }   
}

int main()
{
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    zigzagTraversal(root);
    cout << endl;
    
    return 0;
}
// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#

class Solution
{
public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void serial(Node *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->data);
        serial(root->left, arr);
        serial(root->right, arr);
    }

    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> v;
        serial(root, v);
        return v;
    }
    int index = 0;

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        if (index == A.size())
            return NULL;
        int val = A[index];
        index++;
        if (val == -1)
            return NULL;
        Node *root = new Node(val);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }
};
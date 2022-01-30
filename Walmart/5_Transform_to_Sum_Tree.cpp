// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *node)
    {
        if (node == NULL)
            return 0;
        int old_val = node->data;
        node->data = solve(node->left) + solve(node->right);
        return node->data + old_val;
    }

    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};
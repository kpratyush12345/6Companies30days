// https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/

int solve(Node *root, int &count, int x)
{
    // if tree is empty
    if (!root)
        return 0;

    // sum of nodes in the left subtree
    int ls = solve(root->left, count, x);

    // sum of nodes in the right subtree
    int rs = solve(root->right, count, x);

    // sum of nodes in the subtree rooted
    // with 'root->data'
    int sum = ls + rs + root->data;

    // if true
    if (sum == x)
        count++;

    // return subtree's nodes sum
    return sum;
}

int countSubtreesWithSumX(Node *root, int x)
{
    // Code here
    if (!root)
        return 0;

    int count = 0;

    // sum of nodes in the left subtree
    int ls = solve(root->left, count, x);

    // sum of nodes in the right subtree
    int rs = solve(root->right, count, x);

    // if tree's nodes sum == x
    if ((ls + rs + root->data) == x)
        count++;

    // required count of subtrees
    return count;
}
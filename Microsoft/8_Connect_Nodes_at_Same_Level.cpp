// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/#

class Solution
{
public:
    // Function to connect nodes at same level.
    void connect(Node *root)
    {
        // Your Code Here
        if (root == NULL)
            return;
        // Create an empty queue like level order traversal
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            // size indicates no. of nodes at current level
            int size = q.size();
            // for keeping track of previous node
            Node *prev = NULL;
            while (size--)
            {
                Node *temp = q.front();
                q.pop();

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);

                if (prev != NULL)
                    prev->nextRight = temp;
                prev = temp;
            }
            prev->nextRight = NULL;
        }
    }
};

// https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        // Add code here
        Node *curr = head, *t;
        int count;
        while (curr)
        {
            for (count = 1; count < M && curr != NULL; count++)
                curr = curr->next;

            if (curr == NULL)
                return;

            t = curr->next;
            for (count = 1; count <= N && t != NULL; count++)
            {
                Node *temp = t;
                t = t->next;
                free(temp);
            }
            curr->next = t;
            curr = t;
        }
    }
};
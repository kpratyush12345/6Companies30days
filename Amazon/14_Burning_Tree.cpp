// https://practice.geeksforgeeks.org/problems/burning-tree/1/

class Solution
{
public:
    int mn = INT_MIN;
    int count = 0;
    bool findTarget(Node *root, int target, unordered_map<Node *, int> &mp)
    {
        if (!root)
            return false;

        if (root->data == target)
        {
            mp[root] = count++;
            return true;
        }

        auto r1 = findTarget(root->left, target, mp);
        auto r2 = findTarget(root->right, target, mp);

        if (r1 == true || r2 == true)
        {
            mp[root] = count++;
        }
        return (r1 || r2);
    }

    void BurnTree(Node *root, unordered_map<Node *, int> &mp)
    {
        if (!root)
            return;

        auto itr = mp.find(root);
        if (itr != mp.end())
        {
            mn = max(mn, itr->second);
            if (root->left)
            {
                if (mp.end() == mp.find(root->left))
                {
                    mp[root->left] = itr->second + 1;
                    mn = max(mn, itr->second + 1);
                }
            }
            if (root->right)
            {
                if (mp.end() == mp.find(root->right))
                {
                    mp[root->right] = itr->second + 1;
                    mn = max(mn, itr->second + 1);
                }
            }
            BurnTree(root->left, mp);
            BurnTree(root->right, mp);
        }
    }
    int minTime(Node *root, int target)
    {
        int res{};
        mn = INT_MIN;
        count = 0;
        unordered_map<Node *, int> mp;
        mp.clear();
        if (findTarget(root, target, mp))
        {
            BurnTree(root, mp);
        }
        return mn;
    }
};

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
};

int answer(Tree *root, int lo, int hi)
{
    if (root == nullptr)
        return 0;
    else
    {
        if (root->val >= lo && root->val <= hi)
            return 1 + answer(root->left, lo, hi) + answer(root->right, lo, hi);
        else if (root->val < lo)
            return answer(root->right, lo, hi);
        else
            return answer(root->left, lo, hi);
    }
}
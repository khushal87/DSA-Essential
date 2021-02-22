#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    /* data */
    int val;
    Node *next;
};

bool isPalindrome(Node *root)
{
    Node *head = root;
    stack<int> st;
    while (head != nullptr)
    {
        st.push(head->val);
        head = head->next;
    }
    int flag = 0;
    while (root != nullptr)
    {
        int top = st.top();
        st.pop();
        if (top != root->val)
        {
            flag = 1;
            break;
        }
        root = root->next;
    }
    if (flag == 1)
        return false;
    else
        return true;
}
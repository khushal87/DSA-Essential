#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie()
    {
        root = getNode('/' - 'a');
    }
    //size of a node is 217 bytes
    struct TrieNode
    {
        char val;
        int count, endsHere;
        TrieNode *child[26];
    };

    TrieNode *root;

    TrieNode *getNode(int idx)
    {
        TrieNode *newnode = new TrieNode;
        newnode->val = 'a' + idx;
        newnode->count = newnode->endsHere = 0;
        for (int i = 0; i < 26; i++)
        {
            newnode->child[i] = NULL;
        }
        return newnode;
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        int idx;
        for (auto j : word)
        {
            idx = j - '0';
            if (curr->child[idx] == NULL)
                curr->child[idx] = getNode(idx);
            curr->child[idx]->count += 1;
            curr = curr->child[idx];
        }
        curr->endsHere += 1;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        int idx;
        for (auto j : word)
        {
            idx = j - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return curr->endsHere > 0;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        int idx;
        for (auto j : prefix)
        {
            idx = j - 'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return curr->count > 0;
    }
};
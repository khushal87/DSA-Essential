#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool end;
    TrieNode *children[26];
    int cnt;
    TrieNode()
    {
        end = false;
        cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = this->root;
        for (auto j : word)
        {
            if (!node->children[j - 'a'])
            {
                node->children[j - 'a'] = new TrieNode();
            }
            node = node->children[j - 'a'];
            node->cnt++;
        }
        node->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = root;
        for (auto j : word)
        {
            if (!node->children[j - 'a'])
            {
                return false;
            }
            node = node->children[j - 'a'];
        }
        return node->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto j : prefix)
        {
            if (!node->children[j - 'a'])
            {
                return false;
            }
            node = node->children[j - 'a'];
        }
        if (node->cnt > 0)
            return true;
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
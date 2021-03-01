#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
    bool endOfWord;
    TrieNode *children[26];
};

TrieNode *getNode()
{
    TrieNode *pNode = new TrieNode;
    pNode->endOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        pNode->children[i] = nullptr;
    }
    return pNode;
}

void insert(TrieNode *root, string s)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        if (!pCrawl->children[idx])
        {
            pCrawl->children[idx] = getNode();
        }
        pCrawl = pCrawl->children[idx];
    }
    pCrawl->endOfWord = true;
}

bool search(TrieNode *root, string s)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < s.length(); i++)
    {
        int idx = s[i] - 'a';
        if (!pCrawl->children[idx])
        {
            return false;
        }
        pCrawl = pCrawl->children[idx];
    }
    return (pCrawl != nullptr && pCrawl->endOfWord);
}

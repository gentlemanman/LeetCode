//
// Created by Administrator on 2019/1/19.
//
#include <bits/stdc++.h>
using namespace std;

class WordDictionary{
public:
    struct TrieNode{
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false){
            for(auto &a : child) a = NULL;
        }
    };

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode *p = root;
        for(auto &a : word){
            int i = a - 'a';
            if(!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    bool search(string word){
        return searchWord(word, root, 0);
    }

    bool searchWord(string &word, TrieNode *p, int i){
        if(i == word.size()) return p->isWord;
        if(word[i] == '.'){
            for(auto &a : p->child){
                if(a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        }
        else return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
    }

private:
    TrieNode *root;
};


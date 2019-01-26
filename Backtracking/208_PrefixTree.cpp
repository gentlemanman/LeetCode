//
// Created by Administrator on 2019/1/19.
//

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() : isWord(false){
        for(auto &a : child) a = NULL;
    }
};

class Trie{
public:
     Trie(){
         root = new TrieNode();
     }

     void insert(string s){
         TrieNode *p = root;
         for(auto &a : s){
             int i = a - 'a';
             if(!p->child[i]) p->child[i] = new TrieNode();
             p = p->child[i];
         }
         p->isWord = true;
     }

     bool search(string key){
         TrieNode* p = root;
         for(auto &a : key){
             int i = a - 'a';
             if(!p->child[i]) return false;
             p = p->child[i];
         }
         return p->isWord;
     }

     bool startsWith(string prefix){
         TrieNode *p = root;
         for(auto &a : prefix){
             int i = a - 'a';
             if(!p->child[i]) return false;
             p = p->child[i];
         }
         return true;
     }

private:
    TrieNode* root;
};



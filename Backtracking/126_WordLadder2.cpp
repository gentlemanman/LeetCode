//
// Created by Administrator on 2019/1/17.
//


#include <bits/stdc++.h>
using namespace std;

//https://blog.csdn.net/qq_22080999/article/details/80833570
struct item{
    string node;
    int pre_pos;
    int step;
    item(string _node, int _pre_pos, int _step) :node(_node), pre_pos(_pre_pos), step(_step){}
};

bool check(string s1, string s2){
    int diff = 0;
    for(int i = 0; i < s1.length(); ++i){
        if(s1[i] != s2[i])
            diff++;
    }
    return diff == 1;
}

void construct_graph(string& beginWord, vector<string>& wordList, map<string, vector<string>>& graph){
    int has_beginWord = 0;
    for(int i = 0; i < wordList.size(); ++i){
        if(wordList[i] == beginWord)
            has_beginWord = 1;
        graph[wordList[i]] = vector<string>();
    }
    for(int i = 0; i < wordList.size(); ++i){
        for(int j = i + 1; j < wordList.size(); ++j){
            if(check(wordList[i], wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
        if(has_beginWord == 0 && check(wordList[i], beginWord)){
            graph[wordList[i]].push_back(beginWord);
            graph[beginWord].push_back(wordList[i]);
        }
    }
}

void bfs(string& beginWord, string& endWord, map<string, vector<string>>& graph, vector<item>& q, vector<int>& end_word_pos){
    map<string, int> visit;
    int min_step = 0;
    q.push_back(item(beginWord, -1, 1));
    visit[beginWord] = 1;
    int front = 0;

    while(front != q.size()){
        string node = q[front].node;
        int step = q[front].step;

        if(min_step != 0 && step > min_step)
            break;

        if(node == endWord){
            min_step = step;
            end_word_pos.push_back(front);
        }

        vector<string> neighbors = graph[node];
        for(int i = 0; i < neighbors.size(); ++i){
            if(visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step + 1){
                q.push_back(item(neighbors[i], front, step + 1));
                visit[neighbors[i]] = step + 1;
            }
        }
        front++;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    map<string, vector<string>> graph;
    vector<item> q;
    vector<int> end_word_pos;

    construct_graph(beginWord, wordList, graph);
    bfs(beginWord, endWord, graph, q, end_word_pos);

    vector<vector<string>> res;
    for(int i = 0; i < end_word_pos.size(); ++i){
        int pos = end_word_pos[i];
        vector<string> path;
        while(pos != -1){
            path.push_back(q[pos].node);
            pos = q[pos].pre_pos;
        }
        res.push_back(vector<string>());
        for(int j = path.size() - 1; j >= 0; --j){
            res[i].push_back(path[j]);
        }
    }
    return res;
}

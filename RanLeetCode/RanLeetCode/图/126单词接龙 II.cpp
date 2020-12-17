//
//  126单词接龙 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/10/13.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //1.建立字典
        map<string, vector<string>> mp;
        wordList.push_back(beginWord);
        for (int i=0; i<wordList.size(); i++) {
            string word = wordList[i];
            for (int j=0; j<word.length(); j++) {
                string tmp = word;
                tmp.replace(j, 1, "*");
                if (mp.find(tmp) != mp.end()) {
                    mp[tmp].push_back(word);
                } else {
                    vector<string> v;
                    v.push_back(word);
                    mp[tmp] = v;
                }
            }
        }
        
        //2.BFS
        queue<string> q;
        map<string, bool> visited;  //是否已访问
        map<string, int>  level;    //遍历的层次
        
        //标示为已访问
        visited[beginWord] = true;
        level[beginWord] = 1;
        q.push(beginWord);
        
        while (!q.empty()) {
            int len = q.size();
            for (int i=0; i<len; i++) {
                string cur = q.front();
                q.pop();
                
                //吧相邻的未访问的元素拿出来放进队列
                for (int i=0; i<cur.length(); i++) {
                    string key = cur;
                    key.replace(i, 1, "*");
                    vector<string> v = mp[key];
                    
                    for (int j=0; j<v.size(); j++) {
                        string next = v[j];
                        if (next != cur && !visited[next]) {
                            q.push(next);
                            level[next] = level[cur] + 1;
                            
                            //添加进队列相当于已访问
                            visited[next] = true;
                            
                            //如果访问到了终点
                            if (next == endWord) {
                                //return level[next];
                            }
                        }
                    }
                    
                }
            }
        }
        
        vector<vector<string>> res;
        return res;
    }
};

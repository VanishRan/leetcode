//
//  127单词接龙.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

/*
 输入:
 beginWord = "hit",
 endWord = "cog",
 wordList = ["hot","dot","dog","lot","log","cog"]
 
             dot - dog
           /  ｜    ｜  \
 hit - hot    ｜    ｜   cog
           \  ｜    ｜  /
             lot - log
 
 *it -> hit
 h*t -> hit hot
 hi* -> hit
 ---------------------
 *ot -> hot dot lot
 ho* -> hot
 ---------------------
 d*t -> dot
 do* -> dot dog
 ---------------------
 l*t -> lot
 lo* -> lot log
 ---------------------
 *og -> dog log cog
 d*g -> dog
 ---------------------
 l*g -> log
 ---------------------
 c*g -> cog
 co* -> cog
 ---------------------
 
 
 */
#include "common.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
                                return level[next];
                            }
                        }
                    }
                    
                }
            }
        }
        
        return 0;
    }
};

/*
 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

 每次转换只能改变一个字母。
 转换过程中的中间单词必须是字典中的单词。
 说明:

 如果不存在这样的转换序列，返回 0。
 所有单词具有相同的长度。
 所有单词只由小写字母组成。
 字典中不存在重复的单词。
 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 示例 1:

 输入:
 beginWord = "hit",
 endWord = "cog",
 wordList = ["hot","dot","dog","lot","log","cog"]

 输出: 5

 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
      返回它的长度 5。
 示例 2:

 输入:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]

 输出: 0

 解释: endWord "cog" 不在字典中，所以无法进行转换。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-ladder
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

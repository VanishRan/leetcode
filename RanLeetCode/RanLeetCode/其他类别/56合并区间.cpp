//
//  56合并区间.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i=1; i<intervals.size(); i++) {
            vector<int> pre = res.back();
            vector<int> cur = intervals[i];
            
            if (cur[0] > pre[1]) {
                res.push_back(cur);
            } else if (cur[0] <= pre[1] && cur[1] > pre[1]) {
                pre[1] = cur[1];
                res.pop_back();
                res.push_back(pre);
            }
        }
        return res;
    }
};

//int main() {
//    Solution s;
//    vector<int> t1 = {1,3};
//    vector<int> t2 = {2,6};
//    vector<int> t3 = {8,10};
//    vector<int> t4 = {15,18};
//    vector<vector<int>> tt = {t1,t2,t3,t4};
//    s.merge(tt);
//}

/*
 输入: [[1,3],[2,6],[8,10],[15,18]]
 输出: [[1,6],[8,10],[15,18]]
 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 示例 2:

 输入: [[1,4],[4,5]]
 输出: [[1,5]]
 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-intervals
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

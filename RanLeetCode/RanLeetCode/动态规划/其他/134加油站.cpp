//
//  134加油站.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
我们首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求
 */
//有点难
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int begin = 0;
        int totalLeft = 0; //从0～n-1 走完全程剩余多少油
        int curLeft = 0;   //从某点出发，当前剩余多少油
        for (int i=0; i<gas.size(); i++) {
            totalLeft += gas[i] - cost[i];
            curLeft += gas[i] - cost[i];
            if (curLeft < 0) {
                begin = i+1;
                curLeft = 0;
            }
        }
        
        return totalLeft >= 0 ? begin : -1;
    }
};

class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i=0; i<gas.size(); i++) {
            if (gas[i] >= cost[i] && func(gas, cost, i, i+1, gas[i]-cost[i])) {
                return i;
            }
        }
        return -1;
    }
    
    bool func(vector<int>& gas, vector<int>& cost, int begin, int cur, int left) {
        cur = cur % gas.size();
        if (cur == begin)
            return true;
        
        left += gas[cur];
        if (left < cost[cur])
            return false;
        
        
        return func(gas, cost, begin, cur+1, left-cost[cur]);
    }
};

/*
 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

 说明:

 如果题目有解，该答案即为唯一答案。
 输入数组均为非空数组，且长度相同。
 输入数组中的元素均为非负数。
 示例 1:

 输入:
 gas  = [1,2,3,4,5]
 cost = [3,4,5,1,2]

 输出: 3

 解释:
 从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
 开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
 开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
 开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
 开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
 开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
 因此，3 可为起始索引。
 示例 2:

 输入:
 gas  = [2,3,4]
 cost = [3,4,3]

 输出: -1

 解释:
 你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
 我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
 开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
 开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
 你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
 因此，无论怎样，你都不可能绕环路行驶一周。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/gas-station
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

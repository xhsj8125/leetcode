/*
 * @lc app=leetcode.cn id=1124 lang=c
 *
 * [1124] 表现良好的最长时间段
 *
 * https://leetcode-cn.com/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (28.21%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 21.5K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
 * 
 * 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
 * 
 * 所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
 * 
 * 请你返回「表现良好时间段」的最大长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：hours = [9,9,6,0,6,6,9]
 * 输出：3
 * 解释：最长的表现良好时间段是 [9,9,6]。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= hours.length <= 10000
 * 0 <= hours[i] <= 16
 * 
 * 
 */

// @lc code=start


int longestWPI(int* hours, int hoursSize){
    int i;
    int *presum;

    for (i = 0; i < hoursSize; i++) {
        hours[i] = hours[i] > 8 ? 1 : -1;
    }
    presum = (int *)malloc(sizeof(int) * (hoursSize + 1));
    presum[0] = 1;
    for (i = 1; i < hoursSize + 1; i++) {
        presum[i] = hours[i - 1] + presum[i - 1];
    }


    return 0;
}


// @lc code=end
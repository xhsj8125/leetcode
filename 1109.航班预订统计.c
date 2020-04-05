/*
 * @lc app=leetcode.cn id=1109 lang=c
 *
 * [1109] 航班预订统计
 *
 * https://leetcode-cn.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Medium (41.31%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 16.6K
 * Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
 *
 * 这里有 n 个航班，它们分别从 1 到 n 进行编号。
 * 
 * 我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k
 * 个座位。
 * 
 * 请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * 输出：[10,55,45,25,25]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= bookings.length <= 20000
 * 1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
 * 1 <= bookings[i][2] <= 10000
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize){
    int *res;
    int i, j;

    *returnSize = n;
    res = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        res[i] = 0;
    }
    for (i = 0; i < bookingsSize; i++) {
        res[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n)
            res[bookings[i][1]] -= bookings[i][2];
    }
    for (i = 1; i < n; i++) {
        res[i] += res[i - 1];
    }
    return res;
}


// @lc code=end


/*
 * @lc app=leetcode.cn id=41 lang=c
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (37.14%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    34.2K
 * Total Submissions: 91.5K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 说明:
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 * 
 */

// @lc code=start
static inline void swap(int *nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize){
    int i;

    if (nums == NULL || numsSize == 0) {
        return 1;
    }
    if (numsSize == 1 && (nums[0] > 1 || nums[0] < 1)) {
        return 1;
    }
    for (i = 0; i < numsSize; ) {
        if (nums[i] < 1 || nums[i] > numsSize) {
            i++;
            continue;
        }
        if (nums[i] != i + 1) {
            if (nums[nums[i] - 1] == nums[i]) {
                nums[i] = -1;
                i++;
            }
            else {
                swap(nums, i, nums[i] - 1);
            }    
        }
        else {
            i++;
        }
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}


// @lc code=end


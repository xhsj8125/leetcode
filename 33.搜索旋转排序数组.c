/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.24%)
 * Likes:    486
 * Dislikes: 0
 * Total Accepted:    68.3K
 * Total Submissions: 188.2K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
int search2(int *nums, int left, int right, int target)
{
    int mid;

    if (left > right) {
        return -1;
    }
    mid = left + (right - left) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    else {
        if (nums[mid] < nums[right]) {
            if (nums[mid] < target && target <= nums[right]) {
                return search2(nums, mid + 1, right, target);
            }
            else {
                return search2(nums, left, mid - 1, target);
            }
        }
        else {
            if (nums[left] <= target && target < nums[mid]) {
                return search2(nums, left, mid - 1, target);
            }
            else {
                return search2(nums, mid + 1, right, target);
            }
        }
    }
}

int search(int* nums, int numsSize, int target){
    return search2(nums, 0, numsSize - 1, target);
}


// @lc code=end


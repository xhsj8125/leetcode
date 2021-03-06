/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (46.19%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    98.5K
 * Total Submissions: 213.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode new = {0, head};
    struct ListNode *tmp = &new;

    while (tmp->next) {
        if (tmp->next->val == val)
            tmp->next = tmp->next->next;
        else
            tmp = tmp->next;
    }
    return new.next;
}


// @lc code=end

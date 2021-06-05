/*
203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 

示例 1：


输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]
 

提示：

列表中的节点在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= k <= 50
*/
#include "common.h"
#include "test_tree.h"
#include "test_list.h"
#include "timer.h"

ListNode *removeElements(ListNode *head, int val)
{
    ListNode node(0);
    node.next = head;
    ListNode *current = &node;
    ListNode *tmp;
    while (current->next)
    {
        if (current->next->val == val)
        {
            tmp = current->next->next;
            delete current->next;
            current->next = tmp;
        }
        else
        {
            current = current->next;
        }
    }
    return node.next;
}

//递归
ListNode *removeElements_II(ListNode *head, int val)
{
    if (head == nullptr)
    {
        return head;
    }
    head->next = removeElements_II(head->next, val);
    return head->val == val ? head->next : head;
}

int main()
{
    PrintTitle(__FILE__);
    Timer t;
    //input init
    ListNode *list1 = createList("[1, 2, 6, 3, 4, 5, 6]");
    t.reset();
    auto ret1 = removeElements(list1, 6);
    t.printElapsed();
    printList(ret1);
    destoryList(ret1);

    ListNode *list2 = createList("[7,7,7,7]");
    t.reset();
    auto ret2 = removeElements_II(list2, 7);
    t.printElapsed();
    printList(ret2);
    destoryList(ret2);
    return 0;
}
/**
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**/

/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    if(l1.length === 0) {
        return l2;
    }
    else if(l2.length === 0) {
        return l1;
    }

    var Dummy = new ListNode(0);
    var node = Dummy;
    var increasing = 0;

    while(l1 !== null && l2 !== null) {
        let Sum = l1.val + l2.val + increasing;
        if(Sum >= 10) {
            node.next = new ListNode(Sum - 10);
            increasing = 1;
        }
        else {
            node.next = new ListNode(Sum)
            increasing = 0;
        }
        node = node.next;
        l1 = l1.next;
        l2 = l2.next;
    }

    while(l1 !== null) {
        let Sum = l1.val + increasing;
        if(Sum >= 10) {
            node.next = new ListNode(Sum - 10);
            increasing = 1;
        }
        else {
            node.next = new ListNode(Sum)
            increasing = 0;
        }
        node = node.next;
        l1 = l1.next;
    }

    while(l2 !== null) {
        let Sum = l2.val + increasing;
        if(Sum >= 10) {
            node.next = new ListNode(Sum - 10);
            increasing = 1;
        }
        else {
            node.next = new ListNode(Sum)
            increasing = 0;
        }
        node = node.next;
        l2 = l2.next;
    }

    if(increasing == 1) {
        node.next = new ListNode(1);
    }

    return Dummy.next;
};

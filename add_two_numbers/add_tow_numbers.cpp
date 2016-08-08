/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }

        ListNode *increase = new ListNode(0);
        ListNode *Dummy = new ListNode(0);
        ListNode *construct = Dummy;

        while(l1 != NULL && l2 != NULL){
            l2->val = l1->val + l2->val + increase->val;
            if(l2->val >= 10){
                l2->val = l2->val - 10;
                increase->val = 1;
            }
            else{
                increase->val = 0;
            }
            construct->next = l2;
            l1 = l1->next;
            l2 = l2->next;
            construct = construct->next;
        }

        while(l1 != NULL){
            l1->val = l1->val + increase->val;
            if(l1->val >= 10){
                l1->val = l1->val - 10;
                increase->val = 1;
            }
            else{
                increase->val = 0;
            }
            construct->next = l1;

            l1 = l1->next;
            construct = construct->next;
        }
        while(l2 != NULL){
            l2->val = l2->val + increase->val;
            if(l2->val >= 10){
                l2->val = l2->val - 10;
                increase->val = 1;
            }
            else{
                increase->val = 0;
            }
            construct->next = l2;

            l2 = l2->next;
            construct = construct->next;
        }
        if(increase->val == 1){
            construct->next = increase;
        }
        return Dummy->next;
    }
};

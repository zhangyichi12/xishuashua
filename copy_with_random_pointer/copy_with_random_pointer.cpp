/**
A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.
**/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) {
            return NULL;
        }

        unordered_map<RandomListNode*, RandomListNode*> record;
        RandomListNode *node = head;

        while(node->next != NULL) {
            if(record.find(node) == record.end()) {
                record[node] = new RandomListNode(node->label);
            }

            if(record.find(node->next) == record.end()) {
                record[node->next] = new RandomListNode(node->next->label);
            }
            record[node]->next = record[node->next];

            if(node->random != NULL) {
                if(record.find(node->random) == record.end()) {
                    record[node->random] = new RandomListNode(node->random->label);
                }
                record[node]->random = record[node->random];
            }

            node = node->next;
        }

        if(record.find(node) == record.end()) {
            record[node] = new RandomListNode(node->label);
        }
        if(node->random != NULL) {
            if(record.find(node->random) == record.end()) {
                record[node->random] = new RandomListNode(node->random->label);
            }
            record[node]->random = record[node->random];
        }

        return record[head];
    }
};

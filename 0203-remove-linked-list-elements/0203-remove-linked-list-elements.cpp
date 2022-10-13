/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val==val) head=head->next;
        ListNode *validHead = head;
        while(head){
            ListNode* nextNode = head->next;
            if(nextNode && nextNode->val == val)
                while(nextNode && nextNode->val==val) nextNode=nextNode->next;
            head->next=nextNode;
            head=nextNode;
        }
        return validHead;
    }
};
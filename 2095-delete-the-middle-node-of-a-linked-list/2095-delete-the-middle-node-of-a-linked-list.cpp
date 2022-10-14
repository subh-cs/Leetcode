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
    ListNode* findMiddleNode(ListNode* head){
       ListNode* fastPtr = head;
       ListNode* slowPtr = head;
        while(fastPtr!=NULL && fastPtr->next!=NULL){
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
        }
        return slowPtr;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;
        ListNode* middleNode = findMiddleNode(head);
        ListNode* node=head;
        //again traverse through the list and delete the node
        while(node->next && node->next!=middleNode) node=node->next;
        node->next=middleNode->next;
        middleNode->next=NULL;
        
        return head;
    }
};
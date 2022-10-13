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
    void deleteNode(ListNode* node) {
        ListNode *nextNode = node->next;
        while(nextNode!=NULL){
        node->val = nextNode->val;
        if(nextNode->next==NULL) node->next=NULL;
        node=nextNode;nextNode=nextNode->next;
        }
        
    }
};
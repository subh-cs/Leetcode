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
    int findLength(ListNode* node){
        int n = 1;
        while(node->next) {node=node->next;n++;}
        return n;
    }
    ListNode* nthNode(ListNode* head,int n, int length){
        ListNode* node = head;
        while(true){
            if(length==n) return node;
            length--;node=node->next;
        }
        return node;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        if(length==1) return NULL;
        ListNode* deleteNode = nthNode(head,n,length);
        if(deleteNode==head) return head->next;
        ListNode* node = head;
        while(node->next && node->next!=deleteNode) node=node->next;
        node->next = deleteNode->next;
        deleteNode->next = NULL;
        return head;
    }
};
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
    ListNode* partition(ListNode* head, int x) {
        // if(!head||!head->next) return head;
        vector<int>res;
        ListNode* node = head;
        //
        while(node!=NULL){
            if(node->val<x) res.push_back(node->val);
            node=node->next;
        }
        //
        node=head;
        while(node!=NULL){
            if(node->val>=x) res.push_back(node->val);
            node=node->next;
        }
        //
        node=head;int i=0;
        while(node!=NULL){
            node->val=res[i++];
            node=node->next;
        }
        return head;
    }
};
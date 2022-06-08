/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ne1 = NULL;
        while(head!=NULL){
            ListNode* newHead = head->next;
            head->next = ne1;
            ne1 = head;
            head = newHead;
            
        }
        return ne1;
        
    }
};

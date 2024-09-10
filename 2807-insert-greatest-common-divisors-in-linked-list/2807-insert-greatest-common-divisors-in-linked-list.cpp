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
    /*
    ListNode *reverse(ListNode *head) {
        auto prev = head, curr = head;
        prev = nullptr;
        while (curr) {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return head;
    }
    */
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //auto temp = new ListNode(0);
        if (!head->next) return head;
        
        //add a dump node to the end of listnode to faciliate traverse;
        auto ptra = head;
        while (ptra->next)
            ptra = ptra->next;
        auto temp = new ListNode(0);
        ptra->next = temp;
        
        //add a gcd node between nodes;
        auto prev = head, curr = head->next;
        while (prev->next->next && curr->next) {
            auto tmp = new ListNode();
            tmp->val = gcd(prev->val,curr->val);
            tmp->next = curr;
            prev->next = tmp;
            curr = curr->next;
            prev = prev->next->next;
        }
        
        //remove dump node at the end of listnode
        auto ptrb = head;
        while (ptrb->next->next) {
            ptrb = ptrb->next;
        }
        auto del = ptrb->next;
        ptrb->next = nullptr;
        delete del;
        
        //return
        return head;
    }
};
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
    ListNode* swapPairs(ListNode* head) {

        if (head == nullptr || head->next == nullptr){
            return head;
        } 
        ListNode* first = head;
        ListNode* second = first->next;
        ListNode* nextPair = second->next;

        second->next = first;
        first->next = nextPair;
        head = second;
        ListNode* prevPair = first;

        while (nextPair != nullptr && nextPair->next != nullptr){
            ListNode* firstNext = nextPair;
            ListNode* secondNext = firstNext->next;
            // prevPair = nextPair;
            nextPair = nextPair->next->next;

            secondNext->next = firstNext;
            firstNext->next = nextPair;
            prevPair->next = secondNext;
            prevPair = prevPair->next->next;
        }
        // ListNode* nextNode = head->next->next;
        // prev = head;
        // head = head->next;
        // head->next = prev;
        // prev->next = nextNode;
        // ListNode* temp = head->next->next;
        // curr = head->next->next->next;

        // while (nextNode != nullptr && nextNode->next != nullptr){
        //     nextNode = nextNode->next->next;
        //     // prev++;
        //     temp->next = nextNode;
        //     prev->next = curr;
        //     curr->next = temp;
        // }

        return head;
    }
};
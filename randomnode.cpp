// https://leetcode.com/problems/linked-list-random-node/discuss/1673601/C%2B%2B-Simple-Optimized-Solution

// Approach:

// We want the function to give a selected node from the linked list in such a way that the selection has equal probability for ever node present in the list.
// For this while traversing the list, we start generating random numbers.
// Random numbers -> rand() % len where len is the current length of the list while traversing.
// so now since for different lengths we can have many different samples in 0 to len - 1 range. Like 0 1, 0 1 2, 0 1 2 3 4 etc
// We try choosing a specific number that is common for every length.
// That's 0 or len - 1. So, if rand() % len == 0 or len - 1 we just update our ans as the current node and keep on going (so that we can have choice from the whole list).

class Solution {
public:
    ListNode* temp;
    Solution(ListNode* head) {
        temp = head;
    }
    
    int getRandom() {
        ListNode* p = temp;
        
        int res = 0;
        int len = 0;
        while(p){
            len++;
            if(rand() % len == 0){
                res = p->val;
            }
            p = p->next;
        }
        
        return res;
    }
};
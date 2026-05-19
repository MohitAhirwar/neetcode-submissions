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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1);
        ListNode* pointingAns = ans;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for(auto &list : lists){
            pq.push({list->val,list});
        }

        while(pq.size()){
            auto cur = pq.top(); pq.pop();

            ListNode* cur2 = new ListNode(cur.first);
            ans -> next = cur2;
            ans = ans->next;


            ListNode* nxt = cur.second -> next;
            if(nxt != NULL){
                pq.push({nxt->val,nxt});
            }
        }

        return pointingAns -> next;
    }
};

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head, int k){
        if (!head) return NULL;
        ListNode *cur = head;
        int n=0;
        while(cur){
            n++;
            cur = cur->next;
        }
        k %= n;
        ListNode *fast = head, *slow = head;
        for(int i=0; i<k; ++i){
            if(fast) fast = fast->next;
        }
        if(!fast) return head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = head;
        ListNode *res;
        res = slow->next;
        slow->next=NULL;
        return res;    
    }
};

int main()
{
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = NULL;
    Solution s;
    ListNode *r=s.rotateRight(l,1);
    for(int i=0; i<2; ++i){
        cout<<r->val<<endl;
        r = r->next;
    }
    return 0;
}

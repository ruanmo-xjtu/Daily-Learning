#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *node;
    ListNode() : val(0), next(nullptr) {}//无参类型
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}//有参类型
};
//定义结构
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);//创建哑节点 保证初始节点处理方式与后续一致
        ListNode* cur = dummy;
        int carry = 0;


        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int val1 = (l1 != nullptr) ? l1->val : 0; 
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;           
            carry = sum / 10;                        
            int RealVal = sum % 10;

            cur->next = new ListNode(RealVal);
            cur = cur->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        ListNode* result = dummy->next;
        return result;
    }
};

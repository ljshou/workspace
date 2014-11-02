// copyright @ L.J.SHOU Feb.22, 2014
// reverse k nodes in list
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode{
				int val;
				ListNode *next;
				ListNode(int x)
								:val(x), next(NULL){}
};

int Length(ListNode *head)
{
				int len(0);
				for(; head; head = head->next, ++ len);
				return len;
}

ListNode* ReverseKList(ListNode *head, int k)
{
				int length = Length(head);
				if(length < 2 || k == 0 || k == length)
								return head;
				if(k < 0) return ReverseKList(head, k + length);
				if(k > length) return ReverseKList(head, k % length);

				assert(k > 0 && k < length);
				ListNode *tail(head), *new_tail(head);

				// tail 先走K步
				for(int i=0; i<k; ++i)
								tail = tail->next;

				// 一起走，知道 tail 指向尾节点
				while(tail->next){
								tail = tail->next;
								new_tail = new_tail->next;
				}

				// new_tail 指向旋转后的尾节点
				tail->next = head;
				head = new_tail->next;
				new_tail->next = NULL;

				return head;
}

ListNode* Destroy(ListNode *list)
{
				ListNode *next(NULL);
				while(list){
								next = list->next;
								delete list;
								list = next;
				}
				return NULL;
}

void Print(ListNode *list)
{
				while(list){
								cout << list->val << " ";
								list = list->next;
				}
				cout << endl;
}

int main(void)
{
				ListNode *list(NULL);

				list = new ListNode(1);
				list->next = new ListNode(2);
				list->next->next = new ListNode(3);
				list->next->next->next = new ListNode(4);
				list->next->next->next->next = new ListNode(5);

				list = ReverseKList(list, 0);
				list = ReverseKList(list, 5);
				list = ReverseKList(list, 7);
				Print(list); 
				list = Destroy(list);
				return 0;
}

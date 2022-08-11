#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Definition for singly-linked list.
struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head){
	struct ListNode *cur1, *cur2, *finder;

	if(!head || !head->next){
		return NULL;
	}

	for(cur1 = head->next, cur2 = head->next->next; cur2 != NULL && cur2->next != NULL; cur1 = cur1->next, cur2 = cur2->next->next){
		if(cur1 == cur2){
			for(finder = head;; finder = finder->next, cur1 = cur1->next){
				if(cur1 == finder){
					return finder;
				}
			}
		}
	}

	return NULL;
}
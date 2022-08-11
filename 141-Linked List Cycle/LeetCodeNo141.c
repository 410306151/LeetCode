#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef char bool;
#define false 0
#define true 1


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head){
	struct ListNode *head1, *head2;
	if(head == NULL || head->next == NULL){
		return false;
	}
	for(head1 = head->next, head2 = head->next->next; head2 != NULL && head2->next != NULL; head1 = head1->next, head2 = head2->next->next){
		if(head1 == head2){
			return true;
		}
	}
	return false;
}


//int main(){
//	struct ListNode *node = malloc(sizeof(struct ListNode));
//	node->val = 2;
//	node->next = NULL;
//	printf("%d\n", hasCycle(node));
//
//	getch();
//
//	return 0;
//}

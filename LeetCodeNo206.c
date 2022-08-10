#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

static void connect_node(struct ListNode **cur_node, struct ListNode *new_node){
	struct ListNode *temp = (*cur_node);

	if(*cur_node == NULL){
		*cur_node = new_node;
	} else{
		for(; temp->next != NULL; temp = temp->next){
		}
		temp->next = new_node;
	}
}

//static void reverse_linked_list(struct ListNode *ori_list, struct ListNode *reverse_list){
//	struct ListNode *new_node;
//
//	if(ori_list->next != NULL){
//		reverse_linked_list(ori_list->next, reverse_list);
//	}
//
//	if(reverse_list->val <= -5000){
//		reverse_list->val = ori_list->val;
//	} else{
//		new_node = calloc(1, sizeof(struct ListNode));
//		new_node->val = ori_list->val;
//		new_node->next = NULL;
//		for(; reverse_list->next != NULL; reverse_list = reverse_list->next){
//		}
//		reverse_list->next = new_node;
//	}
//}
//
//struct ListNode* recursion_method(struct ListNode* head){
//	/// This method uses a recursion to reverse
//	if(head == NULL){
//		return NULL;
//	}
//
//	struct ListNode *new_list = calloc(1, sizeof(struct ListNode));
//	new_list->val = -6000;
//	new_list->next = NULL;
//	reverse_linked_list(head, new_list);
//
//	return new_list;
//}


//struct ListNode* create_new_head_method(struct ListNode* head){
//	/// This method uses memory allocation to create a new head
//	if(head == NULL){
//		return NULL;
//	}
//
//	struct ListNode *new_head = calloc(1, sizeof(struct ListNode));
//	struct ListNode *temp;
//
//	new_head->val = head->val;
//	new_head->next = NULL;
//	head = head->next;
//	for(; head != NULL;){
//		temp = head->next;
//		head->next = new_head;
//		new_head = head;
//		head = temp;
//	}
//
//	return new_head;
//}

struct ListNode* reverseList(struct ListNode* head){
	/// This method doesn't use any other space
	if(head == NULL){
		return NULL;
	}

	struct ListNode *new_head;
	struct ListNode *temp;

	new_head = head;
	temp = head->next;
	new_head->next = NULL;
	head = temp;
	for(; head != NULL;){
		temp = head->next;
		head->next = new_head;
		new_head = head;
		head = temp;
	}

	return new_head;
}

//
//int main(){
//	int input;
//	struct ListNode *head = NULL;
//	struct ListNode *answer, *new_node;
//
//	while(1){
//		scanf("%d", &input);
//		if(input == -1){
//			break;
//		}
//		new_node = calloc(1, sizeof(struct ListNode));
//		new_node->val = input;
//		new_node->next = NULL;
//		connect_node(&head, new_node);
//	}
//	answer = reverseList(head);
//
//	if(answer != NULL){
//		for(;; answer = answer->next){
//			printf("%d ", answer->val);
//			if(answer->next == NULL){
//				break;
//			}
//		}
//	}
//
//	getch();
//
//	return 0;
//}

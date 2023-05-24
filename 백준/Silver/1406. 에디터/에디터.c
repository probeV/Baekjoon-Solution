#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode {
	char data;
	struct ListNode* leftlink;
	struct ListNode* rightlink;
}ListNode;

ListNode* pre;

void init(ListNode* head, ListNode* last, int length, char* firstarry) {
	pre = head;
	head->data = firstarry[0];
	head->rightlink = head;
	head->leftlink = head;
	for (int i = 1; i < length; i++) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = firstarry[i];
		node->leftlink = pre;
		node->rightlink = pre->rightlink;
		pre->rightlink->leftlink = node;
		pre->rightlink = node;
		pre = pre->rightlink;
	}
	last->data = '\0';
	last->leftlink = pre;
	last->rightlink = pre->rightlink;
	pre->rightlink->leftlink = last;
	pre->rightlink = last;
	pre = pre->rightlink;
}

void shiftleft() {
	if (pre->leftlink->data == '\0') return;
	pre = pre->leftlink;
}

void shiftright() {
	if (pre->data == '\0') return;
	pre = pre->rightlink;
}

void DeleteLeft(ListNode* removed) {
	if (pre->leftlink->data == '\0') return;
	removed->leftlink->rightlink = removed->rightlink;
	removed->rightlink->leftlink = removed->leftlink;
	free(removed);
}

void plus(char x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->rightlink = (pre->leftlink)->rightlink;
	(pre->leftlink)->rightlink = node;
	node->leftlink = pre->leftlink;
	pre->leftlink = node;
}

int main(void) {
	ListNode* l = (ListNode*)malloc(sizeof(ListNode));
	ListNode* last = (ListNode*)malloc(sizeof(ListNode));
	char firstarray[100002], command, x;
	int commandnum, length;
	fgets(firstarray, 100002, stdin);
	firstarray[strlen(firstarray) - 1] = '\0';
	length = strlen(firstarray);
	scanf("%d", &commandnum);
	getchar();
	init(l, last, length, firstarray);
	for (int i = 0; i < commandnum; i++) {
		command = getchar();
		getchar();
		switch (command) {
		case 'L':
			shiftleft();
			break;
		case 'D':
			shiftright();
			break;
		case 'B':
			DeleteLeft(pre->leftlink);
			break;
		case 'P':
			x = getchar();
			getchar();
			plus(x);
			break;
		}
	}
	for (ListNode* w = last->rightlink; !(w->data == '\0'); w = w->rightlink) printf("%c", w->data);
	return 0;
}
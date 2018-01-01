#include <cstdio>
typedef struct node { long num; struct node *next; }node;
node *Node1, *Node2, *LinkedList;
long n, target;
int main() {
	scanf("%ld", &n);
	Node1 = new node, Node2 = Node1;
	for (long i = 1; i <= n; i++) {
		scanf("%ld", &Node1->num);
		if (i == 1) LinkedList = Node1, Node2->next = NULL;
		else Node2->next = Node1;
		Node2 = Node1, Node1 = new node;
	}
	Node2->next = NULL, scanf("%ld", &target);
	while (LinkedList != NULL && LinkedList->num == target) {
		Node1 = LinkedList, LinkedList = LinkedList->next, delete Node1;
	}
	Node1 = LinkedList;
	if (Node1 != NULL) {
		printf("%ld", Node1->num);
		while (Node1->next != NULL) {
			if (Node1->next->num != target) printf(" %ld", Node1->next->num), Node1 = Node1->next;
			else Node2 = Node1->next, Node1->next = Node1->next->next, delete Node2;
		}
	}
	Node1 = Node2 = NULL;
	delete LinkedList, LinkedList = NULL;
}
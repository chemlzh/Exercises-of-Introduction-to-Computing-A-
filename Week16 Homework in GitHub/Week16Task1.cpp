#include <cstdio>
typedef struct node { long num; struct node *next; }node;
node *a, *b, *res;
long n, m;
inline void init(long cnt, node** head) {
	long tmp;
	for (long i = 1; i <= cnt; i++) {
		node *NewNode = new node;
		scanf("%ld", &NewNode->num), NewNode->next = *head, *head = NewNode;
	}
}
inline void split(node* source, node** a, node** b) {
	node *fast, *slow;
	if (source == NULL || source->next == NULL) *a = source, *b = NULL;
	else {
		slow = source, fast = source->next;
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) slow = slow->next, fast = fast->next;
		}
		*a = source, *b = slow->next, slow->next = NULL;
	}
}
inline node* merge(node* a, node* b) {
	node* result = NULL;
	if (a == NULL) return b;
	if (b == NULL) return a;
	if (a->num <= b->num) {
		result = a, result->next = merge(a->next, b);
	}
	else {
		result = b, result->next = merge(a, b->next);
	}
	return result;
}
inline void mergesort(node **head) {
	node *l, *r;
	if ((*head) == NULL || (*head)->next == NULL) return;
	split(*head, &l, &r), mergesort(&l), mergesort(&r), (*head) = merge(l, r);
}
inline void printlist(node* head) {
	while (head != NULL) {
		printf("%ld", head->num);
		if (head->next != NULL) printf(" ");
		head = head->next;
	}
}
int main() {
	scanf("%ld", &n), init(n, &a);
	scanf("%ld", &m), init(m, &b);
	mergesort(&a), mergesort(&b), res = merge(a, b);
	printlist(res);
}
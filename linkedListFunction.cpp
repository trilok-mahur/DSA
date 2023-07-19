#include "student.cpp"
#include <bits/stdc++.h>
using namespace std;

Node *bubbleSort(Node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	int len = 0;
	Node * temp = head;
	while(temp != NULL) {
		len++;
		temp = temp->next;
	}
  cout << len << endl;
	Node * first = NULL;
	for(int i = 0; i < len; i++) {
		temp = head;
		for(int j = 0; j < len - i - 1; j++) {
			if(temp->data > temp->next->data) {
				Node * k = temp->next;
				temp->next = k->next;
				k->next = temp;
        temp = k;
				if(i == 0 && j == 0) {
					first = k;
          cout << " j = " << j << " " << endl;
				}
			}
			temp = temp->next;
		}
	}
	if(first != NULL) {
		return first;
	}
	else {
		return head;
	}
}
int main() {
  Node *head = NULL;
  head = takeInput(head);
  printLL(head);
  head = bubbleSort(head);
  cout << " after sort \n";
  printLL(head);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node * current = head;
	int len = 0;

	if(head == NULL){
		return len;
	}


	while(current != NULL){
		len++;
		current = current -> next;
	}
		return len;


}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node * current = head;
	char *retString = malloc(sizeof(char) * length(head));
	char *ptrString = retString;
	

	if(head == NULL){
		return "Empty";
	}
	
	while(current != NULL){
		
		*ptrString = (current -> letter);
		
		ptrString++;
		
		
		
		current = current -> next;
	}


	return retString;
	
	
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{

	node * current = *pHead;
	node* newNode = (node*) malloc(sizeof(node));
	if (newNode == NULL){
		return;
	}

	newNode -> letter = c;
	newNode -> next = NULL;


	if(*pHead != NULL){
		while(current -> next != NULL){
			current = current -> next;
		}
		current->next = newNode;

	} else {
		*pHead = newNode;
	}
	

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* current = *pHead;

	while (current != NULL)
	{

		*pHead = current->next;
		free(current);
		current = *pHead;
	}


	*pHead = NULL;
}


int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

	
		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
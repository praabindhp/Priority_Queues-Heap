#include<stdio.h>
#include<stdlib.h>
struct heapnode
{
	int capacity;
	int size;
	int *elements;
};
int isFull(struct heapnode *h)
{
	if(h->capacity==h->size)
		return 1;
	else
		return 0;
}
int isEmpty(struct heapnode *h)
{
	if(h->size==0)
		return 1;
	else
		return 0;
}
void display(struct heapnode *h)
{
	printf("\nPriority Queue Display :");
	if(isEmpty(h))
	{
		printf("\nPriority queue is empty");
		return;
	}
	else
	for(int i=1;i<=h->size;i++)
		printf("%d\t",h->elements[i]);

}
struct heapnode * initialize()
{
	struct heapnode *t;
	int maxelements;
	printf("\nEnter the Size of the Priority queue :");
	scanf("%d",&maxelements);

	if(maxelements<5)
	{
		printf("Priority queue size is to small");
		getch();
		exit(0);
	}
	t=(struct heapnode *)malloc(sizeof(struct heapnode *));

	if(t==NULL)
	{
		printf("out of space!");
		getch();
		exit(0);
	}

	t->elements=(int *)malloc((maxelements+1)*sizeof(int));

	if(t->elements==NULL)
	{
		printf("Out of space");
		getch();
		exit(0);
	}

	t->capacity=maxelements;
	t->size=0;
	t->elements=0;
	return t;
}
void insert(int x,struct heapnode *h)
{
	int i;
	if(isFull(h))
	{
		printf("Priority queue is full");
		return;
	}
	for(i=++h->size;h->elements[i/2]>x;i/=2)
		h->elements[i]=h->elements[i/2];
	h->elements[i]=x;
}
int deleteMin(struct heapnode *h)
{
	int i,child;
	int MinElement,LastElement;

	if(isEmpty(h))
	{
		printf("Priority queue is empty");
		return 0;
	}

	MinElement=h->elements[1];
	LastElement=h->elements[h->size--];

	for(i=1;i*2<=h->size;i=child)
	{
		child=i*2;
		if(child!=h->size&&h->elements[child+1]<h->elements[child])
			child++;
		if(LastElement>h->elements[child])
			h->elements[i]=h->elements[child];
		else
			break;
	}
	h->elements[i]=LastElement;
	return MinElement;
}
void main()
{
	int ch,ins,del;
	struct heapnode *h;
	printf("\nPriority Queue using Heap");
	h=initialize();
	while(1)
	{
		printf("\n1. Insert\n2. DeleteMin\n3. Display\n4. Exit");
		printf("\nEnter u r choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element:");
				scanf("%d",&ins);
				insert(ins,h);
				break;
			case 2:
				del=deleteMin(h);
				printf("\nDeleted element is %d",del);
				getch();
				break;
			case 3:
				display(h);
				getch();
				break;
			case 4:
				exit(0);
		}
	}
}
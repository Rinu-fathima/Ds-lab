
#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;

struct node *createNode(int data)
{
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;
        return newNode;
}

void insertAtBeginning(int data)
{
        struct node *newNode=createNode(data);
        newNode->next=head;
        head=newNode;
}

void insertAtEnd(int data)
{
        struct node *newNode=createNode(data);
        if(head==NULL)
        {
        head=newNode;
        return;
        }
        struct node *temp=head;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        temp->next=newNode;
}


void insertAtAnyPosition(int data,int position)
{
        if(position<1)
        {
                printf("Enter position greater than 1\n");
                return;
        }

        if(position==1)
        {
                insertAtBeginning(data);
                return;
        }
        struct node *newNode=createNode(data);
        struct node *temp=head;
        for(int i=1;i<position-1 && temp!=NULL;i++)
        {
        temp=temp->next;
        }
        if(temp==NULL)
        {
                printf("Position out of bounds\n");
                free(newNode);

        }
        else
        {
        newNode->next=temp->next;
        temp->next=newNode;
        }
}

void deleteAtBeginning()
{
        if(head==NULL)
        {
                printf("List is empty\n");
                return;
        }
        struct node *temp=head;
        head=head->next;
        free(temp);
}





void deleteAtEnd()
{
        if(head==NULL)
        {
                printf("List is empty\n");
                return;
        }
        struct node *temp=head;
        struct node *prev=NULL;
        if(head->next==NULL)
        {
                free(temp);
                head=NULL;
        }
        else
        {
                while(temp->next!=NULL)
                {
                        prev=temp;
                        temp=temp->next;
                }
                prev->next=NULL;
                free(temp);

        }
}


void deleteAtAnyPosition(int position)
{
        if(head==NULL)
        {
                printf("List is empty\n");
                return;
        }
        if(position<1)
        {
                printf("Position must be greater than zero\n");
                return;
        }
        if(position==1)
        {
                deleteAtBeginning();
                return;
        }
        struct node *temp=head;
        struct node *prev=NULL;
        for(int i=1;i<position && temp!=NULL;i++)
        {
                prev=temp;
                temp=temp->next;
        }
        if(temp==NULL)
        {
                printf("Position out of bound");
        }
        else
        {
                prev->next=temp->next;
                free(temp);
        }

}


void display()
{
        struct node *temp=head;
        if(temp==NULL)
        {
        printf("List is Empty\n");
        return;
        }
        while(temp!=NULL)
        {
        printf("%d\t",temp->data);
        temp=temp->next;
        }
}

void search(int value)
{
struct node *temp=head;
int found,position=1;
        if(temp==NULL)
        {
        printf("List is Empty\n");
        return;
        }
        while(temp!=NULL)
        {
        if(temp->data==value)
        {
        found=1;
        break;
        }
        temp=temp->next;
        position++;
        }
        if(found==1)
        {
        printf("Data found at %d\n",position);
        }
        else
        {
        printf("Value not found in list\n");
        }
}

int main()
{
        int choice,data,value,position;
        do
        {
                printf("\nSelect your choice\n");
                printf("1.Insert At Beginning List\n");
                printf("2.Insert At End of List\n");
                printf("3.Insert At Any Position of List\n");
                printf("4.Delete At Beginning of List\n");
                printf("5.Delete At End of List\n");
                printf("6.Delete At Any Position of List\n");
                printf("7.Display List\n");
                printf("8.Search an element in list\n");
                printf("9.Exit\n");
                printf("Enter Your choice\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                        printf("Enter data to be inserted\n");
                        scanf("%d",&data);
                        insertAtBeginning(data);
                        break;

                        case 2:
                        printf("Enter data to be inserted\n");
                        scanf("%d",&data);
                        insertAtEnd(data);
                        break;

                        case 3:
                        printf("Enter data to be inserted\n");
                        scanf("%d",&data);
                        printf("Enter Position to be insert data\n");
                        scanf("%d",&position);
                        insertAtAnyPosition(data,position);
                        break;

                        case 4:
                        deleteAtBeginning();
                        break;

                        case 5:
                        deleteAtEnd();
                        break;

		 case 6:
                        printf("Enter Position to be delete data\n");
                        scanf("%d",&position);
                        deleteAtAnyPosition(position);
                        break;

                        case 7:
                        display();
                        break;

                        case 8:
                        printf("Enter value to be searched\n");
                        scanf("%d",&value);
                        search(value);
                        break;

                        case 9:
                        printf("Exiting");
                        exit(0);
                        break;

                        default:
                        printf("Wrong choice");
                        break;
                }
        }

while(choice!=9);
return 0;
}



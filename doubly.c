#include<stdio.h>
#include<stdlib.h>
struct Node{
        struct Node* prev;
        int data;
        struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data)
{
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->prev=NULL;
        newNode->data=data;
        newNode->next=NULL;
        return newNode;
}

void insertAtBeginning(int data)
{
        struct Node *newNode=createNode(data);
        newNode->prev=NULL;
        newNode->next=head;
        head=newNode;
}

void insertAtEnd(int data)
{
struct Node *newNode=createNode(data);
        if(head==NULL)
        {
        head=newNode;
        return;
        }
        struct Node *temp=head;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;
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
        struct Node *newNode=createNode(data);
        struct Node *temp=head;
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
        temp->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
        }

}
void deleteAtBeginning()
{
        if(head==NULL)
        {
                printf("List is empty\n");
                return;
        }
        struct Node *temp=head;
        head=temp->next;
        if(head!=NULL)
        {
                head->prev=NULL;
        }
        free(temp);
        printf("Item Deleted from List\n");
}

void deleteAtEnd()
{
        if(head==NULL)
        {
                printf("List is empty\n");
                return;
        }
        struct Node *temp=head;
        struct Node *loc=NULL;
        if(head->next==NULL)
        {
                free(temp);
                head=NULL;
        }
        else
        {
                while(temp->next!=NULL)
                {
                        loc=temp;
		   temp=temp->next;
                }
                loc->next=NULL;
                free(temp);
                printf("Item Deleted from List\n");

        }


}

void deleteAtAnyposition(int position)
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
        struct Node *temp=head;
        struct Node *loc=NULL;
        for(int i=1;i<position && temp!=NULL;i++)
        {
                loc=temp;
                temp=temp->next;
        }
        if(temp==NULL)
        {
                printf("Position out of bound");
        }
        else
        {
                loc->next=temp->next;
                loc->prev=temp->prev;
                free(temp);
                printf("Item Deleted from List\n");
        }

}                 


void display()
{
        struct Node *temp=head;
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
        struct Node *temp=head;
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
        int data,position,choice,value;
        do
        {
                printf("\nDoubly Linked List Operations:\n");
                printf("Select your choice\n");
                printf("1.Insert At Beginning\n");
                printf("2.Insert At End\n");
                printf("3.Insert At Any Position\n");
                printf("4.Delete At Beginning\n");
                printf("5.Delete At End\n");
                printf("6.Delete At Any Position\n");
                printf("7.Display List\n");
                printf("8.Search\n");
                printf("9.Exit\n");
                printf("Enter Your Choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter the data to be entered:\n");
                                scanf("%d",&data);
                                insertAtBeginning(data);
                                break;
                        case 2:
                                printf("Enter the data to be entered:\n");
                                scanf("%d",&data);
                                insertAtEnd(data);
                                break;
                        case 3:
                                printf("Enter the data to be entered:\n");
                                scanf("%d",&data);
                                printf("Enter the position to be entered:\n");
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
                                printf("Enter position to be deleted\n");
                                scanf("%d",&position);
                                deleteAtAnyposition(position);
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
                                printf("Enter proper choice\n");
                                break;

                }
        }
        while(choice!=9);
        return 0;


}

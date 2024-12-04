#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *link;
}
*top=NULL;

int isEmpty()
{
        if(top==NULL)
        return 1;
        else
        return 0;
}
void push(int data)
{
        struct node *newNode =(struct node*) malloc(sizeof( struct node));
        if(newNode==NULL)
        {
                 printf("Stack is overflow");

        }
        else
        {
                newNode->data=data;
                newNode->link=NULL;
                newNode->link=top;
                top=newNode;
        }
}


int pop()
{
        struct node *temp;
        int val;
        if(isEmpty())
        {
                printf("Stack underflow\n");

        }
        else
        {
                temp=top;
                val=temp->data;
                top=temp->link;
                free(temp);
                temp=NULL;
                printf("Deleted element is : %d",val);
        }
}

int peek()
{
        if(isEmpty())
        {
                printf("Stack underflow");
                exit(1);
        }
        return top->data;
}

void search(int value)
{
        struct node *temp;
        temp=top;
        int found;

        if(isEmpty())
        {
                printf("Stack underflow");
                
        }
       else
       {

                while(temp)
                {
                        if(temp->data==value)
                        {
                                found=1;
                                break;
                        }
                        temp=temp->link;
                }
                if(found==1)
                {
                        printf("The element is inside stack\n");
                }
                else
                        {
                                printf("The element is not inside stack");

                        }


        }



}


void print()
{
        struct node *temp;
        temp=top;
        if(isEmpty())
        {
                printf("Stack underflow");
                exit(1);
        }

        printf("The stack elements are:\n");
        while(temp)
        {
                printf("%d\n",temp->data);
                temp=temp->link;

        }
        

}

int main()
{
        int choice,data,value;
        while(1)
        {
                printf("\n1.Push\n");
                printf("2.Pop\n");
                printf("3.Print the top element\n");
                printf("4.Print all the elements of stack\n");
                printf("5.Search\n");
                printf("6.Quit\n");
                printf("please enter your choice");
                scanf("%d",&choice);
                switch(choice)

                {
                        case 1:
                                printf("enter the element to be pushed");
                                scanf("%d",&data);
                                push(data);
                                break;
                        case 2:
                                pop();

                                break;
                        case 3:
                                printf("The top most element of the stack is %d\n",peek());
                                break;
                        case 4:
                                print();
                                break;
                        case 5:
                                printf("Enter value to be search");
                                scanf("%d",&value);
                                search(value);
                                break;
                        case 6:
                                exit(1);
                        default:
                                printf("Wrong choice\n");
                }
        }
        return 0;
}

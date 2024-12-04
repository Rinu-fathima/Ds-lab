#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left;
struct node *right;

};


struct node* createnode(int data)
{
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
}

struct node* insert(struct node* root,int data)
{
        if(root==NULL)
        {
                root=createnode(data);

        }
        else if(data<root->data)
        {
                root->left=insert(root->left,data);
        }
        else if(data>root->data)
        { 
                root->right=insert(root->right,data);
        }
        return root;

}

struct node* findMin(struct node *root)
{
        while(root && root->left!=NULL)
        {
        root=root->left;
        }
        return root;
}
struct node* deleteNode(struct node* root,int data)
{
        if(root==NULL)
        {
                printf("The value to be deleted is not present inside tree\n");
                return root;
        }
        if(data<root->data)
        {
                root->left=deleteNode(root->left,data);

        }
        else if(data>root->data)
        {
                root->right=deleteNode(root->right,data);
        }
        else{
                if(root->left==NULL)
                {
                        struct node* temp=root->right;
                        free(root);
                        return temp;
                }
                else if(root->right==NULL)
                {
                        struct node* temp=root->left;
                        free(root);
                        return temp;
                }
                struct node *temp=findMin(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
        }
        return root;
}


struct node* search(struct node* root,int data)
{
        if(root==NULL || root->data==data)
        {
                return root;
        }
        if(data<root->data)
        {
                return search(root->left,data);
        }
        else{
                return search(root->right,data);
        }
}

void preorder(struct node *root)
{
        if(root!=NULL)
        {
                printf("%d->",root->data);
                preorder(root->left);
                preorder(root->right);
        }
}

void inorder(struct node *root)
{
        if(root!=NULL)
        {
                inorder(root->left);
                printf("%d->",root->data);
                inorder(root->right);
        }
}

void postorder(struct node *root)
{
        if(root!=NULL)
        {

                postorder(root->left);
                postorder(root->right);
                printf("%d->",root->data);
        }
}


int main()
{
        struct node* root=NULL;
        int choice,value;
        struct node* foundNode;
        while(1)
        {
                printf("\nBinary Tree Operations:\n");
                printf("Select your choice:\n");
                printf("1.Insert \n");
                printf("2.Delete\n");
                printf("3.Search Tree\n");
                printf("4.Preorder Traversal\n");
                printf("5.Inorder Traversal\n");
                printf("6.Postorder Traversal\n");
                printf("7.Exit\n");
                printf("Enter Your choice:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("Enter Data to be entered\n");
                                scanf("%d",&value);
                                root=insert(root,value);
                                break;
		case 2:
                                if(root==NULL)
                                {
                                        printf("Tree is empty");
                                }
                                else
                                {
                                        printf("Enter Data to be Deleted\n");
                                        scanf("%d",&value);
                                        root=deleteNode(root,value);
                                }
                                break;


                        case 3:
                                 if(root==NULL)
                                {
                                        printf("Tree is empty");
                                }
                                else
                                {

                                printf("Enter value to be searched\n");
                                scanf("%d",&value);
                                foundNode=search(root,value);
                                if(foundNode!=NULL)
                                {
                                printf("Value %d found in the tree.\n",value);
                                }
                                else
                                {
                                printf("Value %d not found in the tree.\n",value);

                                }
                                }
                                break;
                        case 4:
                                 if(root==NULL)
                                {
                                        printf("Tree is empty");
                                }
                                else
                                {
                                        printf("Preorder Traversal:");
                                        preorder(root);
                                        printf("\n");
                                }
                                break;case 5:
                                if(root==NULL)
                                {
                                        printf("Tree is empty");
                                }
                                else
                                {
                                        printf("Inorder Traversal:");
                                        inorder(root);
                                        printf("\n");
                                }
                                break;


                        case 6:
                                if(root==NULL)
                                {
                                        printf("Tree is empty");
                                }
                                else
                                {
                                        printf("PostOrder Traversal:");
                                        postorder(root);
                                        printf("\n");
                                }
                                break;

                        case 7:
                                printf("Exiting");
                                exit(0);
                                break;
                        default:
                                printf("Invalid choice Try Again..\n");
                                break;


                }
        }

        return 0;
}

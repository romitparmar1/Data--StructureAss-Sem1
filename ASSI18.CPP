#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *root = NULL;

struct node* insert(struct node *root, int val)
{
    struct node *nd;

    if(root == NULL)
    {
	nd = (struct node*)malloc(sizeof(struct node));
	nd->data = val;
	nd->lptr = NULL;
	nd->rptr = NULL;
	return nd;
    }

    if(val < root->data)
	root->lptr = insert(root->lptr, val);
    else
	root->rptr = insert(root->rptr, val);

    return root;
}
void preorder(struct node *root)
{
		if(root!=NULL)
		{

			cout  <<root->data<< " ";
			preorder(root->lptr);
			preorder(root->rptr);
		}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->lptr);
		cout <<root->data<< " ";
		inorder(root->rptr);
	}
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
	postorder(root->lptr);
	postorder(root->rptr);
	cout << root->data << " ";
    }
}
void main()
{
	int ch,val;
	clrscr();
	do
	{
		cout<<"\n1.Insert \n2.Preorder \n3.Inorder \n4.Postorder \n5.Exit";
		cout<<"\n Enter Your Choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter The value => ";
				cin>>val;
				root = insert(root,val);
				cout<<val<<"is Inserted succesfully";
				break;

			case 2:
				cout<<"Preorder Traversal=>";
				preorder(root);
				break;

			case 3:
				cout<<"InOrder Traversal=>";
				inorder(root);
				break;

			case 4:
				cout<<"PostOrder Traversal=>";
				postorder(root);
				break;

			case 5:
				break;

			default:
				cout<<"Invalid Choice";
		}
	}while(ch != 5);
		getch();
}



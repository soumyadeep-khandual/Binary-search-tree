#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *NewNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

node* insert(node *root, int data)
{
	if (root == NULL)
	{
		return NewNode(data);
    }
	else
		if (data <= root->data)
		{
			root->left = insert(root->left, data);
		}
		else
			root->right = insert(root->right, data);
	return root;
}

struct node * minValueNode(struct node* node)
{
	struct node* current = node;
	while (current->left != NULL)
	{
		current = current->left;
	}
    return current;
}

node* deleteNode(node *root, int data)
{
	if (root == NULL)
	{
		return root;
	}

	if (data < root->data)
	{
		root->left = deleteNode(root->left, data);
	}
	else
		if (data > root->data)
		{
			root->right = deleteNode(root->right, data);
		}
		else
		{
			if (root->left == NULL)
			{
				struct node *temp = root->right;
				free(root);
				return temp;
			}
			else
				if (root->right == NULL)
				{
					struct node *temp = root->left;
					free(root);
					return temp;
				}
			struct node *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	return root;
}

void search(node *root, int data)
{
	int pos = 0;
	node *temp = new node;
	temp = root;
	
	while (temp != NULL)
	{
		pos++;
		if (temp->data == data)
		{
			cout << "\nData found at: " << pos;
		}

		else if (temp->data > data)
			temp = temp->left;
	
		else
			temp = temp->right;
	}

	cout << "\n Data not found";
	return;
}

int main()
{
	node *root = NULL; //creating an empty tree
	int n, i, a[20] = { 89, 53, 95, 1, 9, 67, 72, 66, 75, 77, 18, 24, 35, 90, 38, 41, 49, 81, 27, 97 };
	for (i = 0; i < 20; i++)
		root = insert(root, a[i]);

up:
	char ch;
	cout << "Choose:" << '\n' << "a = Insert node" << '\n' << "b = Delete node" << '\n' << "c = Search";
	cin >> ch;

	if (ch == 'a')
	{
		int a;
		cout << "\nEnter node:";
		cin >> a;
		insert(root, a);
	}

	if (ch == 'b')
	{
		int b;
		cout << "\nEnter which node to delete:";
		cin >> b;
		deleteNode(root, b);
	}

	if (ch == 'c')
	{
		cout << "\nEnter the Element to be searched: ";
		cin >> n;

		search(root, n);
	}

	cout << "\n\n\tDo you want to search more...enter choice(y/n)?";
	cin >> ch;
	if (ch == 'y')
		goto up;

	return 0;
}

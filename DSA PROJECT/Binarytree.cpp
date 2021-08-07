#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int sizeoftree(Node *root)
{
	if(root == NULL)
		return 0;
	queue<Node *> q;
	int count = 1;
	q.push(root);
	
	while(!q.empty())
	{
		Node *temp = q.front();
	
		if(temp->left)
		{
			q.push(temp->left);
			count++;
		}
	
		if(temp->right)
		{
			q.push(temp->right);
			count++;
		}
		q.pop();
	}
	
	return count;
}

int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Size of the tree is " <<
		sizeoftree(root) << endl;
	return 0;
}
#pragma once
#include <iostream>
#include <queue>

using namespace std;

enum color  { RED ,BLACK };

struct RBNode {
	int key;
	bool color;
	RBNode* left, * right;

};

RBNode* createRBNode(int data)
{
	RBNode* newnode = new RBNode;
	newnode->key = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->color = RED;
	return newnode;
}
bool isRed(RBNode* x)
{
	if (x == NULL)
		return false;
	return x->color == RED;
}

RBNode* rotateLeft(RBNode* h)
{
	RBNode* x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

RBNode* rotateRight(RBNode* h)
{
	RBNode* x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;

}

void flipColor(RBNode* h)
{
	h->color = RED;
	h->left->color = BLACK;
	h->right->color = BLACK;
}

RBNode* insert(RBNode* root, int key)
{
	
	if (root == NULL)
		return createRBNode(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	if (isRed(root->right) and !isRed(root->left))
		root = rotateLeft(root);
	if (isRed(root->left) and isRed(root->left->left))
		root = rotateRight(root);
	if (isRed(root->right) and isRed(root->left))
		flipColor(root);
	return root;
}

void inOrder(RBNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->key << " ";
	inOrder(root->right);

}

void levelOrder(RBNode* root)
{
	if (root == NULL)
		return;

	RBNode* temp = root;
	queue <RBNode*> q;

	q.push(temp);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		cout << temp->key << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);

	}


}

RBNode* find(RBNode* root, int key)
{
	RBNode* temp = root;
	while (temp)
	{
		if (key < temp->key)
			temp = temp->left;
		else if (key > temp->key)
			temp = temp->right;
		else
			break;
	}
	return temp;
}
RBNode* findMax(RBNode* root)
{
	RBNode* temp = root;
	while (temp and temp->right)
		temp = temp->right;
	return temp;
}

RBNode* findMin(RBNode* root)
{
	RBNode* temp = root;
	while (temp and temp->left)
		temp = temp->left;
	return temp;
}

RBNode* predecessor(RBNode* root, int key)
{
	RBNode* temp = root;
	RBNode* pred = NULL;
	while (temp)
	{
		if (key < temp->key)
			temp = temp->left;
		else if (key > temp->key)
		{
			pred = temp;
			temp = temp->right;
		}
		else
			break;
	}

	if (temp == NULL)
	{
		cout << " Key is not available in tree " << endl;
		return NULL;
	}

	if (temp->left)
		pred = findMax(temp->left);
	return pred;

}

RBNode* successor(RBNode* root, int key)
{
	RBNode* temp = root;
	RBNode* succ = NULL;
	while (temp)
	{
		if (key < temp->key)
		{
			succ = temp;
			temp = temp->left;
		}
		else if (key > temp->key)
		{
			temp = temp->right;
		}
		else
			break;
	}
	if (temp == NULL)
	{
		cout << "Key is not available " << endl;
		return NULL;
	}

	if (temp->right)
		succ = findMin(temp->right);
	return succ;

}
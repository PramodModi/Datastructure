#pragma once
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

struct AVLNode {
	int key;
	int height;
	AVLNode* left, * right;

};

AVLNode* createAVLNode(int data)
{
	AVLNode* newnode = new AVLNode;
	newnode->key = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 0;
	return newnode;
}
int height(AVLNode* x)
{
	if (x == NULL)
		return -1;
	return x->height;
}

AVLNode* rotateLeft(AVLNode* h)
{
	AVLNode* x = h->right;
	h->right = x->left;
	x->left = h;
	h->height = max(height(h->left), height(h->right)) + 1;
	x->height = max(height(x->right), height(h)) + 1;
	return x;
}

AVLNode* rotateRight(AVLNode* h)
{
	AVLNode* x = h->left;
	h->left = x->right;
	x->right = h;
	h->height = max(height(h->left), height(h->right)) + 1;
	x->height = max(height(x->left), height(h)) + 1;
	return x;

}

AVLNode* LRRotation(AVLNode* h)
{
	h->left = rotateLeft(h->left);
	return rotateRight(h);
}

AVLNode* RLRotation(AVLNode* h)
{
	h->right = rotateRight(h->right);
	return rotateLeft(h);
}

AVLNode* insert(AVLNode* root, int key)
{

	if (root == NULL)
		return createAVLNode(key);
	if (key < root->key)
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2)
		{
			if (key < root->left->key)
				root = rotateRight(root);
			else
				root = LRRotation(root);
		}
	}
	else if (key > root->key)
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2)
		{
			if (key > root->right->key)
				root = rotateLeft(root);
			else
				root = RLRotation(root);
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

void inOrder(AVLNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->key << " ";
	inOrder(root->right);

}

void levelOrder(AVLNode* root)
{
	if (root == NULL)
		return;

	AVLNode* temp = root;
	queue <AVLNode*> q;

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

AVLNode* find(AVLNode* root, int key)
{
	AVLNode* temp = root;
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
AVLNode* findMax(AVLNode* root)
{
	AVLNode* temp = root;
	while (temp and temp->right)
		temp = temp->right;
	return temp;
}

AVLNode* findMin(AVLNode* root)
{
	AVLNode* temp = root;
	while (temp and temp->left)
		temp = temp->left;
	return temp;
}

AVLNode* predecessor(AVLNode* root, int key)
{
	AVLNode* temp = root;
	AVLNode* pred = NULL;
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

AVLNode* successor(AVLNode* root, int key)
{
	AVLNode* temp = root;
	AVLNode* succ = NULL;
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
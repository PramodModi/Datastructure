#pragma once
#include <iostream>
#include <queue>

using namespace std;

struct BSTNode {
	int key;
	BSTNode* left, * right;
};

BSTNode* createNode(int data)
{
	BSTNode* newnode = new BSTNode;
	newnode->key = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

BSTNode* insert(BSTNode* root, int key)
{
	BSTNode* newnode = createNode(key);
	if (root == NULL)
		return newnode;
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	return root;
}

BSTNode* insertRec(BSTNode* root, int key)
{
	BSTNode* newnode = createNode(key);
	if (root == NULL)
		return newnode;
	BSTNode* tempnode = root;
	BSTNode* x = NULL;
	while (tempnode)
	{
		x = tempnode;
		if (key < tempnode->key)
			tempnode = tempnode->left;
		else if (key > tempnode->key)
			tempnode = tempnode->right;
	}

	if (key < x->key)
		x->left = newnode;
	else if (key > x->key)
		x->right = newnode;

	return root;
}

void inOrder(BSTNode* root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	cout << root->key << " ";
	inOrder(root->right);

}

void levelOrder(BSTNode* root)
{
	if (root == NULL)
		return;

	BSTNode* temp = root;
	queue <BSTNode*> q;

	q.push(temp);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		cout << temp->key <<" ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);

	}
	

}

BSTNode* find(BSTNode* root, int key)
{
	BSTNode* temp = root;
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
BSTNode* findMax(BSTNode* root)
{
	BSTNode* temp = root;
	while (temp and temp->right)
		temp = temp->right;
	return temp;
}

BSTNode* findMin(BSTNode* root)
{
	BSTNode* temp = root;
	while (temp and temp->left)
		temp = temp->left;
	return temp;
}

BSTNode* deleteNode(BSTNode* root, int key)
{
	if (root == NULL)
		return NULL;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left and root->right)
		{
			BSTNode* temp = findMax(root->left);
			root->key = temp->key;
			root->left = deleteNode(root->left, root->key);
		}
		else
		{
			BSTNode* temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;

			delete temp;
		}
	}
	return root;
}

BSTNode* predecessor(BSTNode* root, int key)
{
	BSTNode* temp = root;
	BSTNode* pred = NULL;
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
	
	if(temp->left)
		pred = findMax(temp->left);
	return pred;

}

BSTNode* successor(BSTNode* root, int key)
{
	BSTNode* temp = root;
	BSTNode* succ = NULL;
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

	if(temp->right)
		succ = findMin(temp->right);
	return succ;

}
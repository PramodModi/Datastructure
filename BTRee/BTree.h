#pragma once
#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 5; //maximum number of keys in any node. This is called degree of BTree

struct BTNode
{
	int* key; //hold array of keys
	BTNode** cp; //hold arrays of pointer of child nodes
	bool leaf; // hold true, if it is leaf node otherwise false
	int n; // number of keys at any time
};

/*
This method will create the BTNode
Input parameter : l => leaf node, if it is true
*/
BTNode* createNode(bool l)
{
	BTNode* node = new BTNode;
	node->leaf = l;
	node->n = 0;
	node->key = new int[SIZE];

	//Number of child node is one more than number of keys.
	node->cp = new BTNode * [SIZE + 1]; 

	for (int i = 0; i < (SIZE + 1); i++)
	{
		node->cp[i] = NULL;
	}

	return node;
}

/*
This is the utility function to insert the key and sort the array
*/

void insert_sort(BTNode* node, int k)
{
	int i = node->n - 1;
	while (i >= 0 and k < node->key[i])
	{
		node->key[i + 1] = node->key[i];
		i--;
	}

	node->key[i+1] = k;
	node->n++;
 }

/*
Print the BTree of given root
*/
void traverse(BTNode* root)
{
	if (root == NULL)
	{
		cout<< "BTree is empty" << endl;
		return;
	}

	cout << endl;
	int i;
	for (i = 0; i < root->n; i++)
	{
		if (root->leaf == false)
		{
			traverse(root->cp[i]);
		}
		cout << root->key[i] << " ";
	}

	if (root->leaf == false)
	{
		traverse(root->cp[i]);
	}
	cout << endl;
}

//Print the B Tree from top to bottom, without recursive method.
void traverse_q(BTNode* root)
{
	if (root == NULL)
	{
		cout << "BTree is empty" << endl;
		return;
	}

	queue <BTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BTNode* temp = q.front();
		q.pop();
		cout << endl;
		for (int i = 0; i < temp->n; i++)
		{
			cout << temp->key[i] << " ";
			if (temp->cp[i] != NULL)
			{
				q.push(temp->cp[i]);
			}
		}
		if (temp->cp[temp->n] != NULL)
		{
			q.push(temp->cp[temp->n]);
		}
	}
	
}

/*
This method is responsible to spilt the given node's child at the position c.
*/
void split(BTNode* node, int c)
{
	//Find the child node, which has to be splitted
	BTNode* c1 = node->cp[c];

	//Split the node at the middle
	int mid_pos = (c1->n) / 2;
	int mid_key = c1->key[mid_pos];
	
	//Create a new node. This node will contains half of the data of c1 node
	BTNode* c2 = createNode(c1->leaf);

	//Copy data of c1 (keys and child nodes) from mid_pos to c2. The exact key at mide_pos will move to parent node
	int j = 0;
	int k = c1->n;
	c1->n--; //Mid key is out

	for (int i = mid_pos + 1; i < k; i++)
	{
		c2->key[j] = c1->key[i];
		c2->n++;
		c1->n--;
		c2->cp[j] = c1->cp[i];
		j++;
	}
	c2->cp[j] = c1->cp[k];

	//Move the mid_key to the parent node.
	//make the position for mid_key

	int i = node->n - 1;
	while (i >= c)
	{
		node->key[i + 1] = node->key[i];
		node->cp[i + 2] = node->cp[i + 1];
		i--;
	}

	//Insert the mid_key at parent. 
	node->key[c] = mid_key;
	node->cp[c + 1] = c2;
	node->n++;
	node->leaf = false;
}

/*
This is the helping insert function.
Insert key into the child node of root.
Input : root is the parent node
		c is the child node of parent node
		key should be inserted
*/
BTNode* insert(BTNode* root, int c, int key)
{
	BTNode* t1 = root; //t1 will hold the root
	BTNode* t2 = root->cp[c]; //t2 is the node, where key has to be inserted
	
	//If t2 is not a leaf node, then 
	//	if t2 is full, then split t2 and then find the right child, where key has to be inserted
	//	if t2 is not full, then find the right child, where key has to be inserted
	int i = c;
	while (t2->leaf == false)
	{
		if (t2->n == SIZE)
		{
			split(t1, c);
			i = t1->n;
			while (i > 0 and key < t1->key[i-1])
				i--;
			
			t2 = t1->cp[i];
		}

		else
		{
			t1 = t2;
			i = t1->n;
			while (i > 0 and key < t1->key[i-1])
				i--;

			t2 = t1->cp[i];
		}
	}
	//When t2 is not a leaf node then
	//	if t2 is full, then split it and find the right child, where key has to be inserted
	//	if t2 is not full the insert the key at the right position.
	if (t2->n == SIZE)
	{
		split(t1, i);
		i = t1->n;
		while (i > 0 and key < t1->key[i-1])
			i--;
		t2 = t1->cp[i];
	}
	insert_sort(t2, key);
	return root;
}

/*
Insert the key at the appropriate node.
Split all nodes, while traversing to the right node
*/

BTNode* insert(BTNode* root, int key)
{
	//If root is null, then insert the first key and return root
	if (root == NULL)
	{
		BTNode* temp = createNode(true);
		temp->key[0] = key;
		temp->n++;
		return temp;
	}

	//If root is full, split the root, insert key at the right child and return the root
	if (root->n == SIZE)
	{
		BTNode* temp = createNode(false);
		temp->cp[0] = root;
		root = temp;
		split(root, 0);
		int i = 0;
		if (key > root->key[0])
			i++;
		return insert(root, i, key);
	}

	//If root is the leaf node, then insert the ket at the right position
	if (root->leaf == true)
	{
		insert_sort(root, key);
		return root;
	}

	//If root is not the leaf node, then find the appropriate child and then insert the key
	
	int i = root->n;
	while (i > 0 and key < root->key[i-1])
		i--;
	return insert(root, i, key);
	
}
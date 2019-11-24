#include "BTree.h"

int main()
{
	BTNode* root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	traverse(root);

	root = insert(root, 60);
	root = insert(root, 70);
	root = insert(root, 80);
	root = insert(root, 90);
	traverse(root);

	root = insert(root, 25);
	root = insert(root, 15);
	root = insert(root, 5);
	traverse(root);

	root = insert(root, 7);
	root = insert(root, 3);
	root = insert(root, 16);
	traverse(root);

	root = insert(root, 32);
	root = insert(root, 35);
	root = insert(root, 45);
	traverse(root);

	root = insert(root, 47);
	root = insert(root, 49);
	root = insert(root, 38);
	traverse(root);

	root = insert(root, 100);
	root = insert(root, 75);
	root = insert(root, 85);
	traverse(root);

	root = insert(root, 1);
	traverse(root);

	root = insert(root, 2);
	traverse(root);

	root = insert(root, 46);
	root = insert(root, 48);
	traverse(root);

	cout << "Traverse in queue" << endl;

	traverse_q(root);

	return 0;
}
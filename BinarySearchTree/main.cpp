#include "BST.h"

int main()
{
	BSTNode* root = NULL;
	/*root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);*/

	root = insertRec(root, 50);
	root = insertRec(root, 30);
	root = insertRec(root, 20);
	root = insertRec(root, 40);
	root = insertRec(root, 70);
	root = insertRec(root, 60);
	insertRec(root, 100);
	insertRec(root, 90);
	insertRec(root, 120);
	insertRec(root, 110);
	insertRec(root, 10);

	inOrder(root);
	cout << endl;

	deleteNode(root, 20);
	inOrder(root);
	cout << endl;

	cout << "Max key = " << findMax(root)->key << endl;
	cout << "Min key = " << findMin(root)->key << endl;

	cout << "Predecessor of 90 : "<<predecessor(root, 90)->key<<endl;
	cout << "Successor of 90 : "<<successor(root, 90)->key << endl;

	cout << "Level Order : " << endl;

	levelOrder(root);
	cout << endl;
	return 0;
}
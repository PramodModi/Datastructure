#include "BST.h"
#include "RedBlack.h"
#include "AVL.h"

int main()
{
	//BSTNode* root = NULL;
	/*root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);*/

	/*root = insertRec(root, 50);
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

	deleteNode(root, 20);*/

	/*BST*/

	cout << "********BST***********" << endl;
	BSTNode* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	insert(root, 100);
	insert(root, 90);
	insert(root, 120);
	insert(root, 110);
	insert(root, 10);
	inOrder(root);
	cout << endl;

	cout << "Max key = " << findMax(root)->key << endl;
	cout << "Min key = " << findMin(root)->key << endl;

	cout << "Predecessor of 90 : " << predecessor(root, 90)->key << endl;
	cout << "Successor of 90 : " << successor(root, 90)->key << endl;

	cout << "Level Order : " << endl;

	levelOrder(root);
	cout << endl;

	/*RB Node*/
	cout << "********RB***********" << endl;
	RBNode* rboot = NULL;
	rboot = insert(rboot, 50);
	rboot = insert(rboot, 30);
	rboot = insert(rboot, 20);
	rboot = insert(rboot, 40);
	rboot = insert(rboot, 70);
	rboot = insert(rboot, 60);
	rboot = insert(rboot, 80);
	rboot = insert(rboot, 100);
	rboot = insert(rboot, 90);
	rboot = insert(rboot, 120);
	rboot = insert(rboot, 110);
	rboot = insert(rboot, 10);
	inOrder(rboot);
	cout << endl;

	cout << "Max key = " << findMax(rboot)->key << endl;
	cout << "Min key = " << findMin(rboot)->key << endl;

	cout << "Predecessor of 90 : "<<predecessor(rboot, 90)->key<<endl;
	cout << "Successor of 90 : "<<successor(rboot, 90)->key << endl;

	cout << "Level Order : " << endl;

	levelOrder(rboot);
	cout << endl;

	/*AVL Node*/
	cout << "********AV Treee***********" << endl;
	AVLNode* av_root = NULL;
	av_root = insert(av_root, 50);
	av_root = insert(av_root, 30);
	av_root = insert(av_root, 20);
	av_root = insert(av_root, 40);
	av_root = insert(av_root, 70);
	av_root = insert(av_root, 60);
	av_root = insert(av_root, 80);
	av_root = insert(av_root, 100);
	av_root = insert(av_root, 90);
	av_root = insert(av_root, 120);
	av_root = insert(av_root, 110);
	av_root = insert(av_root, 10);
	inOrder(av_root);
	cout << endl;

	cout << "Max key = " << findMax(av_root)->key << endl;
	cout << "Min key = " << findMin(av_root)->key << endl;

	cout << "Predecessor of 90 : " << predecessor(av_root, 90)->key << endl;
	cout << "Successor of 90 : " << successor(av_root, 90)->key << endl;

	cout << "Level Order : " << endl;

	levelOrder(av_root);
	cout << endl;
	   
	return 0;
}
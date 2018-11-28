#include <iostream>
#include "classes\BST.h"

using namespace std;


int main() {
	
	BST tree;

	cout << "Insert: " << endl;
	int values[] {4,2,1,3,6,5,7, 1};
	for(int v : values) {
		cout << v << ": " << (tree.insert(v) ? "inserted" : "not inserted (duplicate)") << endl;
	}

	// 2. copy constructor
	cout << "Copy constructor: " << endl;
	BST tree2(tree);
	cout << "Copy of BST created" << endl;
	cout << endl;

	// 3. search
	cout << "Search: " << endl;
	int to_search[] {5,1,9,4,11,3,8,50};
	for(int t : to_search) {
		cout << t << ": " << (tree.search(t) ? "found" : "not found") << endl;
	}
	// 4. remove
	//cout << "Remove: " << endl;
	//int to_delete[] {4,2,3,10};
	//for(int r : to_delete) {
	//	 cout << r << ": " << (tree.remove(r) ? "removed" : "not removed (not found)") << endl; // odkomentujte pre otestovanie
	//}

	//cout << endl;

	// 6. pre-order print
	cout << "Pre-Order print: " << endl;
	tree.printPreOrder();

	cout << endl << endl;

	// 7. in-order print
	cout << "In-Order print: " << endl;
	tree.printInOrder();

	cout << endl << endl;

	// 8. post-order print
	cout << "Post-Order print: " << endl;
	tree.printPostOrder();

	cout << endl << endl;

	// 9. level-order print
	cout << "Level-Order print: " << endl;
	tree.printLevelOrder();

	cout << endl << endl;

	// 10. depth of node
	cout << "Depth of node:" << endl;
	for(int i : values) {
		cout << i << ": " << tree.depth(i) << endl;
	}
	cout << endl;

	// 11. Tree max depth
	cout << "Max depth of tree:" << endl;
	cout << tree.treeDepth() << endl;

	cout << endl;

	// 12. number of nodes in tree
	cout << "Number of nodes in tree:" << endl;
	cout << tree.count() << endl;


	cout << endl;
	system("pause");
	return 0;
}
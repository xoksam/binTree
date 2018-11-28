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
	
	cout << "Hello World" << endl;
	cout << endl;
	system("pause");
	return 0;
}

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
	cout << "Remove: " << endl;
	int to_delete[] {4,2,3,10};
	for(int r : to_delete) {
		 cout << r << ": " << (tree.remove(r) ? "removed" : "not removed (not found)") << endl; // odkomentujte pre otestovanie
	}

	cout << endl;


	cout << endl;
	system("pause");
	return 0;
}
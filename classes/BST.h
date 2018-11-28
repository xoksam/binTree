
#include <iostream>
#include <string>
#include <functional>
using namespace std;

// Tema: Binarny vyhladavaci strom (BST)

// BST je datova struktura umoznujuca rychle vyhladavanie uzlov.
//
// Vlastnost BST:
//  * pre lubovolny uzol U v BST plati:
//      a) uzly v lavom podstrome su mensie ako U
//      b) uzly v pravom podstrome su vacsie ako U
//  * vsetky uzly v BST su unikatne
// Struktura 'Node' sluzi na reprezentaciu jedneho uzla v BST
struct Node {
	// datova cast
	int data;       // hodnota uzla
					// navigacna cast
	Node* parent;   // smernik na rodica
	Node* left;     // smernik na laveho nasledovnika
	Node* right;    // smernik na praveho nasledovnika

					// konstruktor
	Node(int data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr):
		data(data),
		parent(parent),
		left(left),
		right(right) {
	}
};
// Trieda 'BST' sluzi na reprezentaciu BST a jeho operacii.
class BST {
public:
	// default konstruktor BST, ak nezadame root, nastavi sa na nullptr
	BST(Node* root = nullptr):
		root(root) {
	}
	~BST() {}
	bool insert(int data);
	BST(const BST& otherBST);
	Node* search(int data);
	bool remove(int data);
	void removeTree();
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	void printLevelOrder();
	int depth(int data);
	int treeDepth();
	int count();
	void applyFunctionToEachNode(const function<void(Node*)>& fn);
private:
	Node* root; // koren stromu 
	bool insert(Node *curNode, int num);
	void copyTree(Node *root);
	Node *search(Node *curr, int num);
	bool remove(Node *curr, int num);
	Node *findMin(Node *curr);


};
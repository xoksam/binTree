#include "BST.h"

// TODO 1: dokoncite funkciu na vlozenie uzla s hodnotou 'data' do BST
bool BST::insert(int data) {
	return insert(this->root, data);
}
bool BST::insert(Node *curNode, int num) {
	if(!curNode) {
		this->root = new Node(num);
		return true;
	}
	if(curNode->data == num) {
		return false;
	}
	else if(num < curNode->data) {
		if(curNode->left) 
			return insert(curNode->left, num);
		 else 
			curNode->left = new Node(num, curNode);
	} else {
		if(curNode->right)
			return insert(curNode->right, num);
		else
			curNode->right = new Node(num, curNode);
	}

	return true;
}
// TODO 2: dokoncite kopirovaci konstruktor, ktory vytvori BST ako 
// kopiu ineho BST
BST::BST(const BST & otherBST) {
	copyTree(otherBST.root);
}
void BST::copyTree(Node *curr) {
	if(curr) {
		insert(curr->data);
		copyTree(curr->left);
		copyTree(curr->right);
	}
}


// TODO 3: dokoncite funkciu na vyhladanie uzla s hodnotou 'data'
Node *BST::search(int data) {
	return search(this->root, data);
}

Node *BST::search(Node * curr, int num) {
	if(!curr) return nullptr;
	if(curr->data == num) return curr;

	if(num < curr->data) return search(curr->left, num);
	else return search(curr->right, num);

}



// TODO 4: dokoncite funkciu na vymazanie uzla s hodnotou 'data'
bool BST::remove(int data) {
	return false;
}
// TODO 5: dokoncite funkciu na vymazanie celeho BST
void BST::removeTree() {

}
// TODO 6: dokoncite funkciu na vypis stromu stylom pre-order
void BST::printPreOrder() {

}

// TODO 7: dokoncite funkciu na vypis stromu stylom in-order
void BST::printInOrder() {
}
// TODO 8: dokoncite funkciu na vypis stromu stylom post-order
void BST::printPostOrder() {
}

void BST::printLevelOrder() {
}
// TODO 10: dokoncite funkciu na zistenie hlbky uzla s hodnotou 'data'

int BST::depth(int data) {
	return -1;
}
// TODO 11: dokoncite funkciu na zistenie maximalnej hlbky stromu
// Poznamka: koren ma hlbku 0.
int BST::treeDepth() {
	return -1;
}
// TODO 12: dokoncite funkciu na zistenie poctu prvkov v strome
int BST::count() {
	return 0;
}

// TODO 13: dokoncite funkciu 'applyFunction', ktora aplikuje
//
// vami definovanu funkciu 'fn' na kazdy uzol v BST.
//
// Funkcia 'fn' musi byt typu void fn(Node*), kde parametrom je povodny uzol.
// Definujte si lubovolnu funkciu 'fn', ktora splna hore uvedene kriteria.
//
// Priklad definicie funkcie 'fn', ktora vypise potomkov zadaneho uzla:
//
// void fn(Node* node){
//    if(node){
//      cout << "Node: [" << node->data << "]" << endl;
//      cout << " ---> Left child: " << ((node->left) ? to_string(node->left->data) : "n/a") << endl;
//      cout << " ---> Right child: " << ((node->right) ? to_string(node->right->data) : "n/a") << endl;
//    }
// }
// 
// Namiesto definicie funkcie 'fn' mozete pouzit lambda vyraz.

void BST::applyFunctionToEachNode(const function<void(Node*)>& fn) {
}









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

Node *BST::search(Node *curr, int num) {
		// Ak neexistuje current
	if(!curr) return nullptr;
		// Ak sme nasli nami vyhladavany uzol
	if(curr->data == num) return curr;
		// Ak je num < hodnota v current, tak sa vnor do laveho podstromu
	if(num < curr->data) return search(curr->left, num);
	else return search(curr->right, num);
}

bool BST::remove(Node *curr, int num) {
	if(!curr) return false;
	
	// Nasli sme uzol ktory ideme mazat
	if(curr->data == num) {
		// Existuje len lavy alebo ziadny (neexistuje pravy)
		if(!curr->right) {
			if(this->root == curr) this->root = curr->left; // Ak vymazavam root
			else { // Ak vymazavam iny uzol ako root
				// AK je curr lavy potomok rodica
				if(curr->parent->left == curr) curr->parent->left = curr->left;
				else curr->parent->right = curr->left; // Ak je curr pravy potomok rodica
			}
		if(curr->left) curr->left->parent = curr->parent;
		delete curr;
		//return true;
		//Existuje len pravy alebo ziadny (neexistuje lavy)
		} else if(!curr->left) {
			// Ak vymazavam root
			if(this->root == curr) this->root = curr->right;
			else { // Ak vymazavam iny uzol ako root
				if(curr->parent->left == curr) curr->parent->left = curr->right; // Ak je curr lavy potomok rodica
				else curr->parent->right = curr->right; // Ak pravy
			}
			// Ak curr nie je listom, aktualizuje sa rodic na praveho potomka
			if(curr->right) curr->right->parent = curr->parent;
			delete curr;
		} else { // Existuje aj lavy aj pravy potomok
				 // treba najst minimum v pravom podstrome (alebo maximum v lavom podstrome)
				 // a nahradit nim vymazavany prvok
			Node *rightMin = findMin(curr->right);
			curr->data = rightMin->data;
			remove(curr->right, rightMin->data); // Vymazanie najdeneho minima
		}
		return true;
		// Ak je hodnota v curr > num, treba sa vnorit do laveho podstromu
	} else if(curr->data > num) return remove(curr->left, num);
	 // inak do praveho
	else return remove(curr->right, num);
}

Node *BST::findMin(Node *curr) {
	if(curr) {
		while(curr->left) {
			curr = curr->left;
		}
	}
	return curr;
}

// TODO 4: dokoncite funkciu na vymazanie uzla s hodnotou 'data'
bool BST::remove(int data) {
	return remove(this->root, data);
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









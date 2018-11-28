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
		while(curr->left) { // V lavo su prvky vzdy mensie, tak idem stale vlavo ... 
			curr = curr->left;
		}
	}
	return curr;
}

void BST::removeTree(Node *root) {
	if(root) {
		removeTree(root->left); // Rekurzivne zmazem lavu cast podstromu
		removeTree(root->right);// Aj pravu
		delete root; 
	}
}
// Root, Left, Right
void BST::printPreOrder(Node *curr) {
	if(curr) {
		cout << "[" << curr->data << "]"; // Vypisem obsah uzla [root]
		printPreOrder(curr->left);// Potom laveho
		printPreOrder(curr->right);// A praveho
	}
}
// Left, Root, Right
void BST::printInOrder(Node *curr) {
	if(curr) {
		printInOrder(curr->left); // Najskor vypisem mensi, cize lavy
		cout << "[" << curr->data << "]"; // Potom root
		printInOrder(curr->right); // Potom vacsi, aka pravy
	}
}
//Left, Right, Root
void BST::printPostOrder(Node *curr) {
	if(curr) {
		printInOrder(curr->left);  
		printInOrder(curr->right); 
		cout << "[" << curr->data << "]";
	}
}

bool BST::printLevelOrder(Node *curr, int level) {
	if(curr) {
		if(level == 0) {
			cout << "[" << curr->data << "]";
			return true;
		}
		bool isLeft = printLevelOrder(curr->left, level - 1);
		bool isRight = printLevelOrder(curr->right, level - 1);
	
		// HMMMMMMMMmmmmmmmmmmmmmmmmm ...
		//return printLevelOrder(curr->left, level - 1) || printLevelOrder(curr->right, level - 1);

		return isLeft || isRight;
	}
	return false;

}

int BST::depth(Node *curr, int num, int currentDepth) {
	if(curr) {
		if(num == curr->data) return currentDepth; // mame hladany uzol
		// Ak je hladany uzol mensi ako curr, tak sa rekurzivne vnorim do laveho podstromu a zvysim hlbku
		else if(num < curr->data) return depth(curr->left, num, ++currentDepth); 
		else return depth(curr->right, num, ++currentDepth);
	}
	return -1;
}

int BST::count(Node *root, int n) {
	if(root) {
		int left = count(root->left, ++n);
		int right = count(root->right, ++n);
		return left + right;
	}
	return 1; 
}

int BST::treeDepth(Node *root) {
	if(root) {
		//Zistim si hlbky laveho aj praveho podstromu 
		int leftDepth = treeDepth(root->left);
		int rightDepth = treeDepth(root->right);

		// Vratim vacsiu z nich + 1 
		if(leftDepth > rightDepth) return ++leftDepth;
		else return ++rightDepth;
	}
	return 0;
}


// TODO 4: dokoncite funkciu na vymazanie uzla s hodnotou 'data'
bool BST::remove(int data) {
	return remove(this->root, data);
}
// TODO 5: dokoncite funkciu na vymazanie celeho BST
void BST::removeTree() {
	removeTree(this->root);
	this->root = nullptr;
}
// TODO 6: dokoncite funkciu na vypis stromu stylom pre-order
void BST::printPreOrder() {
	printPreOrder(this->root);
}

// TODO 7: dokoncite funkciu na vypis stromu stylom in-order
void BST::printInOrder() {
	printInOrder(this->root);
}
// TODO 8: dokoncite funkciu na vypis stromu stylom post-order
void BST::printPostOrder() {
	printPostOrder(this->root);
}

void BST::printLevelOrder() {
	int i = 0;
	while(printLevelOrder(this->root, i++));

}
// TODO 10: dokoncite funkciu na zistenie hlbky uzla s hodnotou 'data'

int BST::depth(int data) {
	return depth(this->root, data, 0);
}
// TODO 11: dokoncite funkciu na zistenie maximalnej hlbky stromu
// Poznamka: koren ma hlbku 0.
int BST::treeDepth() {
	return treeDepth(this->root) - 1; // -1, lebo koren ma hlbku 0
}
// TODO 12: dokoncite funkciu na zistenie poctu prvkov v strome
int BST::count() {
	return count(this->root, 0) - 1;
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









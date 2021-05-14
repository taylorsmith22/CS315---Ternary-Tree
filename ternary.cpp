#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Creates a struct node that contains two pieces of data and 3 more nodes (its left, middle, and right children)
struct node {
	node *leftChild;
	node *middleChild;
	node *rightChild;
	int data1;
	int data2;
	static node* makeNewNode(int data) { //Creates a new node
		node* myNode = new node;
		myNode->data1 = data; //Sets the first data to be the data that was entered
		myNode->data2 = -1; //Sets the second data to be -1, which means the second data has not been set
		myNode->leftChild = NULL; //Sets all the node's children to NULL
		myNode->middleChild = NULL;
		myNode->rightChild = NULL;
		return myNode;
	}
};

//Creates a class called Ternary
class Ternary
{
	node* root; //Contains one data type (a node that is called root)
	public:
		Ternary();
		void insertTernary(node** aNode, int data);
		node* getRoot();
		void printTernary(node** myNode);
};

//Constructor that sets the root to be NULL
Ternary::Ternary() {
	root = NULL;
}

//Inserts a node into the tree or inserts data into an existing node
void Ternary::insertTernary(node** aNode, int data) {
	if (*aNode == NULL) { //if the node that was inputted is NULL, the data is inserted into that node
		node* newNode = node::makeNewNode(data);
		*aNode = newNode;
		return;
	}
	if ((*aNode)->data2 == -1) { //If the node that was inputted has its second data value equal to -1 then the data is inserted into the nodes second data spot
		if ((*aNode)->data1 > data) {
			(*aNode)->data2 = (*aNode)->data1;
			(*aNode)->data1 = data;
		}
		else 
			(*aNode)->data2 = data;
		return;
	}
	if (data <= (*aNode)->data1) //If the data is less then the node's first data then it traverses through the node's left child
		insertTernary(&( (*aNode)->leftChild ), data);
	else if ((data > (*aNode)->data1) && (data <= (*aNode)->data2)) //If the data is in between the node's first data and second data then it traverses through the node's middle child
		insertTernary(&(  (*aNode)->middleChild ), data);
	else //If the data is greater then the node's second data then it traverses through the node's right child
		insertTernary(&( (*aNode)->rightChild), data);
}

void Ternary::printTernary(node** aNode) {
	if (*aNode != NULL) {
		
		if ((*aNode)->leftChild == NULL) { //Checks to see if the node's left child is NULL
			cout << "(";
		}
		else { //If its not NULL it traverses to the node's left child
			cout << "(";
			printTernary(&( (*aNode)->leftChild));
		}
		cout << (*aNode)->data1; //Prints the node's first data element

		if ((*aNode)->data2 != -1){ //Checks to see if the node has a second data element
			cout << " ";
		}

		if ((*aNode)->middleChild != NULL) { //Checks to see if the node's middle child is NULL 
			printTernary(&( (*aNode)->middleChild));
		}

		if ((*aNode)->data2 != -1) { //Checks to see if the node has a second data element and if it does it prints that element
			cout << (*aNode)->data2;
		}

		if ((*aNode)->rightChild != NULL) { //Checks to see if the node's right child is NULL and if its not it traverses through the node's right child
			cout << " ";
			printTernary(&( (*aNode)->rightChild));
			cout << ")";
		}
		else {
			cout << ") ";
		}
	}
	else //Returns if the node is NULL
		return;
}

//Returns the root of the Ternray Tree
node* Ternary::getRoot() {
	return root;
}

int main(int argc, char *argv[]) {

	int n; //Creates an integer to hold the number of inputs
	int x; //Creates an integer to hold the insert value
	
	if (argc == 2) { //Checks to see if there are two arguments
		n = stoi(argv[1]);
	}

	if (n > 0) { //Checks to see if the command line parameter is valid

		Ternary newTernary; //Creates a ternary tree called newTernary
		node* newNode = newTernary.getRoot(); //Creates a node that holds the value of the ternary trees root
		for (int i = 0; i < n; i++) { //Inserts all the data into the ternary tree
			cin >> x;
			newTernary.insertTernary(&newNode, x);
		}	
		newTernary.printTernary((&newNode)); //Prints the ternary tree in order

		cout << endl;
	}

	else {
		cout << "Invalid command line parameter " << endl;
	}	

	return 0;
}

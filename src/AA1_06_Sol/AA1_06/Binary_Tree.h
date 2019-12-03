#include <iostream>
#include <string>
#include <stack>

struct Node {
public:
	int data;
	Node* left;
	Node* right;
	
	Node() { data = 0; left = nullptr; right = nullptr;
	}

	Node(int value) {
		data = value; left = nullptr; right = nullptr;
	}
};

class BinaryTree {

public:
	Node root; // Privado
	Node* rootPointer;

	BinaryTree() { root.data = 0; rootPointer = &root; }

	BinaryTree(int value) {
		root.data = value;
		rootPointer = &root;
	}

	/*int GetNumNodes() {
		int counter = 0;
		std::stack<Node> myStack;

		//COMPROBAR QUE EL �RBOL EST� VAC�O

		Node* pointer = rootPointer;
		myStack.push(*pointer);
		while (!myStack.empty) {
			pointer = myStack.top;

			myStack.pop;
			counter++;

			if (pointer->left != nullptr) {
				myStack.push(*pointer->left);
				//Node* pointer2 = pointer;
				//pointer = pointer->left;
			}
			
			if(pointer->right != nullptr) {
				myStack.push(*pointer->right);
			}
		
		}

		return counter;
	}*/


	int RecursiveGetNumNodes(Node root) {
		if (root.right != nullptr && root.left != nullptr) { return 1 + RecursiveGetNumNodes(*root.left) + RecursiveGetNumNodes(*root.right); }

		else if (root.left != nullptr && root.right == nullptr) { return 1 + RecursiveGetNumNodes(*root.left); }

		else if (root.right != nullptr && root.left == nullptr) { return 1+ RecursiveGetNumNodes(*root.right); }

		else if (root.right == nullptr && root.left == nullptr) { return 1; }


	}
	
	int GetNumNodes() {
		Node* root = rootPointer;
		int count = 0;
		return RecursiveGetNumNodes(*root);
	
	}

	void PreOrder(Node root) {
		std::cout << root.data << std::endl;
		if (root.left != nullptr) { PreOrder(*root.left); }
		//else {
			if (root.right != nullptr) { PreOrder(*root.right); }
			//else { return; }
		//}
		if (root.right == nullptr && root.left == nullptr) { return; }
	}

	void InOrder(Node root) {
		//if (root.left != nullptr) { /*std::cout << root.left->data << std::endl;*/ InOrder(*root.left); }
		//else { std::cout << root.data << std::endl; }

		if (root.left == nullptr) { std::cout << root.data << std::endl; }
		else { InOrder(*root.left); std::cout << root.data << std::endl; }

		if (root.right != nullptr) { /*std::cout << root.right->data << std::endl;*/ InOrder(*root.right); }
		else { return; }
		//if (root.right == nullptr && root.left == nullptr) { std::cout << root.data << std::endl; return; }
	}

	void PostOrder(Node root) {
		if (root.left != nullptr) {
			PostOrder(*root.left); //std::cout << root.data << std::endl;
		}
	
			//if (root.left->left == nullptr) { std::cout << root.data << std::endl; }

			if (root.right != nullptr) {
				PostOrder(*root.right); /*std::cout << root.right->data << std::endl << root.data << std::endl*/;
			}
			else {
				std::cout << root.right->data << root.data << std::endl;
			
		}
			return;
		 

	}
};


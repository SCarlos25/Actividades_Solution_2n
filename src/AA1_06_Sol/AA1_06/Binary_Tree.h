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

		//COMPROBAR QUE EL ÁRBOL ESTÁ VACÍO

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

	
	}

};
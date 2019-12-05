#include "Binary_Tree.h"

int main() {
	BinaryTree tree(3);		// ROOT

	tree.root.left = new Node(2);
	tree.root.right = new Node(1);
	tree.root.left->left = new Node(6);
	tree.root.right->left = new Node(4);
	tree.root.right->right = new Node(5);
	tree.root.left->left->left = new Node(7);
	tree.root.left->right = new Node(3);
	//tree.root.right->left->left = new Node(6);

	int num = 0;
	num = tree.GetNumNodes();

	//tree.InOrder(tree.root);
	//tree.PreOrder(tree.root);
	//tree.PostOrder(tree.root);

	std::cout << tree.GetNum(tree.root) << std::endl;

	std::cout << tree.GetHeight(tree.root) << std::endl;
}
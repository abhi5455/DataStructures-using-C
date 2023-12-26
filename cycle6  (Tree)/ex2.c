#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *createNode(int value) {
	struct TreeNode *newNode = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int value) {
	if (root == NULL) {
		return createNode(value);
	}
	if (value < root->data) {
		root->left = insertNode(root->left, value);
	} else if (value > root->data) {
		root->right = insertNode(root->right, value);
	}
	return root;
}

void inorderTraversal(struct TreeNode *root) {
	if (root != NULL) {
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

void preorderTraversal(struct TreeNode *root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void postorderTraversal(struct TreeNode *root) {
	if (root != NULL) {
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ", root->data);
	}
}

struct TreeNode *deleteNode(struct TreeNode *root, int value) {
	if (root == NULL)
		return root;
	if (root->data > value)
		root->left = deleteNode(root->left, value);
	else if (root->data < value)
		root->right = deleteNode(root->right, value);
	else {
		if (root->left == NULL) {
			struct TreeNode *temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL) {
			struct TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		struct TreeNode *succParent = root;
		struct TreeNode *succ = root->right;
		while (succ->left != NULL) {
			succParent = succ;
			succ = succ->left;
		}

		root->data = succ->data;
		if (succParent != root)
			succParent->left = deleteNode(succParent->left, succ->data);
		else
			succParent->right = deleteNode(succParent->right, succ->data);
	}
	return root;
}

int countLeafNodes(struct TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void sortInputNumbers(struct TreeNode *root) {
	inorderTraversal(root);
}

int main() {
	struct TreeNode *root = NULL;
	int choice, value;
	printf("1. Insert node\n");
	printf("2. Inorder\n");
	printf("3. Preorder\n");
	printf("4. Postorder\n");
	printf("5. Delete node\n");
	printf("6. No of leaf nodes\n");
	printf("7. Sort inputs\n");
	printf("8. Exit\n");
	do {
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				root = insertNode(root, value);
				break;
			case 2:
				printf("Inorder traversal: ");
				inorderTraversal(root);
				printf("\n");
				break;
			case 3:
				printf("Preorder traversal: ");
				preorderTraversal(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder traversal: ");
				postorderTraversal(root);
				printf("\n");
				break;
			case 5:
				printf("Enter key: ");
				scanf("%d", &value);
				deleteNode(root, value);
				break;
			case 6:
				printf("Number of leaf nodes: %d\n", countLeafNodes(root));
				break;
			case 7:
				printf("Sorted input numbers: ");
				sortInputNumbers(root);
				printf("\n");
				break;
			case 8:
				printf("Exiting program...\n");
				break;
			default:
				printf("Invalid choice\n");
		}
	} while (choice != 8);
	return 0;
}


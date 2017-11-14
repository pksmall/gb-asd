#pragma once

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

#include "nodedef.h"
#include "stack.h"

Node *create_node(int val) 
{
	Node *tree = (Node *)malloc(sizeof(Node));
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;

	tree->data = val;

	return tree;
}

void print_tree(Node *root) 
{
	if (root) {
		printf("%d", root->data);
		if (root->left || root->right) {
			printf("(");

			if (root->left) {
				print_tree(root->left);
			}
			else {
				printf("NULL");
			}
			printf(",");
			if (root->right) {
				print_tree(root->right);
			}
			else {
				printf("NULL");
			}

			printf(")\n");
		}
	}
}

void preorder_travers(Node *root) 
{
	if (root) {
		printf("%d", root->data);

		preorder_travers(root->left);
		preorder_travers(root->right);

	}
}

void postorder_travers(Node *root) 
{
	if (root) {
		preorder_travers(root->left);
		preorder_travers(root->right);

		printf("%d", root->data);
	}
}

// inorder travers 
// обход симетрически
void inorder_travers(Node *root) 
{
	if (root) {
		inorder_travers(root->left);
		
		printf("%d", root->data);
		
		inorder_travers(root->right);

	}
}

// Итеративная реализация обхода в глубину требует использования стека.
void iterpreorder_travers(Node *root) 
{
	Stack *ps = createStack();
	while (ps->size != 0 || root != NULL) {
		if (root != NULL) {
			printf("%d", root->data);
			if (root->right) {
				push(ps, root->right);
			}
			root = root->left;
		}
		else {
			root = pop(ps);
		}
	}
	freeStack(&ps);
}

void iternnorder_travers(Node *root) 
{
	Stack *ps = createStack();
	while (ps->size != 0 || root != NULL) {
		if (root != NULL) {
			push(ps, root);
			root = root->left;
		}
		else {
			root = pop(ps);
			printf("%d", root->data);
			root = root->right;
		}
	}
	freeStack(&ps);
}

void iterpostorder_travers(Node *root) 
{
	Stack *ps = createStack();
	Node *lnp = NULL;
	Node *peekn = NULL;

	while (!ps->size == 0 || root != NULL) {
		if (root) {
			push(ps, root);
			root = root->left;
		}
		else {
			peekn = peek(ps);
			if (peekn->right && lnp != peekn->right) {
				root = peekn->right;
			}
			else {
				pop(ps);
				printf("%d", peekn->data);
				lnp = peekn;
			}
		}
	}

	freeStack(&ps);
}

// width travers
// обход в ширину
void width_travers(Node *root) 
{
	if (root) {
		width_travers(root->left);

		printf("%d", root->data);

		width_travers(root->right);
	}
}

char *a = "12345678";

Node *Tree(int n) 
{
	Node *newNode;

	int x, nl, nr;


	if (n == 0) {
		newNode = NULL;
	}
	else {
		// scanf()
		x = (int)*a - 48; // workaround to ger original number from the string
		a++;

		nl = n / 2;
		nr = n - nl - 1;

		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = x;
		newNode->left = Tree(nl);
		newNode->right = Tree(nr);
	}

	return newNode;
}

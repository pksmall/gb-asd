#pragma once

#include <stddef.h>
#include <stdio.h>
#include <malloc.h>

#include "nodedef.h"
#include "stack.h"

biNode *create_biNode(int val) 
{
	biNode *tree = (biNode *)malloc(sizeof(biNode));
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;

	tree->data = val;

	return tree;
}

void print_tree(biNode *root) 
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

void preorder_travers(biNode *root) 
{
	if (root) {
		printf("%d", root->data);

		preorder_travers(root->left);
		preorder_travers(root->right);

	}
}

void postorder_travers(biNode *root) 
{
	if (root) {
		preorder_travers(root->left);
		preorder_travers(root->right);

		printf("%d", root->data);
	}
}

// inorder travers 
// обход симетрически
void inorder_travers(biNode *root) 
{
	if (root) {
		inorder_travers(root->left);
		
		printf("%d", root->data);
		
		inorder_travers(root->right);

	}
}

// Итеративная реализация обхода в глубину требует использования стека.
// inter preorder
// Прямой обход
void iterpreorder_travers(biNode *root) 
{
	Stack *ps = createStack();
	while (ps->size != 0 || root != NULL) {
		if (root != NULL) {
			printf("%d", root->data);
			if (root->right) {
				pushStack(ps, root->right);
			}
			root = root->left;
		}
		else {
			root = popStack(ps);
		}
	}
	freeStack(&ps);
}

// inter in order
// Поперечный обход
void iterinorder_travers(biNode *root) 
{
	Stack *ps = createStack();
	while (ps->size != 0 || root != NULL) {
		if (root != NULL) {
			pushStack(ps, root);
			root = root->left;
		}
		else {
			root = popStack(ps);
			printf("%d", root->data);
			root = root->right;
		}
	}
	freeStack(&ps);
}

// inter post order
// Обратный обход
void iterpostorder_travers(biNode *root) 
{
	Stack *ps = createStack();
	biNode *lnp = NULL;
	biNode *peekn = NULL;

	while (!ps->size == 0 || root != NULL) {
		if (root) {
			pushStack(ps, root);
			root = root->left;
		}
		else {
			peekn = peekStack(ps);
			if (peekn->right && lnp != peekn->right) {
				root = peekn->right;
			}
			else {
				popStack(ps);
				printf("%d", peekn->data);
				lnp = peekn;
			}
		}
	}
	freeStack(&ps);
}

// width travers
// обход в ширину
// сначала мы посещаем корень, затем, слева направо, все ветви первого уровня, 
// затем все ветви второго уровня и т.д.
void width_travers(biNode *root) 
{
	queLinkedList *q = createQueLinkedList();
	pushFront(q, root);
	while (q->size != 0) {
		biNode *tmp = (biNode*) popFront(q);
		printf("%d", tmp->data);
		if (tmp->left) {
			pushFront(q, tmp->left);
		}
		if (tmp->right) {
			pushFront(q, tmp->right);
		}
	}
	deleteQueLinkedList(&q);
}

void deleteTree(biNode **root) 
{
	if (*root) {
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
	}
}

char *a = "12345678";

biNode *Tree(int n) 
{
	biNode *newbiNode;

	int x, nl, nr;


	if (n == 0) {
		newbiNode = NULL;
	}
	else {
		// scanf()
		x = (int)*a - 48; // workaround to ger original number from the string
		a++;

		nl = n / 2;
		nr = n - nl - 1;

		newbiNode = (biNode *)malloc(sizeof(biNode));
		newbiNode->data = x;
		newbiNode->left = Tree(nl);
		newbiNode->right = Tree(nr);
	}

	return newbiNode;
}

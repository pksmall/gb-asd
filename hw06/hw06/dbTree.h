#pragma once
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include "nodedef.h"
#include "stack.h"

int strToHash(char *str, int len)
{
	unsigned int seed = 31;
	unsigned int hash = 0;

	for (int i = 0; i < len; str++, i++)
	{
		hash = (hash * seed) + *str + i;
	}
	return hash;
}

dbNode *create_dbNode(char *name, int age, int tabid)
{
	dbNode *tree = (dbNode *)malloc(sizeof(dbNode));
	tree->parent = NULL;
	tree->left = NULL;
	tree->right = NULL;

	tree->name = name;
	tree->hashName = strToHash(name, strlen(name));
	tree->age = age;
	tree->tabid = tabid;
	tree->idHash = strToHash(name, strlen(name)) + age + tabid;

	return tree;
}

void printDb(dbNode *root)
{
	if (root) {
		printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);
		printDb(root->left);
		printDb(root->right);
	}
}

// search by name
void getDbNodeByName(dbNode *root, char *value)
{
	int idxValue = strToHash(value, strlen(value));
	if (root) {
		if (root->hashName == idxValue) {
			printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);
			return;
		}
		else {
			getDbNodeByName(root->left, value);
			getDbNodeByName(root->right, value);
		}
	}
}

// search by age
void getDbNodeByAge(dbNode *root, int value)
{
	if (root) {
		if (root->age == value) {
			printf("#%d\t Name: %s\t Age: %d\t TabId: %d\n", root->idHash, root->name, root->age, root->tabid);
			return;
		}
		else {
			getDbNodeByAge(root->left, value);
			getDbNodeByAge(root->right, value);
		}
	}
}

dbNode* getFreeDbNode(dbNode *parent, char *name, int age, int tabid)
{
	dbNode* tmp = (dbNode*) malloc(sizeof(dbNode));
	tmp->left = tmp->right = NULL;
	
	tmp->name = name;
	tmp->hashName = strToHash(name, strlen(name));
	tmp->age = age;
	tmp->tabid = tabid;
	tmp->idHash = strToHash(name, strlen(name)) + age + tabid;

	tmp->parent = parent;
	return tmp;
}

void insertDbNode(dbNode **head, char *name, int age, int tabid)
{
	dbNode *tmp;

	if (*head == NULL) {
		*head = getFreeDbNode(NULL, name, age, tabid);
		return;
	}

	tmp = *head;
	int idHash = strToHash(name, strlen(name)) + age + tabid;
	while (tmp) {
		//printf("%d -- %d\n", value, tmp->data);
		if (idHash > tmp->idHash) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			}
			else {
				tmp->right = getFreeDbNode(tmp, name, age, tabid);
				return;
			}
		}
		else if (idHash < tmp->idHash) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			}
			else {
				tmp->left = getFreeDbNode(tmp, name, age, tabid);
				return;
			}
		}
		else {
			printf("Wrong biNode.\n");
			exit(-2);
		}
	}
}

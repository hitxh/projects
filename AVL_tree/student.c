#include <stdio.h>
#include <string.h>
#include "avl_tree.h"

typedef struct {
	char *login;
	int grade;
} STUDENT;


void print_node_data(AVLTreeNode *node) {
	STUDENT *value = avl_tree_node_value(node);
	printf("[key:%s, login:%s, grade:%d]\n", 
			(char *) avl_tree_node_key(node), value->login, value->grade);
}

int login_compare(const char *v1, const char *v2) {
	return strcmp(v1, v2);
}

int main(void) {

	// create three students
	STUDENT s1 = {.login = "Adam", .grade = 42};
	STUDENT s2 = {.login = "Michal", .grade = 32};
	STUDENT s3 = {.login = "Xixao", .grade = 82};
	STUDENT s4 = {.login = "Oto", .grade = 82};

	// create new AVL tree
	AVLTree *tree = avl_tree_new((AVLTreeCompareFunc) login_compare);

	avl_tree_insert(tree, s1.login, &s1);
	avl_tree_insert(tree, s3.login, &s3);
	avl_tree_insert(tree, s2.login, &s2);

	puts("> structure of AVL tree:");
	avl_tree_print(tree, print_node_data);

	puts("\n> remove student: Adam");
	avl_tree_remove(tree, s1.login);
	avl_tree_print(tree, print_node_data);

	puts("\n> add student: Oto");
	avl_tree_insert(tree, s4.login, &s4);
	avl_tree_print(tree, print_node_data);

	avl_tree_free(tree);
	return 0;
}


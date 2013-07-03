#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include <assert.h>

#define LEN(x)	(sizeof(x)/sizeof(x[0]))

int int_compare(void *vlocation1, void *vlocation2) {
	int *location1 = (int *) vlocation1;
	int *location2 = (int *) vlocation2;

	if (*location1 < *location2)
		return -1;
	else if (*location1 > *location2)
		return 1;
	else
		return 0;
}

void print_node_data(AVLTreeNode *node) {
	int *value = avl_tree_node_value(node);
	int *key = avl_tree_node_key(node);
	printf("[key:%d, data:%d]\n", *key, *value);
}

int main(void) {

	AVLTree *tree;
	AVLTreeNode *node;
	unsigned int i;
	int *value;

	int keys[] = {4, 2, 5, 1, 3, 3};
	int data[] = {1, 2, 3, 4, 5, 6};

	/* create new AVL tree */
	tree = avl_tree_new((AVLTreeCompareFunc) int_compare);

	/* Insert some data into the tree. 
	 * You have to check if the key already exists in tree or not. If the key is
	 * already in tree then you have to actualize its data by your self.
	 * Warning: DO NOT INSERT SAME KEYS!
	 */
	printf("insert some data into the tree (items: %d)\n", LEN(keys));
	for (i = 0; i < LEN(keys); i++) {
		if (avl_tree_lookup_node(tree, &keys[i]) != NULL)
			printf("node with key %d is already in AVL tree\n", keys[i]);
		else
			avl_tree_insert(tree, &keys[i], &data[i]);
	}
	avl_tree_print(tree, print_node_data); putchar('\n');

	/* remove node with key 5 */
	i = 5;
	printf("remove node with key %d\n", i);
	node = avl_tree_lookup_node(tree, &i);
	if (node != NULL)
		avl_tree_remove_node(tree, node);
	avl_tree_print(tree, print_node_data); putchar('\n');
	
	/* get value of node with key 3 */
	i = 1;
	AVLTreeValue v = avl_tree_lookup(tree, &i);
	if (v != NULL) {
		value = (int *) v;
		printf("value of node with key %d is %d\n", i, *value);
	}
	else
		printf("there is no node with key %d\n", i);
	
	printf("tree contains %d nodes\n", avl_tree_num_entries(tree));
	/* Dispose entire tree */
	avl_tree_free(tree);
	return 0;
}


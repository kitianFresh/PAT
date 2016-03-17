#include <stdio.h>
#include <stdlib.h>
#define N 1000
static int layer_nodes[1000] = {0};
int layer = 0;
typedef struct BSTNode {
	int key;
	int layer;
	struct BSTNode *left;
	struct BSTNode *right;
} BSTNode;

void initBST(BSTNode **bst, int n);
BSTNode *insertBST(BSTNode **bst, int key);
void preorder(BSTNode *bst);

int main(){
	BSTNode *bst;
	int i, n1, n2, n, lowest, sublow;	
	scanf("%d", &n);
	initBST(&bst, n);
	preorder(bst);
	for (i = 1; layer_nodes[i]; i++)
		;
	lowest = i - 1;
	sublow = i - 2;
	n1 = layer_nodes[lowest];
	n2 = layer_nodes[sublow];
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	return 0;
}

void preorder(BSTNode *bst) {
	if (NULL != bst) {
		layer_nodes[bst->layer] ++;
		preorder(bst->left);
		preorder(bst->right);
	}
	else
		return;
}

void initBST(BSTNode **bst, int n) {
	int i, key;
	*bst = NULL;
	for (i = 0; i < n; i++) {
		scanf("%d", &key);
		insertBST(bst, key);
	}
}

BSTNode *insertBST(BSTNode **bst, int key) {
	layer ++;
	if (NULL == *bst) { 
		*bst = (BSTNode*)malloc(sizeof(BSTNode));
		(*bst)->key = key;
		(*bst)->layer = layer;
		(*bst)->left = NULL;
		(*bst)->right = NULL;
		layer = 0;
		return *bst;
	}
	else {
		if ((*bst)->key >= key)
			insertBST(&(*bst)->left, key);
		else
			insertBST(&(*bst)->right, key);
	}
}

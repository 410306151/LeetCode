#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countLayer(struct TreeNode* root){
	// This function return layers from current node
	int left, right;

	if(root == NULL){
		return 0;
	}

	left = countLayer(root->left);
	right = countLayer(root->right);

	return fmax(left, right) + 1;
}

int infect(struct TreeNode* root, int start, int *returnCount, int *layer){
	int left, right;

	if(root == NULL){
		return 0;
	}
	if(root->val == start){
		// Found the target, checking which side has deeper layer
		*returnCount = countLayer(root) - 1;
		return -1;
	}
	if(root->left == NULL && root->right == NULL){
		return 1;
	}

	left = infect(root->left, start, returnCount, layer);
	right = infect(root->right, start, returnCount, layer);
	if(left == -1){
		// The target is in left side of current node, checking layers of right node
		// Return -1 becuase found the target from current node
		// *layer + 1 becuase we need to trace back how many nodes we need to infect to current node
		*layer += 1;
		*returnCount = fmax(*returnCount, right + *layer);

		return -1;
	}
	if(right == -1){
		// The target is in right side of current node, checking layers of left node
		// Return -1 becuase found the target from current node
		// *layer + 1 becuase we need to trace back how many nodes we need to infect to current node
		*layer += 1;
		*returnCount = fmax(*returnCount, left + *layer);

		return -1;
	}

	return fmax(left, right) + 1;
}

int amountOfTime(struct TreeNode* root, int start){
	int ans = 0, layer = 0;

	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return 0;
	}
	if(root->val == start){
		return countLayer(root) - 1;
	}
	infect(root, start, &ans, &layer);

	return ans;
}
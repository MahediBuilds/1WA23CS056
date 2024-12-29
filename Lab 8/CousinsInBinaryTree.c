#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree() {
    int val;
    printf("\nEnter the root value (or -1 for NULL): ");
    scanf("%d", &val);

    if (val == -1) return NULL;

    TreeNode* root = createNode(val);
    TreeNode** queue = (TreeNode**)malloc(100 * sizeof(TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("\nEnter left child of %d (or -1 for NULL): ", current->val);
        scanf("%d", &val);
        if (val != -1) {
            current->left = createNode(val);
            queue[rear++] = current->left;
        }

        printf("Enter right child of %d (or -1 for NULL): ", current->val);
        scanf("%d", &val);
        if (val != -1) {
            current->right = createNode(val);
            queue[rear++] = current->right;
        }
    }

    free(queue);
    return root;
}

bool isCousins(TreeNode* root, int x, int y) {
    if (root == NULL) return false;

    typedef struct {
        TreeNode* node;
        TreeNode* parent;
        int depth;
    } QueueNode;

    QueueNode* queue = (QueueNode*)malloc(100 * sizeof(QueueNode));
    int front = 0, rear = 0;

    queue[rear++] = (QueueNode){root, NULL, 0};

    while (front < rear) {
        int size = rear - front;
        int xDepth = -1, yDepth = -1;
        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;

        for (int i = 0; i < size; i++) {
            QueueNode current = queue[front++];
            TreeNode* node = current.node;
            TreeNode* parent = current.parent;
            int depth = current.depth;

            if (node->val == x) {
                xDepth = depth;
                xParent = parent;
            }
            if (node->val == y) {
                yDepth = depth;
                yParent = parent;
            }

            if (node->left) 
                queue[rear++] = (QueueNode){node->left, node, depth + 1};
            if (node->right) 
                queue[rear++] = (QueueNode){node->right, node, depth + 1};
        }

        if (xDepth != -1 && yDepth != -1) {
            free(queue);
            return (xDepth == yDepth) && (xParent != yParent);
        }
    }

    free(queue);
    return false;
}

void freeTree(TreeNode* root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = buildTree();

    int x, y;
    printf("\nEnter the two nodes to check if they are cousins: ");
    scanf("%d %d", &x, &y);

    printf("\nProcessing...\n");
    if (isCousins(root, x, y)) {
        printf("\nResult: Yes, the nodes %d and %d are cousins.\n", x, y);
    } else {
        printf("\nResult: No, the nodes %d and %d are not cousins.\n", x, y);
    }

    freeTree(root);
    return 0;
}


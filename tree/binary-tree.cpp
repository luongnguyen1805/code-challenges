
#include <stdio.h>

class TreeNode {
    public:
        int value;
        TreeNode* leftNode;
        TreeNode* rightNode;

        TreeNode(){
            value = -1;
            leftNode = NULL;
            rightNode = NULL;
        }
};

void printNode(TreeNode* rootNode){

    int valLeft = -1;
    if (rootNode->leftNode != NULL) {
        valLeft = rootNode->leftNode->value;
        printNode(rootNode->leftNode);
    }

    int valRight = -1;
    if (rootNode->rightNode != NULL) {
        valRight = rootNode->rightNode->value;
        printNode(rootNode->rightNode);
    }
    
    printf("\nTree Node: %d=>{%d,%d}",rootNode->value,valLeft,valRight);
};

TreeNode* createNode(int (&arr)[], int begin, int end){
 
    int count = end - begin + 1;
    if (count < 1) return NULL;

    if (count == 1) {
        TreeNode* anode = new TreeNode();
        anode->value = arr[begin];
        return anode;
    }
    
    int mid = begin + count/2;
    TreeNode* anode = new TreeNode();
    anode->value = arr[mid];

    if (mid-1 >= begin)
        anode->leftNode = createNode(arr, begin, mid-1);
        
    if (end > mid)
        anode->rightNode = createNode(arr, mid+1, end);

    return anode;
};

int main() {

    printf("Transform array of int to tree");

    int arr[] = {9};
    int size = sizeof(arr)/sizeof(*arr);

    TreeNode* rootNode = createNode(arr, 0, size-1);

    printf("\nTree built\n");
    
    printNode(rootNode);

    return 1;
}


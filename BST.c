#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct Node *insertNode(struct Node *root, int value){
    if(root==NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left=insertNode(root->left,value);
    }
    else if(value > root->data){
        root->right=insertNode(root->right,value);
    }

    return root;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

struct Node *minNode(struct Node *node){
    struct Node *current=node;
    while(current && current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int value){
    if(root==NULL){
        return root;
    }

    if(value < root->data){
        root->left=deleteNode(root->left,value);
        return root;
    }
    else if(value > root->data){
        root->right=deleteNode(root->right,value);
        return root;
    }
    else{
        if(root->left ==NULL){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node *temp=root->left;
            free(root);
            return temp;
        }
        struct Node *temp=minNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int countLeafNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countTotalNodes(struct Node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int height(struct Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftheight=height(root->left);
        int rightheight=height(root->right);

        if(leftheight > rightheight){
            return (leftheight + 1);
        }
        else{
            return (rightheight + 1);
        }
    } 
}

struct Node *searchNode(struct Node *root, int value){
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    } 
    else {
        return searchNode(root->right, value);
    }
}



int main(){
    struct Node *root = NULL;
    int option;
    int range;
    int data=0;

    while(1){
        printf("\n1.Insert a node 2.Inorder display of nodes 3.Delete a node 4.Count of leaf nodes 5.Count of all nodes 6.Node with least value 7.Search for a node 8.Find height of tree 9.Exit");
        printf("\nEnter the operation you want to perform: ");
        scanf("%d",&option);

        switch(option){
            case 1:
            printf("\nEnter the number of elements you want to insert: ");
            scanf("%d",&range);
            int arr[10];
            for(int i=0;i<range;i++){
                printf("\nEnter the data for %d element ",i+1);
                scanf("%d",&arr[i]);
            }
            for(int i=0;i<range;i++){
                root=insertNode(root,arr[i]);
            }
            break;

            case 2:
            printf("\nIn order traversal of the tree: ");
            inorder(root);
            printf("\n");
            break;

            case 3:
            printf("\nEnter the node value you want to delete: ");
            scanf("%d",&data);
            root=deleteNode(root,data);
            printf("\nNode deleted");
            break;

            case 4:
            printf("\nThe number of leaf nodes in the tree: %d", countLeafNodes(root));
            break;

            case 5:
            printf("\nThe total number of nodes in the tree: %d", countTotalNodes(root));
            break;

            case 6:
            struct Node *min=minNode(root);
            if(min!=NULL){
                printf("\nThe node with the minimum value is %d",min->data);
            }
            else{
                printf("\nNo node found");
            }

            case 7:
            printf("\nEnter the node value you want to search: ");
            scanf("%d", &data);
            struct Node *searchResult = searchNode(root, data);
            if (searchResult != NULL) {
                printf("\nNode with value %d found in the tree.", data);
            } 
            else {
                printf("\nNode with value %d not found in the tree.", data);
            }
            break;

            case 8:
            printf("\nThe height of the tree is %d",height(root));
            break;

            case 9:
            exit(0);
            break;
        }
    }
    return 0;
}
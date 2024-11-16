
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define TRUE 1
#define FALSE 0

struct Node{
    int data;
    struct Node* next;
}Node;


int getLength(struct Node* list){
    int length = 0;
    struct Node* current = list;
    while(current != NULL){
        current = current->next;
        length +=1;
    }
    return length;
}

void insertAtTheBeginning(struct Node** list, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *list;
    *list = new_node;
    // free(temp_node);
    
}



void insertAtTheEnd(struct Node** list, int data){
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if(*list == NULL){
        *list = new_node;
        return;
    }
    
    struct Node* temp_node = *list;
    while(temp_node->next != NULL){
        temp_node = temp_node->next;
    }
    
    temp_node->next = new_node;
}


void findValue(struct Node* list, int data){
    int found = FALSE;

    struct Node* current = *&list;
    if (current == NULL){
        printf("Value not found, list is empty\n");
    }

    while (current != NULL){
        if (current->data == data){
            found = TRUE;
        }
        current = current->next;
    }
    if (found){
        printf("Value [%d] has been found in the list\n", data);
    }
    else{
        printf("Value [%d] is not in the list\n", data);
    }
}


void deleteValue(struct Node** list, int data){
    if (list != NULL){
        struct Node* target_node = *list;
        struct Node* previous_node = NULL;
        while (target_node != NULL){
            if (target_node->data == data){
                break;
            }
            previous_node = target_node;
            target_node = target_node->next;
        }
        if (target_node == NULL){
            printf("Value [%d] is not in the list\n", data);
        }
        else if (previous_node == NULL){
            *list = (*list)->next;
            free(target_node);
            printf("value [%d] has been deleted\n", data);
        }
        else{
            previous_node->next = target_node->next;
            free(target_node);
            printf("value [%d] has been deleted\n", data);
        }
    }
}

void printList(struct Node* list){
    struct Node* current = list;
    while (current != NULL){
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    
    printf("NULL \n");
}


void bubbleSort(int data[], int size){
    int temp = 0;
    for (int i = 0; i<size; i++){
        for (int j = 0; j<size-1; ++j){
            if (data[j] > data[j+1]){
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void printSortedList(struct Node* list){
    int len = getLength(list);
    int data[len];
    struct Node* current = list;
    for (int i = 0; i < len; ++i){
        data[i] = current->data;
        current = current->next;
    }
    bubbleSort(data, len);
    for (int i = 0; i < len; i++){
        printf("[%d] -> ", data[i]);
    }
    printf("NULL\n");
}


void menu(struct Node* list){
    char input[30];

    printf(".:Linked List Menu:.\n");
    printf(" 1.) Enter Data \n 2.) Print List \n 3.) Find Value \n 4.) Delete Value \n 5.) Print Sorted List \n 0.) Exit \n > ");
    fgets(input, sizeof(input), stdin);
    int len = strlen(input);
    input[len - 1] = '\0';
    int integer;
    integer = atoi(input);
    while (integer != 0){
        if (integer == 1){
            char add[30];
            printf("What number would you like to add: ");
            fgets(add, sizeof(add), stdin);
            int length = strlen(add);
            add[length - 1] = '\0';
            int num;
            num = atoi(add);
            insertAtTheBeginning(&list, num);
            printList(list);
        }
        else if (integer == 2){
            printList(list);
    
        }
        else if (integer == 3){
            char add[30];
            printf("What number do you want to find: ");
            fgets(add, sizeof(add), stdin);
            int length = strlen(add);
            add[length - 1] = '\0';
            int num;
            num = atoi(add);
            findValue(list, num);
        }
        else if (integer == 4){
            char add[30];
            printf("What number do you want to delete: ");
            fgets(add, sizeof(add), stdin);
            int length = strlen(add);
            add[length - 1] = '\0';
            int num;
            num = atoi(add);
            deleteValue(&list, num);
        }
        else if (integer == 5){
            printSortedList(list);
        }
        printf(".:Linked List Menu:.\n");
        printf(" 1.) Enter Data \n 2.) Print List \n 3.) Find Value \n 4.) Delete Value \n 5.) Print Sorted List \n 0.) Exit \n > ");
        fgets(input, sizeof(input), stdin);
        int len = strlen(input);
        input[len - 1] = '\0';
        integer = atoi(input);
    }
}


int main(){
    struct Node* list = NULL;
    
    insertAtTheBeginning(&list, 10);
    insertAtTheBeginning(&list, 1);
    insertAtTheBeginning(&list, 9);
    insertAtTheBeginning(&list, 30);
    insertAtTheBeginning(&list, 999);


    printList(list);
    
    insertAtTheEnd(&list, 1000);

    printList(list);


    findValue(list, 2);

    deleteValue(&list, 122);
    printList(list);
    printSortedList(list);
    
    menu(list);


    return 0;
}

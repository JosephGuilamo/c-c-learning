/*
    Use the linear linked list code to store a randomly generated set of 100 integers.
    Now write a routine that will rearrange the list in sorted order of these values.
    Note you might want to use bubble sort to do this. Print these values in rows of 5 on the screen.

    Author: Jose Miguel Garcia.
    Date: 27/10/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct integer_list {
    int num;
    struct integer_list *next;
} Integer_list;

Integer_list *generate_array_random_numbers(Integer_list *list, int size) {

    Integer_list *head = NULL;
    Integer_list *current_number = NULL;
 
    for(int i = 0; i < size; i++) {
        Integer_list *num = malloc(sizeof(Integer_list));
        num->num = rand() % 100;
        num->next = NULL;

        if (head == NULL){
            head = num;
        } else {
            current_number->next = num;
        }
        current_number = num;
    }
    return head;
}

void print_list(Integer_list *list){

    while (list != NULL) {
        printf("%d\n", list->num);
        list = list->next;
    };

}

void sort_list(Integer_list *list, int how_many) {
    if (list == NULL) return;

    Integer_list *end = NULL;  

    while (end != list) {
        Integer_list *current = list;
        while (current->next != end) {
            if (current->num > current->next->num) {
                int temp = current->num;
                current->num = current->next->num;
                current->next->num = temp;
            }
            current = current->next;
        }
        end = current; 
    }
}

int main()
{
    int SIZE = 100;
    srand(time(NULL));
    Integer_list *lista = NULL;
    lista = generate_array_random_numbers(lista,SIZE);
    sort_list(lista,SIZE);
    Integer_list *temp_list = lista;
    print_list(temp_list);
    return 0;
}
/*
    Practicing linked list.
    Author: Jose Miguel Garcia
    Date: 2025/10/21
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct employee
{
    int age;
    int salary;
    struct employee *next;
} Employee;

Employee *add_employee(Employee *emp, int age, int salary)
{

    if (emp == NULL)
    {
        emp = malloc(sizeof(Employee));
        emp->age = age;
        emp->salary = salary;
        emp->next = NULL;
        return emp;
    }

    Employee *current = emp;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(Employee));
    current->next->age = age;
    current->next->salary = salary;
    current->next->next = NULL;

    return emp;
}

void print_list(Employee *h, char *tittle)
{

    printf("%s\n", tittle);
    while (h != NULL)
    {
        printf("Employee age: %d\nEmployee Salary: %d\n", h->age, h->salary);
        h = h->next;
    }
}

int main()
{
    Employee *emp1 = NULL;

    emp1 = add_employee(emp1, 15, 2000);
    emp1 = add_employee(emp1, 20, 2500);
    emp1 = add_employee(emp1, 25, 3000);

    Employee *temp = emp1;
    print_list(temp, "Empleados agregados");

    return 0;
}

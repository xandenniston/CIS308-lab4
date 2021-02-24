/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

enum personType{
    Child,
    Student,
    Adult
} personType;

typedef struct person{
    char *name;
    int age;
    enum personType type;
    union{
        struct{
            char* school;
        } childSchool;
        struct{
            char* college;
            double GPA;
        }studentCollege;
        struct{
            char* company;
            double salary;
        }adultJob;
    }roleData;
}Person;

void display(Person *p);


int main()
{
    Person willie;
    willie.name = "Wille";
    willie.type = Student;
    willie.age = 20;
    willie.roleData.studentCollege.college = "K-State";
    willie.roleData.studentCollege.GPA = 3.5;

    Person* alison = malloc(sizeof(Person));
    alison->name = "alison";
    alison->type = Child;
    alison->age = 10;
    alison->roleData.childSchool.school = "Amanda Arnold Elementary";
    
    Person* bob = malloc(sizeof(Person));
    bob->name = "bob";
    bob->type = Adult;
    bob->age = 35;
    bob->roleData.adultJob.company = "Best Buy";
    bob->roleData.adultJob.salary = 45000;
    
    
    display(&willie);
    display(alison);
    display(bob);
    free(alison);
    free(bob);
    return 0;
}

void display(Person *p){
    printf("name: %s\nage: %d\n", p->name, p->age);
    switch(p->type){
        case Child:
        printf("Elementary School: %s\n", p->roleData.childSchool.school);
        break;
        
        case Student:
        printf("College: %s\n", p->roleData.studentCollege.college);
        printf("GPA: %f\n", p->roleData.studentCollege.GPA);
        break;
        
        case Adult:
        printf("Company: %s\n", p->roleData.adultJob.company);
        printf("Salary: %f\n", p->roleData.adultJob.salary);
        break;
        
    }
    printf("\n");
}

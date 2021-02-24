/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>



typedef struct student{
    char* name;
    int age;
    int schoolYear;
}Student;

void display(Student *stu);

int main()
{
    char nameInput[100];
    Student *student = malloc(sizeof(Student));
    
    printf("enter name: ");
    scanf("%s", nameInput);
    student->name = nameInput;

    
    int ageInput;
    printf("enter age as a number (i.e. 16): ");
    scanf("%d", &ageInput);
    student->age = ageInput;

    
    int yearInput;
    printf("enter school year as a number(i.e. 9-12): ");
    scanf("%d", &yearInput);
    student->schoolYear = yearInput;
    printf("\n");
    
    display(student);
    printf("\n\n");
    student->age++;
   if(student->schoolYear < 12){
       student->schoolYear++;
   }
   display(student);
   
   free(student);
    return 0;
    
    
}

void display(Student *stu){
    char *yearString;
    switch (stu->schoolYear){
        case 9:
        yearString = "freshman";
        break;
        
        case 10:
        yearString = "sophmore";
        break;
        
        case 11:
        yearString = "junior";
        break;
        
        case 12:
        yearString = "senior";
        break;
        
        default:
        yearString = "error";
    }
    
    
    printf("name: %s\nage: %d\nyear in school: %s\n", stu->name, stu->age, yearString);
    
}

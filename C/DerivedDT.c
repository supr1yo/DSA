// Derived datatype

#include<stdio.h>

// Struct
struct Student
{
    char name[50];
    char sec;
    int age;
    int enrollment;
};


int main() {
    struct Student s1;
    s1.age = 20;

    printf("%s", s1);

    return 0;
}

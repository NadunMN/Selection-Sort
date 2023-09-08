#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
    float totalmarks;
    
};

float calculateTotalMarks(float math, float physics, float chemistry) {
    return math + physics + chemistry;
}


void selectionsort(struct Student ary[], int n){
    for(int i=0;i<n-1 ; i++){
        int max=i;
       int  min=i;
       int j;
        for( j=i+1; j<n; j++){
            if(ary[j].totalmarks > ary[max].totalmarks){
                max=j;
            }
            else if(ary[j].totalmarks == ary[min].totalmarks && ary[j].id<ary[min].id){
                min= j;
            }
        }
        if(max!= i ){
            struct Student temp= ary[i];
                ary[i]=ary[max];
                ary[max]=temp;
        }
        if(min != i ){
            struct Student temp= ary[i];
                ary[i]=ary[min];
                ary[min]=temp;
        }
    }
}


int main(){

    int n=9;
       struct Student students[9] = {
        {101, "Isuru1", 60, 60, 68.6, 0},
        {102, "Nadun1", 33, 67.4, 90, 0},
        {103, "Sachith", 67.4, 34, 90, 0},
        {104, "Dinuka", 80, 85.2, 97, 0},
        {105, "Kavinda", 97, 98.4, 100, 0},
        {106, "Manilka", 76.5, 70, 73, 0},
        {107, "Tharusha", 65, 67, 69, 0},
        {108, "Malith", 73, 75.5, 75, 0},
        {109, "Thiwanga", 80, 45.5, 55, 0}
    };

     for (int i = 0; i < n; i++) {
        students[i].totalmarks = calculateTotalMarks(students[i].mathMarks, students[i].physicsMarks, students[i].chemistryMarks);
    }

    printf("Sorted Students Records\n");
    printf("-----------------------\n\n ");


    printf(" ID\t");
    printf("Student Name\t\t");
    printf("Maths\t");
    printf("Physics\t");
    printf("Chemistry\t");
    printf("Total marks\t\n");
    printf("---------------------------------------------------------------------------------\n\n ");

    float totalmarks[n];
        for(int i=0; i<n; i++){
            totalmarks[i]=students[i].totalmarks;
        }

        selectionsort(students, n);

    for(int i=0; i<n; i++){
        printf("%d \t%s  \t\t%.1f\t%.1f\t%.1f\t \t%.1f\n ",students[i].id,students[i].name,students[i].mathMarks,
        students[i].physicsMarks,students[i].chemistryMarks,students[i].totalmarks);
    }

    return 0;
}
#include<stdio.h>
#include<string.h>
/*
struct student {
    char name[20];
    int rollno;
    float marks;
};*/

int main(int argc, char const *argv[])
{
    /*
    struct student stupid1;
    
    printf("enter name, rollno and marks ");
    scanf("%s%d%f", stupid1.name, &stupid1.rollno, &stupid1.marks );
    printf("hgfdsa: %s%d%f", stupid1.name, stupid1.rollno, stupid1.marks );
    printf("name is : %s \n",stupid1.name);
    printf("Roll is : %d \n",stupid1.rollno);
    printf("marks is : %f \n",stupid1.marks);


    */

   int i, j, mat[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};1

   for(i = 0; i < 4; i++){
       for (j = 0; j < 3; j++){
           printf("%3d", mat[j][i]);
       }
       printf("\n");
   }

  

/*
  int mat[7] = {10, 21,33,45,54,65,76};
  int x = 2010, *ptr = mat;
  printf("%u%d%d\n", ptr, *ptr,x);
  x = *ptr++;
  printf("%u%d%d\n", ptr, *ptr, x);
  x=*++ptr;
  printf("%u%d%d\n", ptr, *ptr, x);
  x = ++*ptr;
  printf("%u%d%d\n", ptr, *ptr, x);
  x = (*ptr)++;
  printf("%u%d%d\n", ptr, *ptr, x);*/
    return 0;
}



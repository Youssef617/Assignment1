#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

int N=0;
int size = 0; /// Size of the dynamic array.
int capacity = 0; /// Capacity of dynamic array.


/**String maker function that read string from user*/
char * getString(){
    char temp[50];

    fgets(temp, sizeof(temp), stdin);
    char* str= (char*) malloc(strlen(temp));

    for (int i=0;i<strlen(temp);i+=1)
        str[i]=temp[i];

    str[strlen(temp)-1]='\0';

    return str;
}


typedef struct    /// define student structure
{
    char *name;
    int id;
    int day;int month;int year;   /// date of birth
    int student_score;
}student;

student *add (student *array);
student *insert (student *array, student new_student, int pos);
student *ArrayList (int array_size);

/**Change string to lowercase*/
char *lower (char *str){

  char* new_str ="";
  for (int i = 0; i < strlen (str); i += 1){
    printf("%c",tolower(str[i]));
    new_str = new_str+tolower (str[i]);
  }

  return new_str;
}


/**Read student data*/
student read_st(student* array)
{

     fflush(stdin);


     student st;

     printf("student name:");
     st.name=getString();;

     printf("student id:");  scanf("%d",&st.id);

     while(sizeof(st.id) != 4) scanf("%d",&st.id);

     printf("student date of birth:\n");
     printf("day:"); scanf("%d",&st.day);
     while(sizeof(st.id) != 4) scanf("%d",&st.day);

     printf("month:"); scanf("%d",&st.month);
     while(sizeof(st.id) != 4) scanf("%d",&st.year);

     printf("year:"); scanf("%d",&st.year);
     while(sizeof(st.id) != 4) scanf("%d",&st.year);

     printf("student last year score:");  scanf("%d",&st.student_score);

     return st;
}




/** Print student data*/
void print_student(student* st){

    printf("Name    |  Id  | Day  | Month |  Year  |  Score\n");
    printf("__________________________________________________\n");


    for (int i=0;i<size;i+=1){
        printf("%7s |  %2d  |  %2d  |  %2d   |  %4d  |  %3d\n", st[i].name, st[i].id, st[i].day
               , st[i].month, st[i].year, st[i].student_score);
        printf("---------------------------------------------------\n");
    }
}
int main()
{

    printf("Welcome sir!\n");
    int n, l, pos=0;
    student *student_list;


	printf("For linked list press 1 for dynamic array press 2 \n");
    int option;
    scanf("%d",&option);

    while ((option!=1)&&(option!=2)){
        printf("Please enter 1 or 2 \n" );
        scanf("%d",&option);
    }

    printf("Please enter number of students: ");
    scanf("%d",&n);

    if (option==2){
          student_list = ArrayList (n);	/// Make dynamic array of initial size n
    }

    for(int i=0;i<n;i+=1)
    {
             printf("Enter data of student number %d \n",i+1);
                if (option==1){

                }else if(option==2)
                    student_list[i]=read_st(student_list);
    }


    student_list=add(student_list);
    print_student(student_list);

    return 0;
}



/**
    Make a dynamic array of size array size

    array_size: the size of the ArrayList

    Return int pointer to the dynamic array in heap
*/

student *
ArrayList (int array_size){

  if(array_size==0) array_size=1;

  student *dymanic_array = (student *) malloc (array_size * sizeof (student));

  if(size==0){
      size = array_size;
      capacity = size;
  }

  return dymanic_array;
}


/**
    Insert extra element in array in specific position

    array: the array that we want to add extra
            element in it

    Return integer pointer to the new array in heap
*/
student *insert (student *array, student new_student, int pos){

    if (pos > size){
        printf("Please enter position smaller than %d\n", size);
        return add(array);
    }else if (pos == 0){
        printf("Please enter position greater  than zero\n");
        return add(array);
    }

    student *temp_vector = ArrayList (capacity);

    /// insert the new element at the pos
    int j=0, i=0;
    while (i<size){
        if(pos==j+1){
            temp_vector[j]=new_student;
            j+=1;
        }else{
            temp_vector[j]=array[i];
            j+=1;
            i+=1;
        }
    }

    ///Update the size of the array
    size = size + 1;

    return temp_vector;
}

/**
    Add extra element in array at any location (beginning, end or middle)

    array: the array that we want to add extra
            element in it

    Return student pointer to the new array in heap
*/

student *add (student *array){

    int pos=0, loc;
    student new_student;

    if (size == capacity){
        array = (student *) realloc (array, capacity * 2 * sizeof (*array));
        capacity = capacity * 2;
    }


    /// Choose location
    while(pos<=0 || pos>3){
        printf ("Would you like to add at\n1-Beginning\n2-End\n3-Middle\n");
        scanf ("%d", &pos);		// get the position
    }

    if(pos==3){
        printf("\nWhere would you like to insert the student in\n");
        scanf ("%d", &loc);		// get the position
    }

    printf ("\nEnter the student data\n");
    new_student=read_st(array);

    if (pos==1)
        return insert(array, new_student, 1);
    else if (pos==2){
        array[size] = new_student;
        size+=1;
        return array;
    }else if(pos==3)
        return insert(array, new_student, loc);

    return array;
}

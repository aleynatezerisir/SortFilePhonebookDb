#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
FILE *file,*replacement;
struct persons{
 char name[30];
 char surname[30];
 int no;
 int num1;
 };

struct persons person;

void menu();
int addrecord();
void listrecord();
void deleterecord();
void searchrecord();

int main(){
    menu();
 return 0;
}

void menu()
{
    int option;
printf("\t\tMENU \n1- Add Record\n2- List Record \n3- Delete Record \n4- Search Record \n5- Exit \n \n\nPlease enter the option:");
scanf("%d",&option);
switch(option){
 case 1:{
 system("cls");
 addrecord();
  break;
 }
 case 2:{
 system("cls");
 listrecord();
  break;
 }
 case 3:{
 system("cls");
 deleterecord();
  break;
 }
 case 4:{
 system("cls");
 searchrecord();
  break;
 }
 case 5:{
 exit(1);
  break;
 }
 default:{
  printf("Wrong Number");
 }
}
}

int addrecord()
{
    int count = 0;
    char c;
    char files[5][20]={"phone1.txt","phone2.txt","phone3.txt","phone4.txt","phone5.txt"};
    file = fopen(files[person.num1],"r");
    if(file == NULL)
    {
        printf("Could not open file %s.txt", files[person.num1]);
        exit(1);
    }
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n')
            count = count + 1;
      fclose(file);
    for(int i=0; i<count+1; i++){
if((count+1)%6==0)
{
    int k=0;
    file=fopen(files[person.num1+1],"r");
    file = fopen(files[person.num1+1],"ab");
    fflush(stdin);
    printf("\n Please enter Last name:");
    gets(person.surname);
    printf("\n Please enter First name:");
    gets(person.name);
    printf("\n Please enter Phone number:");
    scanf("%d",&person.no);
    printf("\n");
    fprintf(file,"%s , %s , %d\n",person.surname,person.name,person.no);
    fclose(file);
    k++;
    person.num1=k;
    menu();
}
else if((count+1)%6!=0)
{
    file=fopen(files[person.num1],"r");
    file=fopen(files[person.num1],"ab");
    printf("\n Please enter Last name:");
    getchar();
    gets(person.surname);
    printf("\n Please enter First name:");
    gets(person.name);
    printf("\n Please enter Phone number:");
    scanf("%d",&person.no);
    printf("\n");
    fprintf(file,"%s , %s , %d\n",person.surname,person.name,person.no);
    fclose(file);
    menu();
      }
    }
return count;
}


void listrecord(void){
    FILE *file;
 file = fopen("phone1.txt","r");
 if(file == NULL){
  printf("File could not be opened");
  exit(1);
 }
 while(!feof(file))
 {
  fflush(stdout);
  fscanf(file,"%s ,%s , %d\n",person.surname,person.name,&person.no);
   if(person.name!=NULL && person.surname!=NULL && person.no != NULL){
    printf("%s,%s,%d\n",person.surname,person.name,person.no);
   }
 }
 fclose(file);
 menu();
}

void deleterecord(void){
 char nam[10];
 int state=0;
 char str[100];
 char *token;

 fflush(stdin);
 printf("\nEnter the surname of the person you want to delete : ");
 gets(nam);
 file = fopen("phone1.txt","r");
 replacement = fopen("replace.txt","w");
 if(file == NULL || replacement == NULL){
  puts("File could not be opened.");
  exit(1);
 }
 while(!feof(file)){
    fscanf(file,"%s , %s , %d\n",person.surname,person.name,&person.no);
    if(strcmp(person.surname,nam)!=0)
        fprintf(replacement,"%s , %s , %d\n",person.surname,person.name,person.no);
}
printf("The person is deleted.\n\n");
    fclose(file);
 fclose(replacement);
 remove("phone1.txt");
 rename("replace.txt","phone1.txt");
 //remove("replace.txt");
 menu();
}


void searchrecord(void){
 char nam[10];
 char nam1[10];
 int stat=0;
 fflush(stdin);
 printf("\nEnter the surname you searched : ");
 gets(nam);
  printf("\nEnter the name you searched : ");
 gets(nam1);
 file=fopen("phone1.txt","rb");
 if( file==NULL ){
  puts("File could not opened.");
  exit(1);
 }
  while(!feof(file)){
   fscanf(file,"%s ,%s , %d\n",person.surname,person.name,&person.no);
   if((strcmp(person.surname,nam) == 0) && (strcmp(person.name,nam1) == 0) ){
    printf("%s , %s, %d\n\n Enter the continue...",person.surname,person.name,person.no);
    stat=1;
   }
  }
  fclose(file);
  if(stat == 0){
   puts("There is no record you searched for enter the continue...");
  }
 menu();

}

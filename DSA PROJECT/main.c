#include <stdio.h>
#include <stdlib.h>
# include <limits.h>
# include <string.h>
# define NO_OF_CHARS 256
typedef struct ToDo todo;
struct ToDo {
char buffer[101];
todo* next;
int count;
int prio;
};
todo* start = NULL;
int main()
{
int choice;
interface();
FILE *fp;
fp=fopen("my_code.txt","a");

while (1) {
system("Color 3F");
system("cls");
printf("1. To see your ToDo list based on priority\n");
printf("2. To create new ToDo\n");
printf("3. To delete your ToDo\n");
printf("4. To search a ToDo\n");
printf("5. To view file contents\n");
printf("6. Exit");
printf("\n\n\nEnter your choice\t:\t");
scanf("%d", &choice);
switch (choice) {
case 1:
seetodo();
break;
case 2:
createtodo();
break;
        case 3:
            deletetodo(fp);
            break;
        case 4:
            searchToDo();
            break;
        case 5:
            seeFileContents(fp);
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("\nInvalid Choice :-(\n");
            system("pause");
    }
}
    return 0;
}
void interface()
{ system("color 4F");
printf("\n\n\n\n");
printf("\t~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~\n");
printf("\t~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~\n\n");
printf("\t} : } : } : } : } : } "
": } : } : } : "
"WELCOME TO the TODO APP "
" : { : { : { : { : { "
": { : { : { : {\n\n");
printf("\t~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~\n");
printf("\t~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~\n");
printf("\n\n\n\t\t\t\t\t\t\t\t"
"t\t\t\t "
"Shreerama Adakoli\n\n\n\n"
"\n\n\n\t");
system("pause");
}
void seetodo()
{
system("cls");
    todo* temp;
    temp = start;
    if (start == NULL)
   printf("\n\nEmpty ToDo \n\n");
    while (temp != NULL) {
printf("%d.)", temp->count);
puts(temp->buffer);
fflush(stdin);
temp = temp->next;
}
printf("\n\n\n");
system("pause");
}
void createtodo()
{
char c;
int priority;
todo *add, *temp;
//system("cls");
while (1) {
printf("\nWant to add new ToDo ??"
" Press 'y' for Yes and 'n' "
" for No :-)\n\t\t");
fflush(stdin);
scanf("%c", &c);
if (c == 'n')
break;
else {
if (start == NULL) {
add = (todo*)calloc(1, sizeof(todo));
start = add;
printf("\nType it.....\n");
fflush(stdin);
gets(add->buffer);
add->count = 1;
printf("\nAlso give its priority\n");
                scanf("%d",&priority);
                add->prio=priority;
start->next = NULL;
}
else {
temp = (todo*)calloc(1, sizeof(todo));
printf("\nType it.....\n");
add=start;
fflush(stdin);
gets(temp->buffer);
printf("\nAlso give its priority\n");
                scanf("%d",&priority);
                temp->prio=priority;
                if(start->prio>priority)
                {
                    temp->next=start;
                    start=temp;
                }
                else{
                    while(add->next!=NULL&&add->next->prio<priority){
                        add=add->next;
                    }
                    temp->next=add->next;
                    add->next=temp;
                }
}
adjustcount();
}
}
}
void searchToDo(){
      todo *tmp;
      int i;
      char st[100];
      printf("\nEnter the string to search");
      scanf("%s",&st);
      if(start==NULL)
      {
        printf("\nNoshing to display here.......\n");
      }
      for(tmp=start;tmp!=NULL;tmp=tmp->next)
      {
         i=search(tmp->buffer,st);
        printf("Found at %d index of task %d",i,tmp->count);
         }
         system("pause");
}
void createBMT(char str[],int bmt[])
{
int i,plen=strlen(str);
for (i = 0;i< 127;i++)
bmt[i]=plen;
for(i=0;i<plen;i++)
            bmt[str[i]]=plen-i-1;
        bmt[str[i]]=plen;
}
int search( char txt[], char pat[])
{
    int bmt[120],i,j,k,flag,plen,slen;
    createBMT(pat,bmt);
plen=strlen(pat);
slen=strlen(txt);
    for(flag=-1,k=0;k<(slen=plen);){
        i=k+plen-1;
        j=plen-1;
        while(j>-1){
            if(txt[i]!=pat[j]){
                k+=bmt[txt[i]];
                break;
            }
        }
        if(j==-1){
            flag=k;
            break;
        }
        return flag;
    }
}
void deletetodo(FILE *fp)
{
system("cls");
int x;
todo *del, *temp;
printf("\nEnter the ToDo's number"
" that you want to remove.\n\t\t");
if (start == NULL)
printf("\n\nThere is no ToDo"
" for today :-)\n\n\n");
else {
scanf("%d", &x);
del = start;
temp = start->next;
while (1) {
if (del->count == x) {
start = start->next;
fputs(del->buffer,fp);
free(del);
adjustcount();
break;
}
if (temp->count == x) {
del->next = temp->next;
fputs(temp->buffer,fp);
free(temp);
adjustcount();
break;
}
else {
del = temp;
temp = temp->next;
}
}
}
fclose(fp);
//system("pause");
}
void adjustcount()
{
todo* temp;
int i = 1;
temp = start;
while (temp != NULL) {
temp->count = i;
i++;
temp = temp->next;
}
}
void seeFileContents(FILE *fp){
    char c;
   c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
  system("pause");
    fclose(fp);
}

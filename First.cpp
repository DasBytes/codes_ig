#include<stdio.h>
#include<ctype.h>
void FIRST(char );
int count,n=0;
char production[10][10], first[10];
main()
{
int i,choice;
char c,ch;
printf("Number of productions:");
scanf("%d",&count);
for(i=0;i<count;i++)
scanf("%s%c",production[i],&ch);
do
{
n=0;
printf("Element :");
scanf("%c",&c);
FIRST(c);
printf("\n FIRST(%c)= { ",c);
for(i=0;i<n;i++)
printf("%c ",first[i]);
printf("}\n");
printf("press 1 to continue : ");
scanf("%d%c",&choice,&ch);
}
while(choice==1);
}

void FIRST(char c)
{
int j;
if(!(isupper(c)))
    first[n++]=c;
for(j=0;j<count;j++)
{
if(production[j][0]==c)
{
if(islower(production[j][2]))
    first[n++]=production[j][2];
else FIRST(production[j][2]);
}
}
}

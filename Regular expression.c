
#include<stdio.h>
#include<string.h>
int main()
{
    char stn[100];
    gets(stn);
     int state=0;
     for(int i=0;stn[i]!='\0';i++)
     {
          if(state==0 && stn[i]=='a')
          {
               state=0;
          }
           else if(state==0 && stn[i]=='b')
          {
               state=1;
          }
              else if(state==1 && stn[i]=='b')
          {
               state=1;
          }

        else
        {
            state = 2;
            break;
        }

     }
       if(state==0)
       {
            printf("match with a*\n");
       }
      else if(state == 1)
        {
        printf("match with a*b+\n");
        }
    else
        {
        printf("Rejected");
        }


}

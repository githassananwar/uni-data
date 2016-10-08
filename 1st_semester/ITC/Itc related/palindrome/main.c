#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,c=1,chk=0;
    printf("Enter number:\n");
    scanf("%d",&n);
    while(c<=n)
    {
        chk=0;
        while(chk<c)
        {
            printf("%d,",c);
            chk++;
        }
        c++;
    }

    return 0;
}

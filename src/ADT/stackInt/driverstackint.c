# include <stdio.h>
# include "stackInt.h"

int main()
{
    StackInt S;
    int val;

    // Create Stack Int 
    printf("Creating stack......\n");
    CreateEmpty_SInt(&S);

    // Check if stack is empty
    printf("Is Empty Stack Int = %d\n",IsEmpty_SInt(S));

    // Check if stack is full
    printf("Is Full Stack Int = %d\n",IsFull_SInt(S));

    // Push Elmt to Stack
    printf("Push 0 - 9 to stack.......\n");
    for (int i = 0 ; i < 10; i++)
    {
        Push_SInt(&S,i);
    }
    printf("Top index = %d\n",Top(S));
    printf("Top Elmt = %d\n",InfoTop(S));
    printf("Stack length = %d\n",lengthSInt(S));
    printf("Is Empty Stack = %d\n",IsEmpty_SInt(S));
    printf("Is Full Stack = %d\n",IsFull_SInt(S));

    // Pop Elmt
    Pop_SInt(&S,&val);
    printf("val = %d\n",val);

    // Stack Length
    printf("Length after pop = %d\n",lengthSInt(S));

    return 0;
}
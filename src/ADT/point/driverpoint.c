# include <stdio.h>
# include "point.h"

int main()
{
    Point p1,p2,p3;

    // Create Point
    printf("Create point....\n");

    CreatePoint(&p1, 0, 0);
    CreatePoint(&p2, 4, 5);
    CreatePoint(&p3, 0, 0);
    
    PrintPoint(p1);
    PrintPoint(p2);
    PrintPoint(p3);

    // Check equal
    printf("Is Equal p1 & p3 = %d\n",EQ(p1,p3));

    // Test point operation
    Point next;
    printf("Point Operation....");
    next = NextX(p1);
    printf("p1 Next X : ");
    PrintPoint(next);
    printf("p1 Next Y : ");
    next = NextY(p1);
    PrintPoint(next);

    Point plus;
    printf("Plus : ");
    plus = PlusDelta(p2,10,10);
    PrintPoint(plus);

    printf("Shifting point...\n");
    shiftPoint(&plus,10,10);
    PrintPoint(plus);

    return 0;
}
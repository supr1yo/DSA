#include <stdio.h>
#include <math.h>

int main() {
    int option;

    printf("Press respective numbers for operation:\n");
    printf("1. Rectangle\n2. Triangle\n3. Circle\n");
    scanf("%d", &option);

    switch (option) {
        case 1: {
            float l, b, perimeter, area;
            printf("Enter length and breadth: ");
            scanf("%f %f", &l, &b);
            perimeter = 2 * (l + b);
            area = l * b;
            printf("Perimeter of Rectangle: %.2f\n", perimeter);
            printf("Area of Rectangle: %.2f\n", area);
            break;
        }
        case 2: {
            float a, b, c, perimeter, area, semiPeri;
            printf("Enter the lengths of three sides of the triangle: ");
            scanf("%f %f %f", &a, &b, &c);
            perimeter = a + b + c;
            semiPeri = perimeter / 2;
            area = sqrt(semiPeri * (semiPeri - a) * (semiPeri - b) * (semiPeri - c));
            printf("Perimeter of Triangle: %.2f\n", perimeter);
            printf("Area of Triangle: %.2f\n", area);
            break;
        }
        case 3: {
            float r, area, perimeter;
            printf("Enter the radius of the circle: ");
            scanf("%f", &r);
            area = 3.14 * r * r;
            perimeter = 2 * 3.14 * r;
            printf("Area of Circle: %.2f\n", area);
            printf("Perimeter of Circle: %.2f\n", perimeter);
            break;
        }
        default:
            printf("You chose the wrong option. Rerun the program.\n");
            break;
    }

    return 0;
}

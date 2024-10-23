#include <stdio.h>
#define PI 3.14

int main() {
    float radius, area, circumference;

    // Input radius of the circle
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    // Calculate area 
    area = PI * radius * radius;
	// Calculate Circumference
    circumference = 2 * PI * radius;

    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);

    return 0;
}


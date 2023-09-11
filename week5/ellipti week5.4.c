#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

int a, b, p; // Curve parameters

// Function to calculate the slope of the tangent line
int calculateSlope(Point p1, Point p2) {
    if (p1.x == p2.x && p1.y == p2.y) {

             int denominator = (2*p1.y);
              int inverse = 1;

            for (int i = 1; i < p; i++) {
            if ((denominator * i) % p == 1) {
                inverse = i;
                break;
            }
        }


        return ((3 * p1.x * p1.x + a) * inverse) % p;
    } else {
        int numerator = (p2.y - p1.y);
         int denominator = (p2.x - p1.x);
       int inverse = 1;

        // Find modular multiplicative inverse of denominator
        for (int i = 1; i < p; i++) {
            if ((denominator * i) % p == 1) {
                inverse = i;
                break;
            }
        }

        return (numerator * inverse) % p;
    }
}

// Function to perform point addition (p + q)
Point pointAddition(Point p1, Point p2) {
    int m = calculateSlope(p1, p2);

    int x3 = (m * m - p1.x - p2.x) % p;
    if (x3 < 0) {
        x3 += p;
    }

    int y3 = (m * (p1.x - x3) - p1.y) % p;
    if (y3 < 0) {
        y3 += p;
    }

    return (Point){x3, y3};
}

int main() {
    printf("Enter the parameters for the elliptic curve (a, b, p): ");
    scanf("%d %d %d", &a, &b, &p);

    Point p1, p2;
    printf("Enter the coordinates of point p (x y): ");
    scanf("%d %d", &p1.x, &p1.y);
    printf("Enter the coordinates of point q (x y): ");
    scanf("%d %d", &p2.x, &p2.y);

    Point sum = pointAddition(p1, p2);

    printf("Result of point addition (p + q) is (%d, %d)\n", sum.x, sum.y);

    return 0;
}

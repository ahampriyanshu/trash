#include <stdio.h>
#include <math.h>   // for using mathematical funtions
#define rad 0.01745 //  defining 1 radian in terms of degree
#define g 9.8       // defining  gravitational acceleration in m/s^2
int main()
{
    const float camp_dist = 20.278;
    int angle, set = 0;
    float height, distance, velocity, x, formula1, formula2, range, actual_range;
    /* Declaring angle , height , velocity , radian , distance , range   */

    for (angle = 25; angle < 60; angle + 2)
    {
        for (height = 2; height <= 4; height + 0.25)
        {
            for (distance = 1; distance <= 3; distance + 0.1)
            {
                for (velocity = 1500; velocity < 2000; velocity + 1.10)
                {
                    x = angle * rad;
                    // converting degree to radian
                    formula1 = (2 * g * height) / (velocity * velocity * sin(x) * sin(x));
                    /* calculating a smaller part of the formula used for finding range of a projctile
                    launched from a height at some angle */
                    formula2 = 1 + sqrt(1 + formula1);
                    // Progressing towards the main formula
                    range = sin(2 * x) * formula2 * (velocity * velocity / 2 * g);
                    // Finally the real formula
                    actual_range = camp_dist + distance;
                    // Calculating actual range
                    if (range >= actual_range - 15 && range <= actual_range + 15)
                    // Checking if the mortar has reached its target successfully
                    {
                        printf("\nSet %d is : angle = %d , distance = %f , height = %f , velocity = %f", set, angle, distance, height, velocity);
                        set++;
                        // Displaying vlaues of all the possible set
                    }
                }
            }
        }
    }

    if (set == 0) //If solution isn't found
    {
        printf("No solution. Please change the tank");
    }
}
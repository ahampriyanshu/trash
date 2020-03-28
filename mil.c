#include <stdio.h>
#include <math.h>   // for using mathematical funtions
#define rad 0.01745 //  defining 1 radian in terms of degree
#define g 9.8       // defining  gravitational acceleration in m/s^2
int main()
{
    int angle,set = 0;
    float height, distance, x, formula1, formula2,velocity, range, vel,actual_range;
    /* Declaring angle , height , velocity , radian , distance , range   */

    for (angle = 25; angle <= 60; angle += 2)
    {
        for (height = 2.00; height <= 4.00; height += 0.25)
        // Converting mts to kms
        {
            for (distance = 1.00; distance <= 3.00; distance += 00.10)
            {
                for (velocity = 1500; velocity <= 2000; velocity = velocity*1.10)
                {   
                    x = angle * rad;
                    // converting degree to radian
                    vel = velocity * 5/18;
                    // converting mks to si 
                     formula1 = (2 * g * height) / (vel * vel * sin(x) * sin(x));
                    /* calculating a smaller part of the formula used for finding range of a projctile
                    launched from a height at some angle */
                    formula2 = 1 + sqrt(1 + formula1);
                    // Progressing towards the main formula
                    range = sin(2 * x) * formula2 * (vel * vel / 2 * g);
                    // Finally the real formula
                    
                    if (range >= 20263 + distance && range <= 20293 + distance)
                    // Checking if the mortar has reached its target successfully
                    {
                        printf("\nSet %d is : angle = %d , distance = %f , height = %f ,  vel = %f", set, angle, distance, height,vel);
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

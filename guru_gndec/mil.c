#include <stdio.h>
#include <math.h>   // for using mathematical funtions
#define rad 0.01745 //  defining 1 radian in terms of degree
#define g 9.8       // defining  gravitational acceleration in m/s^2
int main()
{
    int set = 0;
    float angle,distance,height,x, formula1, formula2,velocity, range, vel,actual_range;
    /* Declaring angle , height , velocity , radian , distance , range   */

    for (angle = 25; angle <= 60; angle += 2)
    {
        for (height = 2.00; height <= 4.00; height += 0.25)
 
        {
            for (distance = 1000; distance <= 3000; distance += 100)
                   // Converting  to kms to mts
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
                    printf("\n%f  %f  %f",formula1,formula2,range);
                    if (range >= 20263 + distance && range <= 20293 + distance)
                    // Checking if the mortar has reached its target successfully
                    {
                        printf("\nSet %d is : angle = %f , distance = %f , height = %f ,  vel = %f", set, angle, distance, height,vel);
                        set++;
                        // Displaying vlaues of all the possible set
                    }
                    
                }
            }
        }
    }

    if (set == 0) //If solution isn't found
    {
        printf("\nNo solution. Please change the tank");
    }
}

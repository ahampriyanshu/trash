#include <stdio.h>

int main()
{
    printf("*************************************************************************WELCOME*************************************************************************\n");
    int salt_id[13];
    for (int i = 0; i < 13; i++)
    {
        salt_id[i] = i + 1; //Giving every salt a id
    }
    char salt_name[13][10] = {
        "Ca(CO)3",
        "Ca(HCO3)2",
        "Ca(SO4)",
        "Ca(Cl)2",
        "Ca(NO3)2", //Initialising salt name that can be present in given sample of water
        "Mg(CO3)",
        "Mg(HCO3)2",
        "Mg(SO4)",
        "Mg(Cl)2",
        "Mg(NO3)2",
        "NaCl",
        "SiO2",
        "KOH"};
    float salt_mass[13];
    salt_mass[0] = 100;
    salt_mass[1] = 162;
    salt_mass[2] = 136;
    salt_mass[3] = 111;
    salt_mass[4] = 164; //Putting the value of salt's molarmass
    salt_mass[5] = 84;
    salt_mass[6] = 146;
    salt_mass[7] = 120;
    salt_mass[8] = 95;
    salt_mass[9] = 148;
    salt_mass[10] = 58.5;
    salt_mass[11] = 60;
    salt_mass[12] = 56;
    printf("Salt_Id     Salt_Name\n");
    for (int i = 0; i < 13; i++)
    {
        printf("%d	    %s\n", salt_id[i], salt_name[i]); //Printing the table of content
    }
    int sp;
    float tsum = 0, psum = 0;
    printf("\nEnter the number of salts present in the given sample of water from above table\n"); //Counting how many salts are present in the sample
    scanf("%d", &sp);
    if (sp > 0 && sp < 14)
    {
        printf("\nEnter the Salt_Id of salts which are present in the given water sample and their amount\n");
        int salt_present[sp];
        float salt_amt[sp];
        for (int i = 0; i < sp; i++)
        {
            int k;
            printf("\nEnter the salt_id %d: ", i + 1);
            scanf("%d", &salt_present[i]); //storing salt id
            k = salt_present[i];
            if (k > 0 && k < 14) //From here id validation process begins
            {
                int j, count = 0;
                for (int j = 0; j < i; j++)
                {
                    if (k == salt_present[j])
                        count++;
                }
                if (count == 0) //checking whether salt id is already given or not
                {
                    printf("Amount of %s in mg/L: ", salt_name[k - 1]);
                    scanf("%f", &salt_amt[i]); //storing amount of each present salt
                    printf("\n");
                    if (k == 1 || k == 2 || k == 6 || k == 7)
                    {
                        tsum = tsum + (salt_amt[i] / salt_mass[k - 1]); //calculating temprory hardness
                    }
                    else if (k > 10)
                    {
                        psum = psum; //it is for those salts which do not cause hardness in water
                    }
                    else
                    {
                        psum = psum + (salt_amt[i] / salt_mass[k - 1]); // calculating permanent hardness
                    }
                }
                else
                {
                    printf("You already entered for this salt id\n");
                    i--;
                }
            }
            else
            {
                printf("Enter Valid salt id\n");
                i--;
            }
        }
    }
    else
    {
        printf("Invalid entry, Try again\n");
    }
    float total;
    total = tsum + psum;

    printf("Temprory hardness of given sample of water = %f mg/L or %f ppm\n", tsum * 100, tsum * 100); //output

    printf("Permanent hardness of given  sample of water = %f mg/L or %f ppm\n", psum * 100, psum * 100);

    printf("Total hardness of given sample of water = %f mg/L or %fppm\n", total * 100, total * 100);

    return 0;
}

//Made by Vaibhav Shukla
//Improvised b Priyanshumay
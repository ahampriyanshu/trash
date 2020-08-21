Priyanshu Tiwari, [21.08.20 12:09]
#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    printf("no. of terms?\n");
    scanf("%d", &p->n);
    p->terms = (struct term *)malloc(p->n * sizeof(struct term));

    printf("enter terms\n");
    for (int i = 0; i < p->n; i++)
    {
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct poly p)
{
    int i=0;
    while ( i< p.n-1 )
    {
        printf("%d(x^%d)+", p.terms[i].coeff, p.terms[i].exp);
        ++i;
    }
     printf("%d(x^%d)\n", p.terms[i].coeff, p.terms[i].exp);
}

int main()
{
    struct poly p1;
    create(&p1);
    display(p1);
    return 0;
}

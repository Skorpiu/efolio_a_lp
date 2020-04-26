#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_aluno ALUNO;
struct t_aluno
{
    long a;
    char b;
};

static char dat[500];

ALUNO f2(int set)
{
    ALUNO *x = (ALUNO *)dat;
    if (set == 2)
    {
        return (ALUNO){ 0, 0 };
    }
    if (set == 1)
    {
        x->a = 1;
        x->b = '1';
        x++;
        x->a = 2;
        x->b = '2';
        x = (ALUNO *)dat;
    }
    return x[0];
}

int main()
{
    ALUNO y;
    y = f2(1);
    printf("%c", y.b);
    y.b = 'D';
    y = f2(0);
    printf("%c", y.b);
    return 0;
}
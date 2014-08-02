#include <string.h>
#include <stdio.h>

struct datatype
{
    int i;
    char s[10];
};

typedef struct datatype Datatype;
typedef struct datatype* PtrDatatype;

void Modify(Datatype s)
{
    s.i = 10;
    strcpy(s.s,"YOLO");
}

void PtrModify(PtrDatatype s)
{
    s->i=110;
    strcpy(s->s,"TOLO");
}

int main()
{
    Datatype d; d.i = 1;
    PtrDatatype pd;
    pd = (PtrDatatype)(malloc(sizeof(struct datatype)));
    pd->i = 2;
    printf("Here.\n");
    printf("d.i = %d. d.s = %s.\n", d.i, d.s);
    printf("pd.i = %d. pd.s = %s.\n", pd->i, pd->s);
    Modify(d);
    PtrModify(pd);
    printf("d.i = %d. d.s = %s.\n", d.i, d.s);
    printf("pd.i = %d. pd.s = %s.\n", pd->i, pd->s);

}

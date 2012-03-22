//
//  main.c
//  TP01
//
//  Created by Johan Medioni on 15/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include <stdio.h>
void exercice_1(void);
void exercice_2_1(void);
void exercice_2_2(void);
void exercice_2_3(void);
void exercice_2_4(void);
void exercice_3_3(void);
void exercice_3_4(void);

void exercice_1()
{
    float a, b;
    printf("Nombres : ");
    scanf("%f %f", &a, &b);
    printf("%f %f %f", a, b, a+b);
    
    // Permutation //
    float temp;
    temp=a;
    a=b;
    b=temp;
    printf("\n\n%f %f", a, b);
    
    // Pourcentage //
    printf("\n\nNombre, pourcentage : ");
    scanf("%f %f", &a, &b);
    printf("\n %f", a*b/100);
    
    // Conversion °F -> °C //
    printf("\nValeur à convertir en °C : ");
    scanf("%f", &a);
    b=a-32;
    b=5*b/9;
    printf("\n %f",b);
    
    // Affichage déc, hexa, octal //
    int i;
    printf("\n\nEntier : ");
    scanf("%d", &i);
    printf("\n %d %x %o\n", i, i, i);
    
    //0, pair ou impair ?//
    if (i==0)
        printf("\nC'est 0.");
        else if (i%2==0)
            printf("\nPair.");
            else printf("\nImpair.");
                
                // Char //
                char c='5';
                printf("\n\n%c", c);
                c = 96;
                printf("\n%c", c);

}
void exercice_2_1()
{
    char c;
    printf("Caractère : ");
    scanf("%c", &c);
    if ((c>='a' && c<='z') || (c<='Z' && c>='A')) printf("\nC'est une lettre de l'alphabet.");
    else printf("Tu as tapé de la merde.");
}

void exercice_2_2()
{
    unsigned int i=0;
    printf("\nEntier :");
    while(i!=-1)
    {
        scanf("%u", &i);
    }
}
void exercice_2_3(void)
{
    int a, i;
    printf("Quelle table de multiplication voulez-vous ? (0 pour sortir).");
    scanf("%d", &a);
    while (a<0 || a>9)
    {
        printf("Pas dans les possibilités du programmes, recommencez.");
        scanf("%d", &a);
    }
    if (a==0)
        printf("See ya !");
    else if (a<10 && a>0)
    {
        for (i=1; i<=10; i++) 
        {
            printf("%d\t", i*a);
        } 
    }
}

void exercice_2_4()
{
    char c;
    c=getchar();
    switch(c)
    {
        case '1' : 
            printf ("un");
            break;
        case '2' :
            printf ("deux");
            break;
        case '3' :
            printf ("trois");
            break;
        default :
            printf ("autre caractère");
            break;
    }
}

void exercice_3_3()
{
    int m[3][4];
    int i, j;
    
    for (i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            m[i][j]=12+j+4*i;
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void exercice_3_4()
{
    int m[3][4], h[4][3], r[3][3];
    int i, j, g;
    
    for (i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("miaou");
            scanf("%d",&g);
            m[i][j]=g;
        }
    }
    
    for (i=0; i<3; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    
    for (i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d",&g);
            h[i][j]=g;
        }
    }
    
    for (i=0; i<4; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d\t", h[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            for(
        }
    }
}



int main (int argc, const char * argv[])
{
    exercice_3_4();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define tam 100

int strlen_prof (char *string)
{

    int numCaracteres = 0;

    while (string[numCaracteres] != '\0')
    {
        numCaracteres++;
    }

    return numCaracteres;

}

char *strvwl_prof(char *string)
{
    char *vogais;
    int TAM, i=0, ind=0;
    TAM=strlen_prof(string);
    vogais = (char*)malloc(TAM+1);

    do
    {
        if(*(string+i)=='a'||*(string+i)=='e'||*(string+i)=='i'||*(string+i)=='o'||*(string+i)=='u')
        {
            vogais[ind] = string [i] ;
            ind++;
        }
        if(*(string+i)=='A'||*(string+i)=='E'||*(string+i)=='I'||*(string+i)=='O'||*(string+i)=='U')
        {
            vogais[ind] = string[i];
            ind++;
        }
        i++;
        if(*(string+i)=='\0')
            vogais[ind]=string[i];
    }
    while (*(string+i) != '\0');

    return (vogais);
}
*strlwr_prof (char *string)
{
    char *maiusculas;
    int i=0;
    maiusculas= malloc(strlen_prof(string)+1);
    while(*(string+i)!='\0')
    {
        if(string[i]>=65&&string[i]<=90)
            maiusculas[i]=string[i]+32;

        else
            maiusculas[i]=string[i];
        i++;
    }
    maiusculas[i]=string[i];
    return(maiusculas);
}


char *strrev_prof (char *string)
{
    int i,j;

    char *string2;

    for(i=0,j=(strlen_prof(string)-1); i<strlen_prof(string); i++,j--)
        string2[i]=string[j];

    string2[i]='\0';

    return(string2);
}

char *strpal_prof(char *string)
{

    int  tamanho,h=0,i;

    char *palin;

    palin = strrev_prof(string);

    palin = strlwr_prof(palin);

    string = strlwr_prof(string);

    tamanho = strlen_prof(string);

    for(i=0; i<tamanho; i++)
        if(palin[i]==string[i])
            h++;

    if(h==tamanho)
        return("SIM");

    else
        return("NAO");
}




int main()
{
    char stringUser[tam], h[2], N;
    int num;
    scanf("%s", stringUser);
    if(stringUser[0]=='\\'&&stringUser[1]=='0')
        return(0);
    scanf("%s", h);
    if(h[0]=='1'||h[0]=='2'||h[0]=='3'||h[0]=='4'||h[0]=='5')
        N=h[0];
    if(h[0]=='\\'&&h[1]=='0')
        N='\0';


    while (N != '\0')
    {
        switch(N)
        {

        case '1':
            num = strlen_prof(stringUser);
            printf("%d\n", num);
            break;
        case '2':
            printf("%s\n", strvwl_prof(stringUser));
            break;
        case '3':
            printf("%s \n",strlwr_prof(stringUser));
            break;
        case '4':
            printf("%s \n",strrev_prof(stringUser));
            break;
        case '5':
            printf("%s \n",strpal_prof(stringUser));
            break;



        }
        scanf("%s", stringUser);
        if(stringUser[0]=='\\'&&stringUser[1]=='0')
            return(0);
        scanf("%s", h);
        if(h[0]=='1'||h[0]=='2'||h[0]=='3'||h[0]=='4'||h[0]=='5')
            N=h[0];
        if(h[0]=='\\'&&h[1]=='0')
            N='\0';
    }

    return 0;
}

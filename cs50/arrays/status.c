#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;//return if not ful command come!!!
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}//если main а не void, то значит в CLI бою.о загружать аргументы
// функций сразу же
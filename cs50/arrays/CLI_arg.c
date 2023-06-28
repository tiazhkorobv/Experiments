#include <cs50.h>
#include <stdio.h>

//input argument AFTER pogramm start!!!
// int main(void)
// {
//     string name = get_string("What's your name? ");
//     printf("hello, %s\n\n", name);


//input argument BEFORE pogramm start!!!
int main(int argc, /*- is a counter for argv array*/ string argv[])
{
if (argc == 2)
    {
        printf("hello, %s\n", argv[3]);
    }
    else
    {
        printf("hello, world\n");
    }
}//Notice that this program knows both argc, the number of
//command line arguments, and argv which is an array
//of the characters passed as arguments at the command line.
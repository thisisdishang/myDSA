//Various operation on string:-
//1.Check if the string is palindrome.
//2.Convert string into uppercase & lowercase.
//3.Copy one string to another.
//4.Calculate the length of the string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[] = "madam";
    int isPalindrome = 1;
    int size = strlen(str);
    int start = 0, end = size - 1;

    while (start <= end)
    {
        if (str[start++] != str[end--])
        {
            isPalindrome = 0;
            break;
        }
    }

    if (!isPalindrome)
        printf("%s is Not palindrome.", str);
    else
        printf("%s is Palindrome.", str);
    printf("\n");

    printf("%s in upper case: ", str);
    for (int i = 0; i <= size; i++)
        str[i] = toupper(str[i]);

    puts(str);

    printf("%s in lower case: ", str);
    for (int i = 0; i <= size; i++)
        str[i] = tolower(str[i]);

    puts(str);

    printf("The string \"%s\" is ", str);
    strcpy(str, "sir");
    printf("now changed to \"%s\".", str);

    size = strlen(str);
    printf("\n%s has size: %d", str, size);

    return 0;
}
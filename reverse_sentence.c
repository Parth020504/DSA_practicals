#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse the words
// of the given string without using strtok().
void reverse(char *s)
{
    // Create an empty string stack
    char *stack[100]; // Assuming a maximum of 100 words
    int top = -1;

    // Create an empty temporary string
    char temp[100]; // Assuming a maximum word length of 100 characters
    int tempIndex = 0;

    // Traversing the entire string
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            // Push the temporary variable into the stack
            temp[tempIndex] = '\0';
            stack[++top] = strdup(temp);

            // Assigning temporary variable as empty
            tempIndex = 0;
        }
        else
        {
            temp[tempIndex++] = s[i];
        }
    }

    // For the last word of the string
    temp[tempIndex] = '\0';
    stack[++top] = strdup(temp);

    while (top != -1)
    {
        // Get the words in reverse order
        printf("%s ", stack[top--]);
    }
    printf("\n");
}

// Driver code
int main()
{
    char s[50];
    printf("Enter the string: ");
    gets(s);
    reverse(s);
    return 0;
}

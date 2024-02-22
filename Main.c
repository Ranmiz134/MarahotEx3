#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"

int main() {
    StrList* lst = StrList_alloc();
    char* word = (char*)malloc(30*sizeof(char));
    int option, index, numWords, wordLen;

    printf("\nMenu:\n");
    printf("1 - Insert strings into the list\n");
    printf("2 - Insert a string at a certain index\n");
    printf("3 - Print the list\n");
    printf("4 - Print the length of the list\n");
    printf("5 - Print a string at a certain index\n");
    printf("6 - Print the number of characters in the entire list\n");
    printf("7 - Print how many times a string appears\n");
    printf("8 - Delete all occurrences of a string from the list\n");
    printf("9 - Delete a member at a certain index\n");
    printf("10 - Reverse the list\n");
    printf("11 - Delete the entire list\n");
    printf("12 - Sort the list in lexicographical order\n");
    printf("13 - Check whether the list is arranged in lexicographical order\n");
    printf("0 - Exit\n");

    while (1) 
    {
        printf("Enter your option: ");
        scanf(" %d", &option);

        switch(option) 
        {
            case 1:
                int i;
                printf("please enter the number of words you'd like to enter and the words.\n");
                scanf(" %d" , &numWords);
                for (i = 0; i < numWords; i++)
                {
                    scanf(" %s" , word);
                    wordLen = strlen(word);
                    char* tmp;
                    tmp = (char*)realloc(word, wordLen*sizeof(char)+1); //change the dinamyc size of the String to be the exact size of it + /0
                    StrList_insertLast(lst, word);
                    printf("inserted %s to the list and the length of the string after realloc is: %ld\n", tmp, strlen(tmp));
                }
                break;
            case 2:
                printf("Enter the index and the word: ");
                scanf("%d %s", &index, word);
                StrList_insertAt(lst, word, index);
                break;
            case 3:
                printf("List: ");
                StrList_print(lst);
                break;
            case 4:
                printf("Length of the list: %zu\n", StrList_size(lst));
                break;
            case 5:
                printf("Enter the index: ");
                scanf("%d", &index);
                StrList_printAt(lst, index);
                break;
            case 6:
                printf("Total characters in the list: %d\n", StrList_printLen(lst));
                break;
            case 7:
                printf("Enter the string: ");
                scanf("%s", word);
                printf("Number of occurrences: %d\n", StrList_count(lst, word));
                break;
            case 8:
                printf("Enter the string: ");
                scanf("%s", word);
                StrList_remove(lst, word);
                break;
            case 9:
                printf("Enter the index: ");
                scanf("%d", &index);
                StrList_removeAt(lst, index);
                break;
            case 10:
                StrList_reverse(lst);
                printf("List reversed.\n");
                break;
            case 11:
                StrList_free(lst);
                lst = StrList_alloc();
                printf("List deleted.\n");
                break;
            case 12:
                StrList_sort(lst);
                printf("List sorted.\n");
                break;
            case 13:
                int isSorted = StrList_isSorted(lst);
                if (isSorted)
                {
                    printf("List is sorted.\n");
                }
                else
                {
                    printf("List is not sorted.\n");
                }
                break;
            case 0:
                printf("Exiting the program.\n");
                StrList_free(lst);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

//RAN MIZRAHI 314809625
//Main.c

#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"

int main() {
    StrList* lst = StrList_alloc();
    char* word = (char*)malloc(30*sizeof(char));
    int option, index, numWords, wordLen;

    // printf("\nMenu:\n");
    // printf("1 - Insert strings into the list\n");
    // printf("2 - Insert a string at a certain index\n");
    // printf("3 - Print the list\n");
    // printf("4 - Print the length of the list\n");
    // printf("5 - Print a string at a certain index\n");
    // printf("6 - Print the number of characters in the entire list\n");
    // printf("7 - Print how many times a string appears\n");
    // printf("8 - Delete all occurrences of a string from the list\n");
    // printf("9 - Delete a member at a certain index\n");
    // printf("10 - Reverse the list\n");
    // printf("11 - Delete the entire list\n");
    // printf("12 - Sort the list in lexicographical order\n");
    // printf("13 - Check whether the list is arranged in lexicographical order\n");
    // printf("0 - Exit\n");

    while (1) 
    {
        // printf("Enter your option: ");
        scanf(" %d", &option);

        switch(option) 
        {
            case 1:
                int i;
                scanf(" %d" , &numWords);
                for (i = 0; i < numWords; i++)
                {
                    scanf(" %s" , word);
                    wordLen = strlen(word);
                    char* tmp;
                    tmp = (char*)realloc(word, wordLen*sizeof(char)+1); 
                    StrList_insertLast(lst, word);
                }
                break;
            case 2:
                scanf("%d %s", &index, word);
                StrList_insertAt(lst, word, index);
                break;
            case 3:
                StrList_print(lst);
                break;
            case 4:
                printf("%zu\n", StrList_size(lst));
                break;
            case 5:
                scanf("%d", &index);
                StrList_printAt(lst, index);
                break;
            case 6:
                printf("%d\n", StrList_printLen(lst));
                break;
            case 7:
                scanf("%s", word);
                printf("%d\n", StrList_count(lst, word));
                break;
            case 8:
                scanf("%s", word);
                StrList_remove(lst, word);
                break;
            case 9:
                scanf("%d", &index);
                StrList_removeAt(lst, index);
                break;
            case 10:
                StrList_reverse(lst);
                break;
            case 11:
                StrList_free(lst);
                lst = StrList_alloc();
                break;
            case 12:
                StrList_sort(lst);
                break;
            case 13:
                int isSorted = StrList_isSorted(lst);
                if (isSorted)
                {
                    printf("true\n");
                }
                else
                {
                    printf("false\n");
                }
                break;
            case 0:
                StrList_free(lst);
                exit(0);
            default:
               // printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

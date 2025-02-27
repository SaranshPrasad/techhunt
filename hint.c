#include <stdio.h>
#include <string.h>

// Function to reverse a string properly
void reverseString(char str[]){
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Swap characters at left and right positions
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char clue[500]; // Increased size to store the full file content
    clue[0] = '\0'; // Ensure it's an empty string

    // Open the file
    FILE *file = fopen("clue.txt", "r");
    if (file == NULL) {
        printf("Error opening clue file!\n");
        return 1;
    }

    // Read the whole file
    char temp[100];
    while (fgets(temp, sizeof(temp), file) != NULL) {
        strcat(clue, temp); // Append each line to clue
    }
    fclose(file);

    reverseString(clue); // Reverse the entire string

    printf("Proceed to: %s\n", clue);
    return 0;
}

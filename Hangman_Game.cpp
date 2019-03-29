#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
char fileLoc[500];
void showLogo()
{
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t**HANGMAN**\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t  _______\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t |   |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t |   |\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t |   0\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t |  \\|/ \n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t |  / \\ \n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t ==========\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t ~~START~~\n\n");
}
void prn_wg(int i) 
{
    switch (i) 
    {
        case 0 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("____________\n\n");
        break;
        case 1 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 2 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 3 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 4 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 5 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |    |\n");
            printf("  |    |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 6 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|\n");
            printf("  |    | \n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 7 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |\n");
            printf("__|_________\n\n");
        break;
        case 8 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   /\n");
            printf("__|_________\n\n");
        break;
        case 9 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
        break;
        case 10 :
            printf("Amount of wrong letters: %d\n\n", i);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    X \n");
            printf("  |   \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
        break;
    }
}
char randomNumber(int max_number)
{
    srand(time(NULL));
    int g = (rand() % (max_number + 1));
    return g;
}
char *getWord()
{
    char c[50000];
    int n;
    FILE *file;
    if(strcmp(fileLoc, "") != 1)
    {
        file = fopen("PLACES.txt", "r");
    } else 
    {
        file = fopen(fileLoc, "r");
    }
    if(file==NULL) 
    {
        printf("An error has occured: can't open words file.\nPlease type the location of the words file:\n");
        scanf("%s", fileLoc);
        printf("Reading file '%s'.....\n\n", fileLoc);
        file = fopen(fileLoc, "r");
        if (file == NULL) 
        {
            while (file==NULL)
            {
                printf("That file doesn't exist. Enter the location of the words file:\n");
                scanf("%s", fileLoc);
                printf("Reading file '%s'.....\n\n", fileLoc);
                file = fopen(fileLoc, "r");
            }
        }
        printf("File has been read.\n\n");
        n = fread(c, 1, 50000, file);
        c[n] = '\0';
    } 
    else 
    {
        n = fread(c, 1, 50000, file);
        c[n] = '\0';
    }
    char *token = strtok(c, "|");
    char *words[200] = {0};
    int f = 0;
    while(token != NULL) 
    {
        words[f] =(char*) malloc(strlen(token)+1);
        strcpy(words[f],token);
        token = strtok(NULL, "|");
        f++;
    }
    fclose(file);
    int wordN = randomNumber(f);
    int q;
    for(q  = 0; q < 200; q++)
    {
        if( q != wordN) 
        {
            free(words[q]);
        }
    }
    return words[wordN];
}
int main(void)
{
    char udi[] = "EMPTY";
    while ((strcmp(udi, "END") != 0) && ((strcmp(udi, "AGAIN") == 0) || (strcmp(udi, "EMPTY") == 0)))
    {
        strcpy(udi, "EMPTY");
        char *tempWord = getWord();
        char guessWord[strlen(tempWord)+1];
        strcpy(guessWord, tempWord);
        free(tempWord);
        int wordlength = strlen(guessWord);
        char* currentWord =(char*) malloc( wordlength );
        int t;
        for (t = 0; t <= wordlength; t++)
        {
            if (t == wordlength) 
            {
                currentWord[t] = '\0';
            } 
            else 
            {
                currentWord[t] =  '.';
            }
        }
        int errors = 0;
        int guessedLetter = 0;
        int i,n = 1;
        char c;
        showLogo();
        printf("%s\n\n%s\n%s\n%s\n%s\n\n%s%s\n\n",
        "Welcome to the game Hangman!",
        "The objective in this game is to guess the name of the PLACE.",
        "You can enter both uppercase and lowercase letters.",
        "If you think you know the word, you can type it in.",
        "You will loose if you have guessed 10 letters wrong.",
        "This is the word you need to guess: ",
        currentWord);
        printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
        while( (strcmp(currentWord, guessWord) != 0) && (errors < 10) ) 
        {
            scanf("%c", &c);
            c = tolower(c);
            if (c != '\n') 
            {
                if (isalpha(c))
                {
                    for (i = 0; i < wordlength; i++) 
                    {
                        if (guessWord[i] == c)
                        {
                            currentWord[i] = c;
                            guessedLetter = 1;
                        }
                    }
                    if (guessedLetter == 0) 
                    {
                        errors++;
                        printf("\nThat letter was incorrect.\n\n");
                    }
                    else 
                    {
                        guessedLetter = 0;
                        printf("\nThat letter was correct.\n\n");
                    }
                    printf("%s%s\n\n", "The word including the letters you guessed: ", currentWord);
                    prn_wg(errors);
                    n++;
                    if((strcmp(currentWord, guessWord) != 0) && (errors < 10) ) 
                    {
                        printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
                    }
                } 
                else
                {
                    printf("Only alphabetic symbols are allowed (a-z, A-Z), try again:\n");
                }
            }
        }
        printf("---------------\n");
        printf("--- Results ---\n");
        printf("---------------\n\n");
        if (errors < 10) 
        {
            if(strcmp(currentWord, guessWord) == 0)
            {
                printf("Congratulations you have guessed the right word!\n\n");
            }
            else 
            {
                printf("You have guessed the wrong word, better luck next time!\n\n");
            }
        }
        else 
        {
            printf("You have guessed the wrong word, better luck next time!\n\n");
        }
        printf("\nLetters guessed wrong: %d\nThe word that needed to be guessed: %s\nThe word you guessed: %s\n", errors, guessWord, currentWord);
        printf("\nEnter 'end' to end the game or enter 'again' to guess another word:\n");
        while((strcmp(udi, "END") != 0) && (strcmp(udi, "AGAIN") != 0)) 
        {
            if (strcmp(udi, "EMPTY") != 0) 
            {
            printf("\n\nIt is not allowed to enter anything else than 'again' or 'end', try again:\n");
            }
            scanf("%s", udi);
            int x;
            for (x = 0; x < 5; x++) 
            {
                udi[x] = toupper(udi[x]);
            }
        }
        printf("\n\n--------------------------------------------\n\n");
    }
    return 0;
}
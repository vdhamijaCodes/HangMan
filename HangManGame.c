// HangMan Game

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void PrintHangMan(int lives){

    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");

    for(int i = 0;i<lives;i++){
        printf("%s\n", hangmanParts[i]);
    }

}

int main(){
    char guessWord[][16] = {
        "green",
        "yello",
        "purple",
        "windows",
        "linux",
        "apple",
    };

    srand(time(NULL)); // acts a a seed to generate random numbers based on the time
    int word = rand()%6; // it will give us a random number between 1 - 6 which will fall under the array index
    int lives = 1; // number of guesses
    int correctGuess = 0; // length of the letter guessed
    int oldCorrect = 0;

    int lengthOfWord = strlen(guessWord[word]); // legngth of the word

    int letterGuessed[10] = {0,0,0,0,0,0,0,0,0,0}; // will keep a track of index of the word that has been guessed

    int quit = 0; // if the user has quit
    int loopindex = 0;
    char guess[16]; //  user guess word will be held here
    char letterEntered;

    printf("Random Guessed Word %s \n Index of the word %d \n length of the word %d", guessWord[word],word, lengthOfWord);

    // game loop
    while(correctGuess < lengthOfWord){
        printf("Enter a guess letter: ");
        fgets(guess, 16, stdin);
        if(strncmp(guess, "quit",4) == 0){ // strcmp function will check if the user has type quit by checking just the first 4 characters
            quit = 1;
            break;
        }
        letterEntered = guess[0];
        printf("Letter Guesssed : %c\n", letterEntered);
        oldCorrect = correctGuess;
        int flag = 0;
        for(loopindex = 0;loopindex<lengthOfWord;loopindex++){
            if(letterGuessed[loopindex] == 1){
                continue;
            }
            if(letterEntered == guessWord[word][loopindex]){
                letterGuessed[loopindex] = 1;
                correctGuess ++;
            }
        }   

        if(oldCorrect == correctGuess && !flag){
            lives++;
            printf("Sorry Wrong Guuess\n");
            PrintHangMan(lives);
        }
        else{
            printf("Correct Guess\n");
        }

        if(lives == 5){
            printf("Yo've run out of lives\n");
            break;
        }

    }
    // if user quits then here is the condition

    if(quit == 1){
        printf("The user has quit early\n");
    }
    if(lives!=6 && quit ==0){
        printf("You've guess the word correctly %s\n", guessWord[word]);
    }



}
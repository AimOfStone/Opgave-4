#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
/*
Kør dette en gang i terminalen for at bruge emojis:
chcp 65001
$OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()
*/

int main (void){
//____________________________ Variables _________________________________
    int bot_score = 0;
    int player_Score = 0;
    char choice;
    bool begin;
    char player_input;
    char allowed_input[] = {'0','1','2','3','4'};
    bool valid;
    int bot_input;
    int check_winner(char player, char bot);

//_________________________________ choose to play or exit _________________________________
    printf(" Welcome to 🪨  ✂️  🗒️  🖖 🦎 !");


    while (1) {
        printf("\r\n (s) Single player \r\n (e) Exit \r\n select an item: ");
        choice = getchar();
        while (getchar() != '\n'); //flush indtil newline, ved ikke hvorfor?

        if (choice == 's'){ //Single player
            printf("You have chosen Single player! \r\n");
            begin = true;
            break;  //exit loop and begin game
        }
        else if (choice =='e'){ //Exit program
            printf("Ending program");
            return 0;
        }
        else if (choice != 'e' && choice !='s'){ //retry to get correct input
            printf("%c is not an allowed input", choice);

        }
    }

    //_________________________________ game running _________________________________

    if (begin) {
        printf("Starting game! 🎉 \r\n");
    }
    while(begin) { 


        //_________________________________ check if legal input _________________________________
        while(1){
            printf("Select a shape: \r\n  0🪨  || 1🦎  || 2✂️  || 3🗒️  || 4🖖: ");

            player_input = getchar();
            while (getchar() != '\n'); //flush until newline, ikke sikker på hvorfor.

            valid = false;
            for (int i = 0; i < 5; i++) {
                if (player_input == allowed_input[i]) {
                    valid = true;
                    break;
                }
            }

            if (!valid) {
                printf("%c is not an allowed input. Try again.\n", player_input);
            } else {
                //printf("Valid input: %c\n", player_input); //test for nu, for at se om det virker
                break;
            }
        }
        //_________________________________ bot RNG logic _________________________________
        srand(time(NULL));
        bot_input = rand() % 5 +'0';    //bot choice between 0-4
        printf("Bot chose: %c\n", bot_input);

        //_________________________________ check who wins _________________________________
        int result = check_winner(player_input, bot_input); //

        if (result == 1) {
            printf("You win this round!\n");
            player_Score++;
        } else if (result == -1) {
            printf("Bot wins this round!\n");
            bot_score++;
        } else {
            printf("It's a draw!\n");
        }
        //_________________________________ Print score + Check if game is finished _________________________________
        printf("👫:🤖 %d : %d \r\n", player_Score, bot_score);

        if (bot_score == 5){
            printf("🤖 Bot has won!");
            begin = false;
        }
        else if (player_Score == 5){
            printf("👫 Player has won!");
            begin = false;
        }  
    }

    return 0; 
}
    //____________________________________________________________________________________________________________________________________

    //_________________________________ Enum definition _________________________________
    enum RPSSL_e {
        ROCK = '0',
        LIZARD,
        SCISSOR,
        PAPER,
        SPOCK
    };

    enum RPSSL_e myRPSSL;

    //_________________________________ win checker (helper function) _________________________________
    int check_winner(char player, char bot) {
        if (player == bot) return 0; //draw

            switch(player) { //Switch so i can use case. Case faster than if/else.
                case ROCK: //Rock beats Scissors or Lizard
                    if (bot == SCISSOR || bot == LIZARD)
                        return 1; 
                    else
                        return -1;
                case LIZARD: //Lizard beats Paper or Spock
                    if (bot == PAPER || bot == SPOCK)
                        return 1; 
                    else
                        return -1;
                case SCISSOR: //Scissors beats Paper or Lizard
                    if (bot == PAPER || bot == LIZARD)
                        return 1; 
                    else
                        return -1;
                case PAPER: //Paper beats Rock or Spock
                    if (bot == ROCK || bot == SPOCK)
                        return 1; 
                    else
                        return -1;
                case SPOCK: //Spock beats Scissors or Rock
                    if (bot == SCISSOR || bot == ROCK)
                        return 1;
                    else
                        return -1;
            }
        return 0; //to make sure game doesn't break in case of error
    }



/*
pseudo code:

1. Welcome message once
2. Scanf to let player choose to play or exit once
    2.1 Check if input is allowed
    2.2 if exit -> end program
    2.3 if single player -> start game
3. "select an item" and "starting game" message once
4. Make 2 variables to keep score (X, Y)
5. While (X || Y) < 5 run the game
    6. print "Select Shape" + what numbers correspond to what shape
    7. Scanf the input from user
        7.1 error message if input != correct shape
    8. RNG for bots choice (possible its own function)
    9.print the bot's choice
    10. Helper-function to determine who gets a point. Case/switch faster than if/else
    11. Calculate who gets the point using helper function
        11.1 enum sets up symbolic names for user input
12. if (X || Y == 5) print winner
13. end program

Components:
print/getChar()
if/else statements
case/switch statements
While and for loops
RNG for the bot (* and time apperently according to)
Enum
*/
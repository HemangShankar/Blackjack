/*
Programmer:Hemang Shankar
Design Your Own Lab
*/ 

/* Algorithm
1. Give the user 500 dollars.

2. Assign every value of the card to an array including A(value 11).

3. Start the game and ask them how much do they want to bet?

4. Check if the bet is above 0 and below the user balance

5. Deal 2 random cards from the array to the user. Let User see the cards

6. Deal 2 random cards to the computer from the 13 card array. One of them must be displayed to the user. 

7. If the two cards of the user is equal to 21 - Wins the game, Initialmoney + (1 + 1/2 of bet) + bet

8. Showcase "Hit" and "Stay".

9. If player chooses hits
	(a) assign them 1 more card.
	(b)Add the values
		(1)If below 21, ask them if they want to hit or stand
	(c) redo this process 
	(d) Decide the winner 
	

10. If the user chooses stand
	a.  Reveal the all the cards of the dealer .
	b. Calculate the sum of the dealer's cards
		(1)If sum is 16 and lower, assign one more random card to the dealer
		(2)If the sum is 17 and higher, Decide the winner
		
		
11. Decide the winner
	a. If finalDealercards > 21, user wins the game, balance will increase twice of their bet
	b. If finalUserCards > 21, User loses the game and balance will decrease by the bet
	c. If the finalUserCards = 21, User wins the game and balance will increase by 1 and half of the bet
	d. if finalDealercards > finalUserCards, the user loses the game and balance will decrease by the bet
	e. if finalUserCards > finalDealercards, the uesr wins the game and balance will increase by 2 times the bet
	f. if finalDealercards == finalUserCards, bet will be returned to the user.

10. Display the userbalance and the game results.
	b. Caluculate the total sum of the cards by adding its values
	
	c. If sum is greater than 21, game ends, output= " Dealer got Busted"
	
	d. If sum is equal to 21, Game ends, output = "Dealer won"
	
	e. If sum is less than 21, recurse back to step 7.

8. If user says stay, they will reveal their second card

9 . if the computers card is below 16, will take one more card, else, will stay with the value.

10. If computer busts, player wins, 2 * bet + initial money

11. Else, if user's cards > computers cards, bet * 2. 

12. Else you lose and bet is gone
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {

  //Sets a random seed
  srand(time(NULL));

  //Declare and Initialize variables
  int initialMoney,bet, finalBalance, userInput, finalUser, sumDealer, finalDealer, sumUser;

  int randomCard_user1=0,randomCard_user2=0,randomCard_user3=0;
  int randomCard_dealer1=0,randomCard_dealer2=0,randomCard_dealer3=0;

  //Sets initial money to 500
  initialMoney = 500;

  //Creates two card sets - for player and dealer
  int arrayUser[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
  int arrayDealer[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

  //Selects two random cards from the array of the user
  randomCard_user1 = arrayUser[rand() % 13];
  randomCard_user2 = arrayUser[rand() % 13];

  //Selects two random cards from the array of the dealer
  randomCard_dealer1 = arrayDealer[rand() % 13];
  randomCard_dealer2 = arrayDealer[rand() % 13];

  //Adds the values of the two random cards dealt to the user and the dealer
  sumDealer = randomCard_dealer1 + randomCard_dealer2;
  sumUser = randomCard_user1 + randomCard_user2;
  
  //Clears screen
  system("clear");

  //Welcomes the user to the game
  printf("\nWelcome to BlackJack! You will begin with 500 dollars!\n");

  //Asks the user how much they are willing to bet from the 500 dollars
  printf("\nFor today's game, how much will you bet?\n");
  scanf("%i",&bet);
  
  //Repeatedly prompts the user to enter a valid bet
  while(bet <= 0 || bet > initialMoney)
  { 
    printf("\nPlease enter a valid bet!\n");
    scanf("%i", &bet);
  }

  //Prints the cards dealt to the user and their values. Prints one of the dealer's cards
  printf("\n\nYour two random cards dealt to you are %i and %i\n\n", randomCard_user1, randomCard_user2);

  printf("\nThe values of both your cards are: %i\n", sumUser);

  printf("\n\nOne of the random cards dealt to the dealer is a %i\n", randomCard_dealer1);

  //If the user's cards equal 21, they automatically win the game with a BlackJack
  if(randomCard_user1 + randomCard_user2 == 21){

    printf("\n\nCongratulations! You have a BlackJack and have won this round\n");

    finalBalance = initialMoney + bet + (1 + 1/2 * bet);

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }

else 

  while(1){
  
    //Prompts the user whether they want to hit or stay
    printf("\n\nDo you want to Hit or Stay? (1 = Hit / 0 = Stay)\n");
    scanf("%i", &userInput);

    //Repeatedly prompts the user to enter a valid commmand
    while(userInput != 0 && userInput != 1 ){

      printf("\nPlease enter a valid command to Hit or Stay! (1 = Hit / 0 = Stay\n");
      scanf("%i", &userInput);
    }

    //If the user hits, a random card from the array is dealt to them
    if (userInput == 1){
      randomCard_user3 = arrayUser[rand() % 13];
      printf("\nYour extra card dealt is %i\n", randomCard_user3); 
      sumUser = sumUser + randomCard_user3;
      printf("\nThe values of your cards are %i\n", sumUser);
    }
    
    //Comes out of the loop if the user stays
    if (userInput == 0){
      break;
    }
  }

  //If the user stays, the second card of the dealer is revealed to the user
  if (userInput == 0){
    printf("\nThe second card dealt to the dealer is %i\n", randomCard_dealer2);

  }

  //If the dealers cards are 16 and below, they are forced to take another card
  while (sumDealer <= 16){
      randomCard_dealer3 = arrayUser[rand() % 13];
      printf("\nAn extra card has been taken by the dealer!\n\n");
      sumDealer = sumDealer + randomCard_dealer3;
    
  //If the cards of the dealer are 17 and above, comes out of the loop
    if (sumDealer >= 17){
      break;
    }
  }

  //If the cards of the user is above 21, they bust and lose their game.
  if (sumUser > 21){
    printf("\nYou have lost this round for busting over 21! Sorry!\n");

    finalBalance = initialMoney - bet;

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }
  //If the cards of the user is 21, they win the game with a Blackjack
  else if (sumUser == 21){
    printf("\n\nCongratulations! You have a BlackJack and have won this round\n");

    finalBalance = initialMoney + bet + (1 + 1/2 * bet);

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }
  //If the dealer busts over 21, the user wins the game with twice their bet
  else if (sumDealer > 21){
    printf("\nCongratulations! You have won this round as the dealer has busted over 21!\n");

    finalBalance = initialMoney + (bet + (2 * bet));

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }

  //If the user's cards are higher than the dealers cards, they win the game
  else if (sumUser > sumDealer){
    printf("\n\nCongratulations! You have won this round as your cards are higher than the dealers!\n");

    finalBalance = initialMoney + bet + (2 * bet);

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }

  //If the dealer's cards are higher than the user's cards, the user loses the round
  else if (sumDealer > sumUser ){
    printf("\n\nYou have lost this round as the dealer's cards is higher than yours!\n");

    finalBalance = initialMoney - bet;

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }

  //If the user's cards and the dealer's cards are equal, the round is a tie
  else if (sumUser == sumDealer){
    printf("\n\nThe game has ended in a push as the dealer's cards is equivalent to your cards!\n");

    finalBalance = initialMoney;

    printf("\nThank you for playing the game! Your final balance is %i.\n", finalBalance);
  }

  return 0;
}

/*Welcome to BlackJack! You will begin with 500 dollars!

For today's game, how much will you bet?
450


Your two random cards dealt to you are 10 and 5


The values of both your cards are: 15


One of the random cards dealt to the dealer is a 11


Do you want to Hit or Stay? (1 = Hit / 0 = Stay)
1

Your extra card dealt is 10

The values of your cards are 25


Do you want to Hit or Stay? (1 = Hit / 0 = Stay)
0

The second card dealt to the dealer is 10

You have lost this round for busting over 21! Sorry!

Thank you for playing the game! Your final balance is 50.
*/

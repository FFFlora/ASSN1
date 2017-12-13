//
// Created by Flora on 10/13/2017.
//

#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

/*
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with
   several decks of cards at the same time.
*/
Card::Card() {
    int r = 1 + rand() % 4;
    switch (r) {
        case 1:
            suit = OROS;
            break;
        case 2:
            suit = COPAS;
            break;
        case 3:
            suit = ESPADAS;
            break;
        case 4:
            suit = BASTOS;
            break;
        default:
            break;
    }

    r = 1 + rand() % 10;
    switch (r) {
        case 1:
            rank = AS;
            break;
        case 2:
            rank = DOS;
            break;
        case 3:
            rank = TRES;
            break;
        case 4:
            rank = CUATRO;
            break;
        case 5:
            rank = CINCO;
            break;
        case 6:
            rank = SEIS;
            break;
        case 7:
            rank = SIETE;
            break;
        case 8:
            rank = SOTA;
            break;
        case 9:
            rank = CABALLO;
            break;
        case 10:
            rank = REY;
            break;
        default:
            break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default:
            break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default:
            break;
    }
    return rankName;
}

// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "golds";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "swords";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default:
            break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "2";
            break;
        case TRES:
            rankName = "3";
            break;
        case CUATRO:
            rankName = "4";
            break;
        case CINCO:
            rankName = "5";
            break;
        case SEIS:
            rankName = "6";
            break;
        case SIETE:
            rankName = "7";
            break;
        case SOTA:
            rankName = "10";
            break;
        case CABALLO:
            rankName = "Jack";
            break;
        case REY:
            rankName = "Queen";
            break;
        default:
            break;
    }
    return rankName;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
/*    enum rank {
        As = 1, Dos = 2, Tres = 3, Cuatro = 4, Cinco = 5, Seis = 6, Siete = 7, Sota = 10, Caballo = 11, Rey = 12
    };*/
    return static_cast<int>(rank)+1;
}

double Card::get_value() const {
    int rank = get_rank();
    if ((rank == 10) || (rank == 11) || (rank == 12)) {
        return 0.5;
    }
    else {
        return double(rank);
    }
}
// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator<(Card card2) const {
    return rank < card2.rank;
}

//Prints a card's information in Spanish and English
void Card::printCards() const {
    cout << "\t" << get_spanish_rank() << " de " << get_spanish_suit();
    cout << " (" << get_english_rank() << " of " << get_english_suit() << ")" << endl;
}



/* *************************************************
   Hand class
   ************************************************* */

//Adds a new card to the hand
void Hand::addCard(Card C) {
    cards.push_back(C);
}

//Prints the information of all cards in the hand
void Hand::printCards() const {
    for (int i = 0; i < cards.size(); i++) {
        cards[i].printCards();
    }
}

//Returns the total combined value of all cards in the hand
double Hand::get_total() const {
    double total = 0;
    for (int i = 0; i < cards.size(); i++) {
        total += cards[i].get_value();
    }
    return total;
}

//Returns true if the hand has busted (its value is over 7.5)
bool Hand::bust() const {
    if (get_total() > 7.5) {
        return true;
    }

    else {
        return false;
    }
}

/* Player class */

//Constructor which assigns a given amount of money
Player::Player(int m){
    money = m;
}

//Returns the amount of money the player has
int Player::get_money() const {
    return money;
}

//Increases the player's money by a given amount
void Player::gain(int money_to_gain) {
    money += money_to_gain;
}

//Decreases the player's money by a given amount
void Player::lose(int money_to_lose) {
    money -= money_to_lose;
}


/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.

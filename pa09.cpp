/// @author Arin Arjani
/// @note pa09
/// @file pa09.cpp
/// @version 2016-04-23
/// @brief 1. A function that initializes a new Deck of Cards.
///           All values should be in order by suit. (Hint: Use nested
///           loops to initialize each new Card before being added to the
///           Deck.)
///        2. A function that neatly prints a Deck of Cards.
///        3. A function that randomly shuffles a Deck of Cards.
///           (Hint: Generate a random number in the range 0..51 and
///           exchange the current card with the card in the random position.)
///        4. A function that deals a Hand of 5 Cards. As each card is
///           dealt, it should be removed from the Deck.
///        5. A driver program that initializes a new Deck of Cards
///           , shuffles them, then deals and prints a Hand.

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct {
  string suit;
  int value;
} Card;  // name is Cards

typedef vector<Card> Deck;  // Deck = [Cards, Cards, Cards];
typedef Deck Hand;  // Hand or new Deck

// ============================================================================
//                            PROTOTYPES
//=============================================================================
void initialize ( Deck& deck );
void print ( const Deck& deck );
void shuffle ( Deck& deck);
void deal ( Deck& deck, Hand& hand, int num_cards );

const int NUM_SUITS = 4;  // max num of suits in a deck of cards
const int NUM_VALUES = 13;  // max value totals in a suit
const int NUM_CARDS = 5;  // number of cards in a hand

int main() {
  srand( static_cast<unsigned>( time( NULL ) ) );
  Deck deck;  // create the deck to use
  Hand hand;  // create a hand to use

  //cout << "Normal Deck" << endl;
  initialize ( deck );
  //print ( deck );
  //cout << "Shuffled Deck" << endl;
  shuffle ( deck );
  //print ( deck );
  deal ( deck, hand, NUM_CARDS );
  cout << "Hand" << endl;
  print ( hand );
  //cout << "Deck after pop_back" << endl;
  //print ( deck );

  return 0;
}

// ============================================================================
//                            FUNCTIONS
//=============================================================================

/// @brief Initaliza a new Deck of Cards
/// @param deck A deck of Cards
void initialize ( Deck& deck ) {
  deck.clear();  // want to start with a vector having no elements
  for ( unsigned i = 0; i < NUM_SUITS; i++ ) {
      for ( unsigned z = 1; z <= NUM_VALUES; z++ ) {
        Card card;  // creates a card with suit and value
        switch ( i ) {
            case 0: { card.suit = "Clubs"; break; }
            case 1: { card.suit = "Diamonds"; break; }
            case 2: { card.suit = "Hearts"; break; }
            case 3: { card.suit = "Spades"; break; }
            default: { break; }
        }
        card.value = static_cast<int>(z);
        deck.push_back(card);
      }
  }
}

/// @brief Print a Deck of Cards
/// @param The Deck of Cards to print
void print ( const Deck& cards ) {
  for ( unsigned i = 0; i < cards.size(); i++ ) {
    switch ( cards[i].value ) {
      case 1: { cout << "Suit: " << cards[i].suit << " value: " << "Ace" << endl; break; }
      case 2: { cout << "Suit: " << cards[i].suit << " value: " <<  "Deuce" << endl; break; }
      case 3: { cout << "Suit: " << cards[i].suit << " value: " <<  3 << endl; break; }
      case 4: { cout << "Suit: " << cards[i].suit << " value: " <<  4 << endl; break; }
      case 5: { cout << "Suit: " << cards[i].suit << " value: " <<  5 << endl; break; }
      case 6: { cout << "Suit: " << cards[i].suit << " value: " <<  6 << endl; break; }
      case 7: { cout << "Suit: " << cards[i].suit << " value: " <<  7 << endl; break; }
      case 8: { cout << "Suit: " << cards[i].suit << " value: " <<  8 << endl; break; }
      case 9: { cout << "Suit: " << cards[i].suit << " value: " <<  9 << endl; break; }
      case 10: { cout << "Suit: " << cards[i].suit << " value: " <<  10 << endl; break; }
      case 11: { cout << "Suit: " << cards[i].suit << " value: " <<  "Jack" << endl; break; }
      case 12: { cout << "Suit: " << cards[i].suit << " value: " <<  "Queen" << endl; break; }
      case 13: { cout << "Suit: " << cards[i].suit << " value: " <<  "King" << endl; break; }
      default: { break; }
    }

    //cout << "Suit: " << cards[i].suit << " value: " <<  cards[i].value << endl;
  }
}


/// @brief Shuffle the deck of Cards
/// @param the Deck of cards to be shuffled
void shuffle ( Deck& deck) {
  /*
  temp = a;
  b = a + 1;
  b = temp;
  a = b;
  */
  for ( unsigned i = 0; i < deck.size(); i++ ) {
    Card temp = deck[i];  // a holder variable for shuffling
    unsigned random = rand()%52;  // create a random int [0,52]
    deck[i] = deck[random];
    deck[random] = temp;
  }
}

/// @brief Deal a Hand of cards from a deck of cards
///        using the specified number of cards in the hand.
/// @param deck The Deck of Cards
/// @param hand The new Dand of Cards
/// @param num_cards The number of cards in hand
void deal ( Deck& deck, Hand& hand, int num_cards ) {
  hand.clear();
  for ( int i = 0; i < num_cards; i++ ) {
    Card card = deck.back();  // get the end of the deck
    deck.pop_back();  // delete the end of the deck
    hand.push_back(card);  // put the end of the deck into the hand
  }
}

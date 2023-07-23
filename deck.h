#ifndef _DECK_H_
#define _DECK_H_




#include <string.h>
#include <stdlib.h>
#include <stdio.h>




/**
 * enum kind_e - that is Suit Of A Card.
 *
 * @SPADE: That 0, Or Spades.
 * @HEART: that 1, Or Hearts
 * @CLUB: that 2, Or Clubs
 * @DIAMOND: that 3, Or Diamonds
 */


typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Card Representation.
 *
 * @value: that is the value Of A Card
 * From "Ace" To "King".
 *
 * @kind: That is the Kind Of A Card.
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;


/**
 * struct deck_node_s - that is the deck Of Card
 *
 * @card: that is the Pointer To A Card Of A Node.
 * @prev: that is the Pointer to the previous node of the list
 * 
 * @next: that is the Pointer To A Next Node Of A List.
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* _DECK_H_ */

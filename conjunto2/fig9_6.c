/* ECP: FILEname=fig9_6.c */
   typedef enum { Heart, Diamond, Club, Space } SuitType;

   typedef struct Card
   {
       unsigned int FaceVal;
       SuitType Suit;
   } Card;

       /* Constants To Allow Multiple Decks */
   #define Decks          1
   #define CardsPerDeck   52
   #define TotalCards     ( Decks * CardsPerDeck )
   #define MinCards       1    /* Minimum Before New Decks Needed */

   #include <stdlib.h>

   /* Discard Old Stack Of Cards And get New Cards */
   void
   NewDeck( Card SomeCards[ ], const int NumDecks )
   {
       int i, j, k;

           /* Load Up All The Cards */
       for( i = 0; i < NumDecks; i++ )
           for( j = 0; j < 13; j++ )
               for( k = 0; k < 4; k++ )
               {
                   SomeCards[ 52*i + 4*j + k ].Suit = k;
                   SomeCards[ 52*i + 4*j + k ].FaceVal = j + 1;
               }

           /* Shuffle */
       for( i = 1; i < TotalCards; i++ )
       {
           int RandCard = rand( ) % ( i + 1 );  /* Choose Random */
           Card TmpCard = SomeCards[ i ];       /* Card And Swap */

           SomeCards[ i ] = SomeCards[ RandCard ];
           SomeCards[ RandCard ] = TmpCard;
       }
   }

/* ECP: FILEname=fig9_7.c */
   /* Return The Next Card */
   void
   Deal( Card *OneCard )
   {
       static Card TheCards[ TotalCards ];
       static int CardsUndealt = 0;

       if( CardsUndealt < MinCards )
       {
           NewDeck( TheCards, Decks );
           CardsUndealt = TotalCards;
       }

       *OneCard = TheCards[ --CardsUndealt ];
   }

   /* Get Five Cards */
   void
   DealHand( Card Hand[ ] )
   {
       int i;

       for( i = 0; i < 5; i++ )
           Deal( &Hand[ i ] );
   }

   /* Returns Non Zero If All Cards Have Same Suit */
   int
   IsFlush( const Card Hand[ ] )
   {
       int i;

       for( i = 1; i < 5; i++ )
           if( Hand[ i ].Suit != Hand[ 0 ].Suit )
               return 0;

       return 1;
   }

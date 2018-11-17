/* ECP: FILEname=fig7_18.c */
   enum Piece { Human, Computer, Empty  };
   enum Side { You, Me };
   enum Color { X, O };
   enum Score { HumanWin, Draw, ComputerWin, Unclear };

   typedef enum Piece Piece;
   typedef enum Side Side;
   typedef enum Score Score;
   typedef enum Color Color;

   #define Bsize 3	       /* 3 By 3 Tic Tac Toe */
   typedef Piece BoardType[ Bsize ][ Bsize ];


   /* Prototypes For Two Unwritten Routines */
   void GetMove( BoardType B, Side S );
   int IsWon( BoardType B, Side S );


   /* Place Piece P ( Possibly Empty ) */
   void
   Place( BoardType Board, int Row, int Column, Piece P )
   {
       Board[ Row ][ Column ] = P;
   }

   int
   IsFull( BoardType Board )
   {
       int Row, Column;

       for( Row = 0; Row < Bsize; Row++ )
           for( Column = 0; Column < Bsize; Column++ )
               if( Board[ Row ][ Column ] == Empty )
                   return 0;

       return 1;
   }

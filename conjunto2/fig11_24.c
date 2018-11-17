/* ECP: FILEname=fig11_24.c */
   /* Find The Best Move, And return Its Value */
   /* Assumes: Humanwin < Draw < Computerwin */

   int
   ChooseMove( BoardType B, Side S, int *BestRow, int *BestColumn )
   {
       Side Opp;                              /* The Opponent */
       int Reply;                /* Value Of Opponent's Reply */
       int Value;               /* Value Of Best Move, So Far */
       Piece Mypiece;        /* Piece Corresponding To Side S */
       int Row, Column;                           /* Counters */
       int Z;                                  /* Placeholder */
       int SimpleEval;       /* Result Of A Simple Evaluation */

       if( ( SimpleEval = Terminal( B ) ) != Unclear )
           return SimpleEval; /* Immediate Win, Lose, Or Draw */

           /* Set Some Variables Depending On Who S Is */
       if( S == Me )
       {
           Opp = You; Value = HumanWin; Mypiece = Computer;
       }
       else
       {
           Opp = Me; Value = ComputerWin; Mypiece = Human;
       }

           /* Search for A Move */
       for( Row = 0; Row < Bsize; Row++ )
           for( Column = 0; Column < Bsize; Column++ )
               if( IsEmpty( B, Row, Column ) )
               {
                   Place( B, Row, Column, Mypiece );
                   Reply = ChooseMove( B, Opp, &Z, &Z );
                   Unplace( B, Row, Column );

                      /* Test if S Gets A Better Position */
                      /* If So, Update */
                   if( S == Me && Reply > Value ||
                       S == You && Reply < Value )
                   {
                       Value = Reply;
                       *BestRow = Row; *BestColumn = Column;
                   }
               }

       return Value;
   }

/* ECP: FILEname=fig11_25.c */
   /* Same As ChooseMove, But Use Alpha Beta Pruning. */

   int
   Choose( BoardType B, Side S, int *BestRow, int *BestColumn,
           int Alpha, int Beta )
   {

           /* Up To Here, Everything Is Identical... */
           /* Set Some Variables Depending On Who S Is */
       if( S == Me )
       {
           Opp = You; Value = Alpha; Mypiece = Computer;
       }
       else
       {
           Opp = Me; Value = Beta; Mypiece = Human;
       }

           /* Search for A Move */
       for( Row = 0; Row < Bsize; Row++ )
           for( Column = 0; Column < Bsize; Column++ )
               if( IsEmpty( B, Row, Column ) )
               {
                   Place( B, Row, Column, Mypiece );
                   if( S == Me )
                   {
                       Reply = Choose( B, Opp, &Z, &Z, Value, Beta );
                       Unplace( B, Row, Column );
                       if( Reply > Value )
                       {
                           *BestRow = Row; *BestColumn = Column;
                           if( ( Value = Reply ) >= Beta )
                               return Value;  /* Refutation Found */
                       }
                   }
                   else
                   {
                       Reply = Choose( B, Opp, &Z, &Z, Alpha, Value );
                       Unplace( B, Row, Column );
                       if( Reply < Value )
                       {
                           *BestRow = Row; *BestColumn = Column;
                           if( ( Value = Reply ) <= Alpha )
                               return Value;  /* Refutation Found */
                       }
                   }
               }

       return Value;
   }

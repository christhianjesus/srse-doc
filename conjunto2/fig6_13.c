/* ECP: FILEname=fig6_13.c */
   void            * Swaps Where X And Y Point, Not Their Value */
   WrongSwap1( const int *X, const int *Y )
   {
       const int *Tmp;

       Tmp = X;
       X   = Y;           /* Would Be Caught By Compiler If The */
       Y   = Tmp;         /* const Directive Was Used Correctly */
   }


   void            /* Can Lead To A Difficult To Track Down Bug */
   WrongSwap2( int * const X, int * const Y )
   {
       int *Tmp;         /* Pointer Not Needed To Store The int */

       *Tmp = *X;        /* Major Error: Tmp Is Uninitialized */
       *X   = *Y;
       *Y   = *Tmp;
   }

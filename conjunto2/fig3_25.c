/* ECP: FILEname=fig3_25.c */
   /* Print Prime Factorization Of A Number */

   #include <stdio.h>

   main( void )
   {
       unsigned long NumberToFactor, PossibleFactor, UnfactoredPart;

       printf( "Enter a number to factor: " );
       scanf( "%lu", &NumberToFactor );

       PossibleFactor = 2;
       UnfactoredPart = NumberToFactor;
       while( PossibleFactor * PossibleFactor <= UnfactoredPart )
       {
           if( UnfactoredPart % PossibleFactor == 0 )
           {	/* Found A Factor */
               printf( "%lu ", PossibleFactor );
               UnfactoredPart /= PossibleFactor;
               continue;
           }

           /* No Factor; try Next Factor */
           if( PossibleFactor == 2 )
               PossibleFactor = 3;
           else
               PossibleFactor += 2;
       }

          /* Print Last Factor */
       printf( "%lu\n", UnfactoredPart );
   }

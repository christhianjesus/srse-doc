/* ECP: FILEname=fig3_20.c */
   /* Find Numbers Equal To Sum Of The Cubes Of Their Digits */

   #include <stdio.h>

   main( void )
   {
       int Hund, Tens, Ones;

       for( Hund = 1; Hund <= 9; Hund++ )
           for( Tens = 0; Tens <= 9; Tens++ )
               for( Ones = 0; Ones <= 9; Ones++ )
                   if( Hund * Hund * Hund + Tens * Tens * Tens
                          + Ones * Ones * Ones
                            == 100 * Hund + 10 * Tens + Ones )
                       printf( "%d%d%d\n", Hund, Tens, Ones );
   }

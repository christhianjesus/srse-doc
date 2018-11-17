/* ECP: FILEname=fig3_26.c */
   /* Print Distribution Of Last Digit Of Random Numbers */

   #include <stdio.h>
   #include <stdlib.h>                 /* For rand( ) */

   main( void )
   {
       int i;
       int Zeros = 0, Odds = 0, Others = 0;


       for( i = 0; i < 10000; i++ )
           switch( rand( ) % 10 )
           {
             case 0:
               Zeros++;
               break;

             case 2:
             case 4:
             case 6:
             case 8:
               Others++;
               break;

             default:
               Odds++;
               break;
           }

       printf( "Zeros: %d, odds: %d, others: %d\n",
                           Zeros, Odds, Others );
   }

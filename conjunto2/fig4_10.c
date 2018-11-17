/* ECP: FILEname=fig4_10.c */
   #include <stdio.h>
   #include "prime.h"

   /* Return An Odd Starting Number */
   unsigned long int
   FirstTrial( void )
   {
       unsigned long int StartingNum;

       printf( "Enter a starting number: " );
       if( scanf( "%lu", &StartingNum ) == 1 )
           return StartingNum % 2 ? StartingNum : ++StartingNum;

       printf( "Bad number entered\n" );
       return 0;
   }


   /* Find Next Prime After Some Starting Point */
   main( void )
   {
       printf( "Next largest prime is %lu\n",
                       FindPrime( FirstTrial( ) ) );
   }

/* ECP: FILEname=fig3_28.c */
   /* Find Next Prime After StartingNumber */

   #include <stdio.h>

   main( void )
   {
       unsigned long int Divisor, PossiblePrime;

       printf( "Enter the starting number: " );
       scanf( "%lu", &PossiblePrime );

       if( PossiblePrime <= 2 )
           PossiblePrime = 2;
       else
       if( PossiblePrime != 3 )
       {
           if( PossiblePrime % 2 == 0 )
               PossiblePrime++;	/* Need An Odd Number */
       
           for( ; ; PossiblePrime += 2 )
               for( Divisor = 3; PossiblePrime % Divisor; Divisor += 2 )
                   if( Divisor * Divisor > PossiblePrime )
                       goto FoundPrime;
       }

   FoundPrime:
       printf( "Next largest prime is %lu\n", PossiblePrime );
   }

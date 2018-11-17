/* ECP: FILEname=fig3_24.c */
   /* Find Next Prime After Some Starting Number */

   #include <stdio.h>
   #define TRUE 1

   main( void )
   {
       unsigned long int Divisor, PossiblePrime;
       int FoundPrime;

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
           {
               FoundPrime = !TRUE;
               for( Divisor = 3; PossiblePrime % Divisor; Divisor += 2 )
                   if( Divisor * Divisor > PossiblePrime )
                   {
                       FoundPrime = TRUE;
                       break;
                   }
       
               if( FoundPrime )
                   break;
           }
       }

       printf( "Next largest prime is %lu\n", PossiblePrime );
   }

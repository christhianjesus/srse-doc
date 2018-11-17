/* ECP: FILEname=fig4_1.c */
   #include <stdio.h>

   /* Return True Iff N Is Prime */
   int
   IsPrime( unsigned long int N )
   {
       unsigned long int Divisor;

       if( N % 2 )
           for( Divisor = 3; N % Divisor; Divisor += 2 )
               if( Divisor * Divisor > N )
                   return 1;

       return N == 2 || N == 3;
   }


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
       unsigned long int PossiblePrime = FirstTrial( );

       for( ; !IsPrime( PossiblePrime ); PossiblePrime += 2 )
           ;

       printf( "Next largest prime is %lu\n", PossiblePrime );
   }

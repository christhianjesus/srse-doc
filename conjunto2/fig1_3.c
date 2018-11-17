/* ECP: FILEname=fig1_3.c */
   #include <stdio.h>

   unsigned long int
   Factorial( unsigned long int N )
   {
       int i;
       unsigned long int Answer = 1;

       for( i = 1; i <= N; i++ )
           Answer *= i;

       return Answer;
   }

   main( void )
   {
       int i;
       const int MaxNum = 12;

       printf( " N      N!\n" );
       for( i = 0; i <= MaxNum; i++ )
           printf( "%2d %10lu\n", i, Factorial( i ) );

       return 0;
   }

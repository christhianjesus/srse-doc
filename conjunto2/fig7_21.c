/* ECP: FILEname=fig7_21.c */
   #include <stdio.h>

   void
   PrintSize( int A[ ] )
   {
       printf( "Size of formal A[] is %u\n", sizeof( A ) );
   }

   main( void )
   {
       int A[ ] = { 1, 2, 3, 4, 5 };

       printf( "Size of actual A[] is %u\n", sizeof( A ) );
       printf( "A has %u elements\n", sizeof( A )/sizeof( A[ 0 ] ) );
       printf( "Ints are %u bytes\n\n", sizeof( int ) );
       PrintSize( A );

       return 0;
   }

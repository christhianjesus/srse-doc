/* ECP: FILEname=fig7_11.c */
   #include <stdio.h>
   #define MaxN 10

   /* Read Up To MaxItems Ints, With No Attempts At Error Recovery */
   int
   GetInts( int Array[ ], int MaxItems )
   {
       int i = 0;

       printf( "Enter up to %d integers: ", MaxItems );
       while( i < MaxItems && scanf( "%d", &Array[ i ] ) == 1 )
           i++;

       return i;
   }

   /* Print Non-Duplicates: Sorted Array Array With N Items */
   void
   PrintNondup( const int Array[ ], unsigned int N )
   {
       int i;

       printf( "%d", Array[ 0 ] );
       for( i = 1; i < N; i++ )
           if( Array[ i ] != Array[ i - 1 ] )
               printf( " %d", Array[ i ] );
       printf( "\n" );
   }

   main( void )
   {
       int Num[ MaxN ];
       int ItemsRead;

       ItemsRead = GetInts( Num, MaxN );
       printf( "Processing %d items\n", ItemsRead );
       if( ItemsRead > 0 )
       {
           InsertSort( Num, ItemsRead );
           PrintNondup( Num, ItemsRead );
       }

       return !ItemsRead;
   }

/* ECP: FILEname=fig7_13.c */
   #include <stdio.h>
   #define MaxN 10
   typedef int IntArray[ MaxN ];

   /* Print Non-Duplicates: Array Array With N Items */
   /* Do Not Alter The Array */

   void
   PrintNondup( const IntArray Array, unsigned int N )
   {
       IntArray Tmp;	/* A Temporary Array */
       int i;

       for( i = 0; i < N; i++ )	/* Copy Into Tmp */
           Tmp[ i ] = Array[ i ];
       InsertSort( Tmp, N );      /* Sort Tmp */

       printf( "%d", Tmp[ 0 ] );
       for( i = 1; i < N; i++ )
           if( Tmp[ i ] != Tmp[ i - 1 ] )
               printf( " %d", Tmp[ i ] );
       printf( "\n" );
   }

   main( void )
   {
       IntArray Num;
       int ItemsRead;

       ItemsRead = GetInts( Num, MaxN );
       printf( "Processing %d items\n", ItemsRead );
       if( ItemsRead > 0 )
           PrintNondup( Num, ItemsRead );

       return !ItemsRead;
   }

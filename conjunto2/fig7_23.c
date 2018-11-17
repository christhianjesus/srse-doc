/* ECP: FILEname=fig7_23.c */
   #include <stdio.h>
   #include <stdlib.h>

   main( void )
   {
       int *NumArray;       /* A Dynamically Allocated Array */
       int ItemsRead = 0;

       printf( "How many items? " );
       scanf( "%d", &ItemsRead );
       if( ItemsRead <= 0 || ItemsRead > MaxN )
           Error( "ItemsRead is out of range" );

       NumArray = malloc( sizeof( int ) * ItemsRead );
       if( NumArray == NULL )
           Error( "Out of memory" );

       if( GetInts( NumArray, ItemsRead ) != ItemsRead )
           Error( "Not enough input" );

       PrintNondup( NumArray, ItemsRead );

       return !ItemsRead;
   }

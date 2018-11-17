/* ECP: FILEname=fig7_25.c */
   #include <stdio.h>
   #include <stdlib.h>

   /* Print Non-Duplicates: Array Has N Items */
   /* Since We Do Not Know N, TmpArray Is Dynamically Allocated */
   /* However, We Must Now Remember To free The Memory! */
   /* Array Is Left Untouched */

   void
   PrintNondup( const int Array[ ], const unsigned int N )
   {
       int *TmpArray;                      /* A Temporary Array */
       int i;

       TmpArray = malloc( sizeof( int ) * N );
       if( TmpArray == NULL )
           Error( "No memory for temporary array" );

       for( i = 0; i < N; i++ )           /* Copy Into TmpArray */
           TmpArray[ i ] = Array[ i ];
       Shellsort( TmpArray, N );               /* Sort TmpArray */

       printf( "%d", TmpArray[ 0 ] );
       for( i = 1; i < N; i++ )
           if( TmpArray[ i ] != TmpArray[ i - 1 ] )
               printf( " %d", TmpArray[ i ] );
       printf( "\n" );

       free( TmpArray );             /* Must free The Array Now */
   }

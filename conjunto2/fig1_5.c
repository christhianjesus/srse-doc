/* ECP: FILEname=fig1_5.c */
   #include <stdio.h>

   /* Compute Frequency Of Lottery Numbers */

   #define MaxNum 49       /* Numbers Range From 1 To 49 */

   main( void )
   {
       int Count[ MaxNum + 1 ];    /* Frequency Of Each Number */
       int Number; 
       int i;

       for( i = 0; i <= MaxNum; i++ )
           Count[ i ] = 0;

           /* Note: No Prompting For Input */
       while( scanf( "%d", &Number ) == 1 )
           if( Number < 1 || Number > MaxNum )
               printf( "Out of range number ignored\n" );
           else
               Count[ Number ]++;

           /* Output The Data, Seven Numbers Per Line */
       for( i = 1; i <= MaxNum; i++ )
       {
           printf( "%3d:%4d", i, Count[ i ] );
           if( i % 7 == 0 )
               printf( "\n" );
           else
               printf( "   " );
       }

       return 0;
   }

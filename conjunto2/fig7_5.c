/* ECP: FILEname=fig7_5.c */
   #include <stdio.h>

   /* Print Up To MaxN Integers, But Avoid Duplicates */

   #define MaxN 10

   main( void )
   {
       int Num[ MaxN ], Tmp;
       int j, Counter, ItemsRead = 0;

           /* Read Input */
       printf( "Enter up to %d integers: ", MaxN );
       while( ItemsRead < MaxN
                       && scanf( "%d", &Num[ ItemsRead ] ) > 0 )
           ItemsRead++;

           /* Sort Input, Using Insertion Sort */
       for( Counter = 1; Counter < ItemsRead; Counter++ )
       {
           Tmp = Num[ Counter ];
           for( j = Counter; j > 0 && Tmp < Num[ j - 1 ]; j-- )
               Num[ j ] = Num[ j - 1 ];
           Num[ j ] = Tmp;
       }

           /* Output Non-Duplicates */
       printf( "%d", Num[ 0 ] );
       for( Counter = 1; Counter < ItemsRead; Counter++ )
           if( Num[ Counter ] != Num[ Counter - 1 ] )
               printf( " %d", Num[ Counter ] );
       printf( "\n" );

       return 0;	/* Normal Exit */
   }

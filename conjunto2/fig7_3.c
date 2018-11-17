/* ECP: FILEname=fig7_3.c */
   #include <stdio.h>

   /* Print Four Integers, But Avoid Duplicates */

   #define CompExch( X, Y ) \
       if( X > Y ) { int _Tmp; _Tmp = X; X = Y; Y = _Tmp; }

   main( void )
   {
       int Num[ 4 ];   /* Num[ 0 ] Num[ 1 ] Num[ 2 ] Num[ 3 ] */

       printf( "Enter four integers: " );
       if( scanf( "%d %d %d %d",
               &Num[ 0 ], &Num[ 1 ], &Num[ 2 ], &Num[ 3 ] ) != 4 )
       {
           printf( "Expected four integers -- exiting...\n" );
           return 1;
       }

       CompExch( Num[ 0 ], Num[ 1 ] );
       CompExch( Num[ 2 ], Num[ 3 ] );
       CompExch( Num[ 0 ], Num[ 2 ] );
       CompExch( Num[ 1 ], Num[ 3 ] );
       CompExch( Num[ 1 ], Num[ 2 ] );

       printf( "%d", Num[ 0 ] );
       if( Num[ 1 ] != Num[ 0 ] )
           printf( " %d", Num[ 1 ] );
       if( Num[ 2 ] != Num[ 1 ] )
           printf( " %d", Num[ 2 ] );
       if( Num[ 3 ] != Num[ 2 ] )
           printf( " %d", Num[ 3 ] );
       printf( "\n" );

       return 0;	/* Normal Exit */
   }

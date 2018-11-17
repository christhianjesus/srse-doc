/* ECP: FILEname=fig7_2.c */
   #include <stdio.h>

   #define CompExch( X, Y ) \
       if( X > Y ){ int _Tmp; _Tmp = X; X = Y; Y = _Tmp; }

   /* Print Four Integers, But Avoid Duplicates */

   main( void )
   {
       int Num1, Num2, Num3, Num4;

       printf( "Enter four integers: " );
       if( scanf( "%d %d %d %d",
                   &Num1, &Num2, &Num3, &Num4 ) != 4 )
       {
           printf( "Expected four integers -- exiting...\n" );
           return 1;
       }

       CompExch( Num1, Num2 );
       CompExch( Num3, Num4 );
       CompExch( Num1, Num3 );
       CompExch( Num2, Num4 );
       CompExch( Num2, Num3 );

       printf( "%d", Num1 );
       if( Num2 != Num1 )
           printf( " %d", Num2 );
       if( Num3 != Num2 )
           printf( " %d", Num3 );
       if( Num4 != Num3 )
           printf( " %d", Num4 );
       printf( "\n" );

       return 0;	/* Normal Exit */
   }

/* ECP: FILEname=fig7_1.c */
   #include <stdio.h>

   /* Print Three Integers, But Avoid Duplicates */

   main( void )
   {
       int Num1, Num2, Num3;

       printf( "Enter three integers: " );
       if( scanf( "%d %d %d", &Num1, &Num2, &Num3 ) != 3 )
       {
           printf( "Expected three integers -- exiting...\n" );
           return 1;
       }

       if( Num1 == Num2 )
           if(  Num2 == Num3 )
               printf( "%d\n", Num1 );
           else
               printf( "%d %d\n", Num1, Num3 );
       else	/* Num1 != Num2 */
           if( Num1 == Num3 || Num2 == Num3 )
               printf( "%d %d\n", Num1, Num2 );
           else
               printf( "%d %d %d\n", Num1, Num2, Num3 );

       return 0;	/* Normal Exit */
   }

/* ECP: FILEname=fig7_8.c */
   #include <stdio.h>

   #define Len 3

   main( void )
   {
       int First, Second;
       int Num[ Len ];
       int Third, Fourth;
       int i;

           /* Initialize Array To Zero, Other Variables To Five */
       First = Second = Third = Fourth = 5;
       for( i = 0; i < Len; i++ )
           Num[ i ] = 0;

       printf( "Addresses are:\n" );
       printf( "&First = %x, &Second = %x\n", &First, &Second );
       printf( "&Third = %x, &Fourth = %x\n", &Third, &Fourth );
       for( i = 0; i < Len + 2; i++ )
           printf( "&Num[%d] = %x\n", i, &Num[ i ] );
       printf( "\n" );

             /* Print Array Starting Point */
       printf( "Num = %x\n", Num );
       /* This Will Usually Print One Of Other Variables */
       printf( "Num[%d] = %d\n", Len + 1, Num[ Len + 1 ] );

       /* This Will Usually Overwrite One Of Other Variables */
       Num[ Len + 1 ] = 0;
       printf( "First = %d, Second = %d\n", First, Second );
       printf( "Third = %d, Fourth = %d\n", Third, Fourth );
   }

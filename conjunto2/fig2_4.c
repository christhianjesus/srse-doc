/* ECP: FILEname=fig2_4.c */
   #include <stdio.h>

   main( void )
   {
       int First = 12, Second, Third = 6;

       Second = 8;
       printf( "The ints: %d %d %d\n", First, Second, Third );
       First = Third;
       printf( "The ints: %d %d %d\n", First, Second, Third );
       Third += Second;
       printf( "The ints: %d %d %d\n", First, Second, Third );
       First = Second + Third;
       printf( "The ints: %d %d %d\n", First, Second, Third );
       First++;
       ++Second;
       printf( "The ints: %d %d %d\n", First, Second, Third );
       Third = First++ + ++Second;
       printf( "The ints: %d %d %d\n", First, Second, Third );
   }

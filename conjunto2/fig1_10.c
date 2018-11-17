/* ECP: FILEname=fig1_10.c */
   #include <stdio.h>


   void
   Swap( int * const X, int * const Y )
   {
       int Tmp;

       Tmp = *X;
       *X  = *Y;
       *Y  = Tmp;
   }


   main( void )
   {
       int A = 5, B = 7;

       Swap( &A, &B );          /* Must Pass The Address */
       printf( "%d %d\n", A, B );

       return 0;
   }

/* ECP: FILEname=fig6_10.c */
   #include <stdio.h>

   main( void )
   {
       const int X = 5;               /* X Should Not Change */
       const int *PtrC = &X;     /* A Constant Pointer To It */
       int *PtrNC = ( int * ) PtrC; /* PtrNC Is Not Constant */

       *PtrNC = 10;                    /* So This Changes X! */
       printf( "%d\n", X );

       return 0;
   }

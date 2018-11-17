/* ECP: FILEname=fig7_31.c */
   #include <stdio.h>
   #define MaxN 10

   /* Read Up To MaxItems Ints; No Attempts At Error Recovery */
   int
   GetInts( int *Array, int MaxItems )
   {
       int i = 0;

       printf( "Enter up to %d integers: ", MaxItems );
       while( i < MaxItems && scanf( "%d", Array++ ) == 1 )
           i++;

       return i;
   }

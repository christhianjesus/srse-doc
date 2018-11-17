/* ECP: FILEname=fig6_1.c */
   /* A Very Flawed Program */

   #include <stdio.h>

   int Global;

   main( void )
   {
       static int X, Y, Z = 1;
       int Local;

           /* First, We Will Be Nosey */
       printf( "X, Y, and Z are at %x, %x, %x\n", &X, &Y, &Z );
       printf( "Global is at: %x\n", &Global );
       printf( "Local is at: %x\n\n", &Local );

       printf( "X, Y, and Z are at %u, %u, %u\n", &X, &Y, &Z );
       printf( "Values of X, Y, and Z: %d %d %d\n", X, Y, Z );

           /* Now Show Some Typical scanf Errors */
       printf( "Enter 1 to read into Y, 2 for Z\n" );
       scanf( "%d", &X );
       if( X == 1 )
       {
           printf( "Enter Y: " );
           scanf( "%d", Y );		/* Wrong! */
           printf( "Y = %d\n", Y );
       }
       else
       if( X == 2 )
       {
           printf( "Enter Z: " );
           scanf( "%d", Z );		/* Wrong! */
           printf( "Z = %d\n", Z );
       }
       return 0;
   }

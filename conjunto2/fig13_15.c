/* ECP: FILEname=fig13_15.c */
   #include <stdio.h>
   #include <unistd.h>

   main( void )
   {
       printf( "No flush because no newline" );
       fork( );            /* No Error Checks */
       return 0;           /* Call To exit( ) Is Implicit */
   }

/* ECP: FILEname=fig8_1.c */
   #include <stdio.h>

   main( void )
   {
       char Ch;

       while( scanf( "%c", &Ch ) != EOF )
           printf( "Read a *%c*, internal number %d\n", Ch, Ch );

       return 0;
   }

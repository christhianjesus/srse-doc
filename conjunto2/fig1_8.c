/* ECP: FILEname=fig1_8.c */
   #include <stdio.h>

   /* Read And Write Strings */

   #define MaxLen 512

   main( void )
   {
       char Str[ MaxLen + 1 ];

       while( scanf( "%s", Str ) == 1 )
           printf( "I read %s\n", Str );

       return 0;
   }

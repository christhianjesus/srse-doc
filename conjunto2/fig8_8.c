/* ECP: FILEname=fig8_8.c */
   /* Generate Routine in Previous Figure */
   /* This Program Works Only An ASCII Machine, */
   /* But Code That Is Generated Is Portable To Any Machine */

   #include <stdio.h>

   main( void )
   {
       char C;

       printf( "int\nToUpper( char ch )\n{\n" );    /* ToUpper */

       printf( "\tswitch( ch )\n\t{\n" );      /* Start switch */

       for( C = 'a'; C <= 'z'; C++ )            /* Print Cases */
           printf( "\t\tcase '%C': return '%C';\n",
                                                  C, C + 'A'-'a' );
       printf( "\t\tdefault : return ch;\n" );

       printf( "\t}\n}\n" );                 /* Closing Braces */

       return 0;
   }

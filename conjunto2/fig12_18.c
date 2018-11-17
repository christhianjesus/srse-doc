/* ECP: FILEname=fig12_18.c */
   #include <stdio.h>
   #include <ctype.h>

   int Cflag = 1;         /* Print out Character Counts */
   int Lflag = 1;         /* Print out Line Counts */
   int Wflag = 1;         /* Print out Word Counts */

   main( int argc, char *argv[ ] )
   {
       argv++; argc--;		/* Skip Command Name */

       if( argc > 0 && **argv == '-' )
       {
           SetOptions( *argv );
           argv++; argc--;
       }

           /* If No Files, Use Standard Input */
       if( argc == 0 )
           Wc( stdin );
       else
       do
       {
           FILE *Ifp = fopen( *argv, "r" );

           if( Ifp == NULL )
               fprintf( stderr, "Can not open %s\n", *argv );
           else
           {
               Wc( Ifp );
               fclose( Ifp );
               printf( " %s", *argv );
           }
           printf( "\n" );
           argv++;
       } while( --argc > 0 );

       return 0;
   }

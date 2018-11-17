/* ECP: FILEname=fig13_8.c */
   /* Simple du Program.  List Disk Usage.  Double */
   /* Counts Hard Links Or It Would Be The Same As du */

   #include <string.h>
   #include <errno.h>
   #include <stdio.h>
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <sys/param.h>
   #include <dirent.h>

   int aflag = 0;

   long int du( const char *Dir );

   int
   main( int argc, char **argv )
   {
       if( argc > 1 )
       {
           if( strcmp( argv[ 1 ], "-a" ) == 0 )
           {
               argv++; argc--; aflag = 1;
           }
       }
       if( argc == 1 )
           du( "." );
       else
       while( --argc )
           du( *++argv );

       return 0;
   }

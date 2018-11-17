/* ECP: FILEname=fig8_6.c */
   #include <stdio.h>
   #include <ctype.h>

   void
   PrintBool( int Val )
   {
       printf( "%6c", Val ? 'T' : 'F' );
   }

   main( void )
   {
       unsigned char Ch = 0;

       printf( "DEC OCT HEX CHAR ALPHA UPPER LOWER " );
       printf( "DIGIT ALNUM  HEX  SPACE PUNCT\n" );
       do
       {
           printf( "%3d %3o %3x ", Ch, Ch, Ch );

           if( isgraph( Ch ) )
               printf( "%4c", Ch );
           else if( isprint( Ch ) )
               printf( "  sp" );
           else switch( Ch )
           {
               case '\a': printf( "bell" ); break;
               case '\n': printf( "  nl" ); break;
               case '\0': printf( "null" ); break;
               case '\t': printf( " tab" ); break;
               default  : printf( "\\%03o", Ch ); break;
           }

           PrintBool( isalpha( Ch ) );
           PrintBool( isupper( Ch ) );
           PrintBool( islower( Ch ) );
           PrintBool( isdigit( Ch ) );
           PrintBool( isalnum( Ch ) );
           PrintBool( isxdigit( Ch ) );
           PrintBool( isspace( Ch ) );
           PrintBool( ispunct( Ch ) );

           printf( "\n" );
       } while( Ch++ != 127 );

       return 0;
   }

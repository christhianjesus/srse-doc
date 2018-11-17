/* ECP: FILEname=fig8_28.c */
   main ( void )
   {
       char Str[ 1000 ];

       for( ; ; )
       {
           if( scanf( "%[^ \t\n]", Str ) == 1 )
           {
               Justify( Str );      /* Get A Word And Justify */
               continue;
           }
           else                       /* Get White Space */
           if( scanf( "%[ \t]", Str ) == 1 ) 
               continue;
           else                   /* Must Be A Newline Or EOF */
           {
               if( getchar( ) == EOF ) /* Should Be A Newline */
                   break;
            /* If There's another newline, then new paragraph */
               if( scanf( "%[\n]", Str ) == 1 )
                   Justify( FLUSH );
           }

       }
       Justify( FLUSH );              /* Finish Off Last Line */
       return 0;
   }

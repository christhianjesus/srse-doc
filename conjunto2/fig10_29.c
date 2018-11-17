/* ECP: FILEname=fig10_29.c */
   #define MaxNodeLen 80
   typedef char NodeName[ MaxNodeLen + 1 ];
   const char *Term = "##";

   void
   ReadGraph( Vertex Graph[ ], HashTbl H )
   {
       NodeName Source, Dest;
       int RetVal;

       while( ( RetVal = GetTwoStrings( Source, Dest, MaxNodeLen ) )
                > 0 )
       {
           if( RetVal != 2 )
               printf( "Warning: skipped an input line\n" );
           else
           if( !strcmp( Source, Term ) && !strcmp( Dest, Term ) )
               return;
           else
               AddEdge( AddNode( Source, H, Graph ),
                        AddNode( Dest,   H, Graph ), Graph );
       }
       printf( "Input terminated early???\n" );
   }

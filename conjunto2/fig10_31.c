/* ECP: FILEname=fig10_31.c */
   void
   ProcessRequests( Vertex Graph[ ], HashTbl H )
   {
       NodeName Source, Dest;
       int SourceNum, DestNum;
       int RetVal;

       while( ( RetVal = GetTwoStrings( Source, Dest, MaxNodeLen ) )
               > 0 )
       {
           if( RetVal != 2 )
           {
               printf( "Format error: skipping this line\n" );
               continue;
           }
           SourceNum = Find( Source, H );
           DestNum = Find( Dest, H );
           if( SourceNum == -1 || DestNum == -1 )
               printf( "Illegal vertex specified\n" );
           else
           {
               EvaluateShort( SourceNum, Graph );
               PrintPath( DestNum, Graph );	
           }
       }
   }


   main( void )
   {
       HashTbl H = HaMakeEmpty( NULL );
       Vertex G[ MaxNodes + 1 ];

       ReadGraph( G, H );
       ProcessRequests( G, H );
       return 0;
   }

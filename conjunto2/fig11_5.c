/* ECP: FILEname=fig11_5.c */
   /* PrintPath Is A Driver; PrintPath1 Does The Real Work */

   static void
   PrintPath1( int DestNode, const Vertex Graph[ ] )
   {
       if( Graph[ DestNode ].PreviousNode != -1 )
       {
           PrintPath1( Graph[ DestNode ].PreviousNode, Graph );
           printf( " to " );
       }
       printf( "%s", Graph[ DestNode ].NodeName );
   }

   void
   PrintPath( int DestNode, const Vertex Graph[ ] )
   {
       if( Graph[ DestNode ].Distance == Infinity )
           printf( "%s unreachable", Graph[ DestNode ].NodeName );
       else
           PrintPath1( DestNode, Graph );
       printf( "\n" );
   }

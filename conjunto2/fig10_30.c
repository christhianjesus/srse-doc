/* ECP: FILEname=fig10_30.c */
   void
   PrintPath( int DestNode, const Vertex Graph[ ] )
   {
       Stack S = StMakeEmpty( NULL );
       int Intermediate;

       if( Graph[ DestNode ].Distance == Infinity )
           printf( "%s unreachable\n", Graph[ DestNode ].NodeName );
       else
       {
           Intermediate = Graph[ DestNode ].PreviousNode;
           while( Intermediate != -1 )
           {
               Push( Intermediate, S );
               Intermediate = Graph[ Intermediate ].PreviousNode;
           }
           while( !StIsEmpty( S ) )
           {
               printf( "%s to ", Graph[ Top( S ) ].NodeName );
               Pop( S );
           }
           printf( "%s\n", Graph[ DestNode ].NodeName );
       }
       StRecycle( S );
   }

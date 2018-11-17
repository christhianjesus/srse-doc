/* ECP: FILEname=fig10_32.c */
   void
   EvaluateShort( int StartNode, Vertex Graph[ ] )
   {
       int i, V, W;
       Queue Q = QuMakeEmpty( NULL );

       for( i = 0; Graph[ i ].NodeName != NULL; i++ )
       {
           Graph[ i ].Distance = Infinity;
           Graph[ i ].PreviousNode = -1;
       }

       Graph[ StartNode ].Distance = 0;
       Enqueue( StartNode, Q );
       while( !QuIsEmpty( Q ) )
       {
           Dequeue( &V, Q );
           for( i = 0; i < Graph[ V ].Adj.CurrentSize; i++ )
           {
               W = Graph[ V ].Adj.Array[ i ];
               if( Graph[ W ].Distance == Infinity )
               {
                   Graph[ W ].Distance = Graph[ V ].Distance + 1;
                   Graph[ W ].PreviousNode = V;
                   Enqueue( W, Q );
               }
           }
       }
       QuRecycle( Q );
   }

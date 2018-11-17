/* ECP: FILEname=fig10_17.c */
   int
   QuIsEmpty( const Queue Q )
   {
       QuInsistGood( Q );
       return Q->Size == 0;
   }


   static int
   Increment( int QParam, int QSize )
   {
       if( ++QParam == QSize )
           return 0;
       else
           return QParam;
   }


   void
   Dequeue( QuEtype *X, Queue Q )
   {
       if( QuIsEmpty( Q ) )
           printf( "Error: can not pop an empty queue\n" );
       else
       {
           *X = Q->Array[ Q->Front ];
           Q->Front = Increment( Q->Front, Q->MaxSize );
           Q->Size--;
       }
   }

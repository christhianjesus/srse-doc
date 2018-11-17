/* ECP: FILEname=fig10_18.c */
   /* After Queue Is Doubled, Arrangement May Be Bad. */
   /* This Routine Fixes It, And Avoids Excessive Moves */

   static void
   FixWraparound( Queue Q )
   {
       const int OrigSz = Q->MaxSize / 2;

       if( Q->Front < OrigSz / 2  )
       {
           memcpy( &Q->Array[ OrigSz ], &Q->Array[ 0 ],
                   Q->Front * sizeof( QuEtype ) );
           Q->Back += OrigSz;
       } 
       else
       {
           memcpy( &Q->Array[  OrigSz + Q->Front ],
                   &Q->Array[ Q->Front ],
                   ( OrigSz - Q->Front ) * sizeof( QuEtype ) );
           Q->Front += OrigSz;
       }
   }
               

   void
   Enqueue( QuEtype X, Queue Q )
   {
       QuInsistGood( Q );
       if( Q->Size == Q->MaxSize )
       {
           Q->MaxSize *= 2;
           Q->Array = realloc( Q->Array,
                   sizeof( QuEtype ) * Q->MaxSize );
           if( Q->Array == NULL )
           {
               printf( "Can not extend the queue\n" );
               exit( -1 );
           }
           if( Q->Front != 0 )
               FixWraparound( Q );
       }
       Q->Back = Increment( Q->Back, Q->MaxSize );
       Q->Array[ Q->Back ] = X;
       Q->Size++;
   }

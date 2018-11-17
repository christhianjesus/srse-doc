/* ECP: FILEname=fig10_8.c */
   int
   StIsEmpty( const Stack S )
   {
       StInsistGood( S );
       return S->TopOfStack == -1;
   }

   void
   Push( StEtype X, Stack S )
   {
       StInsistGood( S );
       if( ++S->TopOfStack == S->MaxSize )
       {
           S->MaxSize *= 2;
           S->Array = realloc( S->Array,
                            sizeof( StEtype ) * S->MaxSize );
           if( S->Array == NULL )
           {
               printf( "Can not extend the stack\n" );
               exit( -1 );
           }
       }
       S->Array[ S->TopOfStack ] = X;
   }

   void
   Pop( Stack S )
   {
       if( StIsEmpty( S ) )
           printf( "Error: can not pop an empty stack\n" );
       else
           S->TopOfStack--;
   }

   StEtype
   Top( const Stack S )
   {
       if( StIsEmpty( S ) )
           printf( "Error: can not top an empty stack\n" );
       else
           return S->Array[ S->TopOfStack ];
   }

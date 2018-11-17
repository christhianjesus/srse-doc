/* ECP: FILEname=fig10_23.c */
   HashTbl
   HaMakeEmpty( HashTbl H )
   {
       int i;
       const Cell InitCell = { NULL, NotFound };

       if( H != NULL )
       {
           for( i = 0; i < H->MaxSize; i++ )
           {
               free( H->Array[ i ].Word );
               H->Array[ i ].Num = NotFound;
           }
           H->Size = 0;
           return H;
       }

       free( H );	/* Safe Even if H == NULL */
       if( ( H = malloc( sizeof( struct HashStr ) ) ) == NULL )
           return NULL;
       H->Array = malloc( sizeof( Cell ) * HaInitSize );
       if( H->Array == NULL )
           return NULL;

       H->Size = 0;
       H->MaxSize = HaInitSize;
       for( i = 0; i < H->MaxSize; i++ )
           H->Array[ i ] = InitCell;

       return H;
   }


   void
   HaRecycle( HashTbl H )
   {
       int i;

       HaInsistGood( H );
       for( i = 0; i < H->MaxSize; i++ )
           free( H->Array[ i ].Word );
       free( H->Array );
       free( H );
   }

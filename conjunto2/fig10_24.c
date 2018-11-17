/* ECP: FILEname=fig10_24.c */
   static int
   FindPos( const char *Key, const HashTbl H )
   {
       unsigned int Pos;

       Pos = Hash( Key, H->MaxSize );
       while( H->Array[ Pos ].Num != NotFound &&
                   strcmp( H->Array[ Pos ].Word, Key ) )
           if( ++Pos == H->MaxSize )
               Pos = 0;

       return Pos;
   }


   int
   Find( const char *Key, const HashTbl H )
   {
       return H->Array[ FindPos( Key, H ) ].Num;
   }


   /* Insert A new Key Into H, Making A Duplicate */

   int
   Insert( const char *Key, HashTbl H )
   {
       unsigned int Pos;

       if( H->Size > H->MaxSize / 2 )
           Rehash( H );

       Pos = FindPos( Key, H );
       if( H->Array[ Pos ].Num == NotFound )
       {
           H->Array[ Pos ].Word = Strdup( Key );
           H->Array[ Pos ].Num = H->Size++;
       }
       return H->Array[ Pos ].Num;
   }

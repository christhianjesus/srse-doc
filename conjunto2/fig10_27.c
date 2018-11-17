/* ECP: FILEname=fig10_27.c */
   typedef int ArEtype;

   typedef struct
   {
       int CurrentSize;
       int MaxSize;
       ArEtype *Array;
   } VarArray;


   void
   Add( ArEtype X, VarArray *A )
   {
       if( A->CurrentSize == A->MaxSize )
       {
           if( A->CurrentSize == 0 )
           {
               A->MaxSize = 2;
               A->Array = malloc( sizeof( ArEtype ) * A->MaxSize );
           }
           else
           {
               A->MaxSize *= 2;
               A->Array = realloc( A->Array, sizeof( ArEtype ) *
                           A->MaxSize );
           }

           if( A->Array == NULL )
           {
               printf( "Out of space\n" );
               exit( -1 );
           }
       }
       A->Array[ A->CurrentSize++ ] = X;
   }

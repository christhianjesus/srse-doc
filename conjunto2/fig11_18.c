/* ECP: FILEname=fig11_18.c */
   void
   PrintInOrder( const Tree T )
   {
       if( T != NULL )
       {
           PrintInOrder( T->Left );
           if( T->Count )
               printf( "%s occurs %d times\n", T->Item, T->Count );
           PrintInOrder( T->Right );
       }
   }

/* ECP: FILEname=fig11_15.c */
   /* Return A Pointer To Node Storing X if X Is Found */

   TreeNode *
   Find( const Tree Root, const char *X )
   {
       int Cmp;

       if( Root == NULL )                   /* Not Found */
           return NULL;
       if( ( Cmp = strcmp( X, Root->Item ) ) < 0 )
           return Find( Root->Left, X );    /* X < Root->Item */
       if( Cmp > 0 )
           return Find( Root->Right, X );   /* X > Root->Item */
       return Root->Count ? Root : NULL;    /* X = Root->Item */
   }

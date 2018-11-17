/* ECP: FILEname=fig11_17.c */
   Tree
   Insert( Tree Root, const char *X )
   {
       int Cmp;

       if( Root == NULL )               /* Spot Found */
       {
           Root = malloc( sizeof( struct TreeNode ) );
           if( Root == NULL || ! ( Root->Item = Strdup( X ) ) )
               Error( "Out of space!!" );
           Root->Count = 1;
           Root->Left = Root->Right = NULL;
       }
       else                         /* X < Root->Item */
       if( ( Cmp = strcmp( X, Root->Item ) ) < 0 )
           Root->Left = Insert( Root->Left, X );
       else
       if( Cmp > 0 )                /* X > Root->Item */
           Root->Right = Insert( Root->Right, X );
       else
           Root->Count++;    /* X Was Previously Seen */

       return Root;
   }

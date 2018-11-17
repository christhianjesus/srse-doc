/* ECP: FILEname=fig11_16.c */
   void
   Remove( Tree Root, const char *X )
   {
       int Cmp;

       if( Root == NULL )                   /* Not Found */
           return;                          /* Do Nothing */
       else if( ( Cmp = strcmp( X, Root->Item ) ) < 0 )
           Remove( Root->Left, X );
       else if( Cmp > 0 )
           Remove( Root->Right, X );
       else if( Root->Count > 0 )
           Root->Count--;
   }

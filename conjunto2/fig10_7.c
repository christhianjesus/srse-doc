/* ECP: FILEname=fig10_7.c */
   void
   StRecycle( Stack S )
   {
       StInsistGood( S );
       free( S->Array );
       free( S );
   }

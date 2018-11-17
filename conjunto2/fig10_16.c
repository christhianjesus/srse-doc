/* ECP: FILEname=fig10_16.c */
   typedef SortedInts QuEtype;
   typedef struct QueueStr
   {
       QuEtype *Array;      /* The Array Of Elements */
       int Front;           /* Index Of Front Element */
       int Back;            /* Index Of Back Element */
       int Size;            /* Current Number Of Elements in Queue */
       int MaxSize;         /* Maximum Queue Qize */
   } *Queue;

   static const QuInitSize = 5;

   Queue
   QuMakeEmpty( Queue Q )
   {
       if( Q == NULL )
       {
           if( ! ( Q = malloc( sizeof( struct QueueStr ) ) ) )
               return NULL;
           Q->Array = malloc( sizeof( QuEtype ) * QuInitSize );
           if( Q->Array == NULL )
               return NULL;
           Q->MaxSize = QuInitSize;
       }
       Q->Size = 0;
       Q->Front = 0;
       Q->Back = -1;
       return Q;
   }

/* ECP: FILEname=fig10_6.c */
   #include <stdio.h>
   #include <stdlib.h>

   typedef Symbol StEtype;
   typedef struct StackStr
   {
       StEtype *Array;      /* The Array Of Elements */
       int TopOfStack;      /* Index Of Top Element */
       int MaxSize;         /* Maximum Stack Size */
   } *Stack;

   static const StInitSize = 5;

   Stack
   StMakeEmpty( Stack S )
   {
       if( S == NULL )
       {
           if( ! ( S = malloc( sizeof( struct StackStr ) ) ) )
               return NULL;
           S->Array = malloc( sizeof( StEtype ) * StInitSize );
           if( S->Array == NULL )
               return NULL;
           S->MaxSize = StInitSize;
       }
       S->TopOfStack = -1;
       return S;
   }

   static void
   StInsistGood( const Stack S )
   {
       if( S == NULL )
       {
           printf( "Stack routine received bad Stack\n" );
           exit( 1 );
       }
   }

/* ECP: FILEname=fig10_12.c */
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct
   {
       int *Array;
       int Size;
   } SortedInts;


   /* Merge Two Sorted Lists.  Since SortedInts Is */
   /* A Small Structure We Avoid Pointers */

   SortedInts
   MergeTwo( SortedInts struct1, SortedInts struct2 )
   {
       int *C;
       int *A = struct1.Array, *B = struct2.Array;
       int ACtr = 0, BCtr = 0, CCtr = 0;

       C = malloc( sizeof( int ) * ( struct1.Size + struct2.Size ) );
       if( C == NULL )
       {
           printf( "Can not allocate temporary array\n" );
           return struct1;
       }

       while( ACtr < struct1.Size && BCtr < struct2.Size )
           if( A[ ACtr ] <= B[ BCtr ] )
               C[ CCtr++ ] = A[ ACtr++ ];
           else
               C[ CCtr++ ] = B[ BCtr++ ];

       while( ACtr < struct1.Size )
           C[ CCtr++ ] = A[ ACtr++ ];
       while( BCtr < struct2.Size )
           C[ CCtr++ ] = B[ BCtr++ ];

       free( A ); free( B );
       struct1.Size += struct2.Size;
       struct1.Array = C;

       return struct1;
   }

/* ECP: FILEname=fig9_32.c */
   #include "shape.h"

   /* Comparison Function For qsort */

   int
   Compare( const void *Left, const void *Right )
   {
       ShapeType *LeftShape  = * ( ShapeType ** ) Left;
       ShapeType *RightShape = * ( ShapeType ** ) Right;

       if( LeftShape->TheShape < RightShape->TheShape )
           return -1;
       else
       if( LeftShape->TheShape > RightShape->TheShape )
           return 1;

           /* Same Shape */
       if( LeftShape->Area < RightShape->Area )
           return -1;
       else
       if( LeftShape->Area > RightShape->Area )
           return 1;
       else
           return 0;
   }

   /* Read Some Shapes, Sort Them By Area, And Write Them Out */

   #define MaxShapes 1000

   main( void )
   {
       ShapeType *Shapes[ MaxShapes ];
       int ItemsRead, i;

       for( ItemsRead = 0; ItemsRead < MaxShapes; ItemsRead++ )
           if( ( Shapes[ ItemsRead ] = ReadShape( ) ) == NULL )
               break;
           else
               AreaShape( Shapes[ ItemsRead ] );

       printf( "\n" );
       qsort( Shapes, ItemsRead, sizeof( ShapeType * ), Compare );
       for( i = 0; i < ItemsRead; i++ )
           WriteShape( Shapes[ i ] );

       return 0;
   }

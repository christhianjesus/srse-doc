/* ECP: FILEname=fig9_29.c */
   #include "circle.h"

   ShapeType *
   ReadCircle( void )
   {
       ShapeType *S;

       if ( S = malloc( sizeof ( ShapeType ) ) )
       {
           printf( "Enter radius: " );
           if( scanf( "%lf", &S->Dimension.Radius ) == 1 )
               return S;
       }

       return NULL;
   }

   void
   WriteCircle( const ShapeType * Shape )
   {
       printf( "radius %.2f", Shape->Dimension.Radius );
   }

   void
   AreaCircle( ShapeType * Shape )
   {
       Shape->Area = Pi * Shape->Dimension.Radius
                       * Shape->Dimension.Radius;
   }

/* ECP: FILEname=fig9_31.c */
   #include "table.h"

   #define StrConv1( Len ) ( "%" #Len "s" )
   #define StrConv( Len ) ( StrConv1( Len ) )

   ShapeType *
   ReadShape( void )
   {
       static char InputString[ MaxStringLen + 1 ];
       ShapeSwitch *Ptr;
       ShapeType *Shape;

       printf( "Enter shape type: " );
       if( scanf( StrConv( MaxStringLen ), InputString ) == 1 )
           for( Ptr = ShapeTable; Ptr->ShapeName; Ptr++ )
               if( strcmp( Ptr->ShapeName, InputString ) == 0 )
               {       /* Found The Type */
                   if( Shape = ( *Ptr->ReadShape )( ) )
                       Shape->TheShape = Ptr - ShapeTable;
                   return Shape;
               }

       return NULL;     /* No Match */
   }

   void
   WriteShape( const ShapeType * Shape )
   {
       printf( "Shape is a %s ",
                   ShapeTable[ Shape->TheShape ].ShapeName );
       ( *ShapeTable[ Shape->TheShape ].WriteShape )( Shape );
       printf( "; the area is %.2f\n", Shape->Area );
   }

   void
   AreaShape( ShapeType * Shape )
   {
       ( *ShapeTable[ Shape->TheShape ].Area )( Shape );
   }

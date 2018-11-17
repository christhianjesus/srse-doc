/* ECP: FILEname=fig8_39.c */
   void
   PrintShapeName( int i )
   {

       if( i < 0 || i >= DiffShapes )
           printf( "unrecognized shape" );
       else
           printf( "%s", ShapeNames[ i ] );
   }

/* ECP: FILEname=fig7_32.c */
   void
   PrintShapeName( int i )
   {
       if( i == Circle )
           printf( "circle" );
       else if( i == Rectangle )
           printf( "rectangle" );
       else if( i == Square )
           printf( "square" );
       else
           printf( "unrecognized shape" );
   }

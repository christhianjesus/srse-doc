/* ECP: FILEname=fig7_34.c */
   main( void )
   {
       int i, j, ShapesRead, Choice;
       double Areas[ MaxShapes ];
       double ShapeType[ MaxShapes ];

       for( i = 0; i < MaxShapes; i++ )
       {
           printf( "Enter %d for circle, ", Circle );
           printf( "Enter %d for rectangle, ", Rectangle );
           printf( "Enter %d for square: ", Square );

           if( scanf( "%d", &Choice ) != 1 )
               break;

           if( Choice == Circle )
               Areas[ i ] = ReadCircle( );
           else if( Choice == Square )
               Areas[ i ] = ReadSquare( );
           else if( Choice == Rectangle )
               Areas[ i ] = ReadRectangle( );
           else      /* Illegal Choice */
               break;

           ShapeType[ i ] = Choice;
       }

       OutputShapes( ShapeType, Areas, i );

       return 0;
   }

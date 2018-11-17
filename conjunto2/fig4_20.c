/* ECP: FILEname=fig4_20.c */
   main( void )
   {
       int Choice;
       double Area;

       while( 1 )
       {
           printf( "Enter %d for circle, ", Circle );
           printf( "Enter %d for rectangle, ", Rectangle );
           printf( "Enter %d for square: ", Square );

           if( scanf( "%d", &Choice ) != 1 )
               break;

           if( Choice == Circle )
               Area = ProcessCircle( );
           else if( Choice == Square )
               Area = ProcessSquare( );
           else if( Choice == Rectangle )
               Area = ProcessRectangle( );
           else      /* Illegal Choice */
               break;

           if( Area < 0 )
               break;
           printf( "the area is %.2f\n", Area );
       }
   }

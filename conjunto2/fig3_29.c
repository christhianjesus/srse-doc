/* ECP: FILEname=fig3_29.c */
   #include <stdio.h>

   #define Pi 3.1416
   #define Circle 1
   #define Rectangle 2
   #define Square 3

   main( void )
   {
       int Choice;
       double Dim1, Dim2;

       while( 1 )
       {
           printf( "Enter %d for circle, ", Circle );
           printf( "Enter %d for rectangle, ", Rectangle );
           printf( "Enter %d for square: ", Square );

           if( scanf( "%d", &Choice ) != 1 )
               break;

           if( Choice == Circle )
           {
               printf( "Enter radius: " );
               if( scanf( "%lf", &Dim1 ) != 1 )
                   break;
               printf( "Shape is circle radius %.2f; ", Dim1 );
               printf( "the area is %.2f\n", Dim1 * Dim1 * Pi );
           }
           else if( Choice == Square )
           {
               printf( "Enter side: " );
               if( scanf( "%lf", &Dim1 ) != 1 )
                   break;
               printf( "Shape is square side %.2f; ", Dim1 );
               printf( "the area is %.2f\n", Dim1 * Dim1 );
           }
           else if( Choice == Rectangle )
           {
               printf( "Enter length and width: " );
               if( scanf( "%lf %lf", &Dim1, &Dim2 ) != 2 )
                   break;
               printf( "Shape is rectangle " );
               printf( "length %.2f width %.2f; ", Dim1, Dim2 );
               printf( "the area is %.2f\n", Dim1 * Dim2 );
           }
           else      /* Illegal Choice */
               break;
       }
   }

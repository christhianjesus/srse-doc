/* ECP: FILEname=fig4_19.c */
   #include <stdio.h>

   #define Pi 3.1416
   #define Circle 1
   #define Rectangle 2
   #define Square 3

   #define NoArea ( -1.0 )

   double
   ProcessCircle( void )
   {
       double Dim1;

       printf( "Enter radius: " );
       if( scanf( "%lf", &Dim1 ) != 1 )
           return NoArea;
       printf( "Shape is circle radius %.2f; ", Dim1 );
       return Dim1 * Dim1 * Pi;
   }

/* ECP: FILEname=fig8_38.c */
   #include <stdio.h>

   #define Pi 3.1416
   #define NoArea ( -1.0 )

   enum { Circle, Rectangle, Square };

   /* Names Must Be in The Same Order As enum List */
   static char *ShapeNames[ ] =
   {
       "circle",
       "rectangle",
       "square",
   };

   #define DiffShapes ( sizeof ( ShapeNames ) / sizeof( char * ) )

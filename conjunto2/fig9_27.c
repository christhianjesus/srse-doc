/* ECP: FILEname=fig9_27.c */
   #ifndef _Shape
   #define _Shape

   #include <stdio.h>
   #include <stdlib.h>

   #define Pi 3.1416
   #define MaxStringLen 80

   typedef struct
   {
       int TheShape;
       double Area;

       union      /* Stores The Dimensions Of The Object */
       {
           double Radius;       /* Circle */
           double Side;         /* Square */
           struct               /* Rectangle */
           {
               double Length;
               double Width;
           } Rect;
       } Dimension;
   } ShapeType;

   void WriteShape( const ShapeType * Shape );
   void AreaShape( ShapeType * Shape );
   ShapeType * ReadShape( void );

   #endif

/* ECP: FILEname=fig9_30.c */
   /* To Add A New Shape                        */
   /* 1. Create Appropriate Header And Source   */
   /*        Read, Write, And Area Functions;   */
   /* 2. Update #include Statements Below;      */
   /* 3. Adjust typedef Shape                   */
  

   #include "circle.h"
   #include "square.h"
   #include "rectangle.h"


   typedef struct
   {
       char *ShapeName;
       ShapeType * ( *ReadShape )( void );
       void ( *WriteShape )( const ShapeType *Shape );
       void ( *Area )( ShapeType *Shape );
   } ShapeSwitch;


   static ShapeSwitch ShapeTable[ ] =
   {
       { "circle", ReadCircle, WriteCircle, AreaCircle },
       { "rectangle", ReadRectangle, WriteRectangle, AreaRectangle },
       { "square", ReadSquare, WriteSquare, AreaSquare },
       { NULL, NULL, NULL, NULL }
   };

   #include <string.h>

/* ECP: FILEname=fig7_33.c */
   #define MaxShapes 1000

   void
   OutputShapes( const double ShapeType[ ],
                      const double Areas[ ], double HowMany )
   {
       int i, j;

       printf( "\n" );
       for( i = Circle; i <= Square; i++ )
       {
           for( j = 0; j < HowMany; j++ )
               if( ShapeType[ j ] == i )
               {
                   PrintShapeName( i );
                   printf( " area %.2f\n", Areas[ j ] );
               }
       }
   }

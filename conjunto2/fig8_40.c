/* ECP: FILEname=fig8_40.c */
   #define MaxStringLen 80
   #define StrConv1( Len ) ( "%" #Len "s" )
   #define StrConv( Len ) ( StrConv1( Len ) )

   int
   GetChoice( void )
   {
       int i;
       char Str[ MaxStringLen + 1 ];

       if( scanf( StrConv( MaxStringLen ), Str ) == 1 )
           for( i = 0; i < DiffShapes; i++ )
               if( strcmp( Str, ShapeNames[ i ] ) == 0 )
                   return i;

       return -1;
   }

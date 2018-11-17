/* ECP: FILEname=fig5_7.c */
   #define PrintDebug( Expr, Type )                            \
       printf( __FILE__ "[%d](" #Expr "): %" Type##Conv "\n",  \
                   __LINE__, ( Expr ) )
   #define intConv         "d"
   #define doubleConv      "f"

   main( void )
   {
       int X = 5, Y = 7;
       double A = 5.0, B = 7.0;

       PrintDebug( X + Y, int  );        /* Really Line 12 */
       PrintDebug( A + B, double  );     /* Really Line 13 */
       return 0;
   }

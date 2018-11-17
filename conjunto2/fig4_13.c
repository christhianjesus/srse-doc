/* ECP: FILEname=fig4_13.c */
   #include "root.h"

   int
   DifferentSign( double F( double ), double Pt1, double Pt2 )
   {
       return  ( F( Pt1 ) < 0 ) != ( F( Pt2 ) < 0 );
   }

   double
   Solve( double F( double ), double Low, double High )
   {
       double Mid = ( Low + High ) / 2.0;
       double SmallInterval = ( High - Low ) * Epsilon;

       if( ! F( Low ) )
           return Low;
       else
       if( ! F( High ) )
           return High;
       else
       if( ! DifferentSign( F, Low, High ) )
       {
           printf( "Suggested points have same sign!\n" );
           return SolveError;
       }

       while( F( Mid ) && ( High - Low ) > SmallInterval )
       {
           if( DifferentSign( F, Low, Mid ) )
               High = Mid;
           else
               Low = Mid;

           Mid = ( Low + High ) / 2.0;
       }

       return Mid;
   }

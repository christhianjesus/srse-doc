/* ECP: FILEname=fig9_21.c */
   #include <stdio.h>
   #include "complex.h"

   struct Complex
   {
       double Real;
       double Imag;
   };

   void
   PrintComplex( const Complex A )
   {
       if( A != NULL )
           printf( "%f+%f", A->Real, A->Imag );
       else
           printf( "Uninitialized complex number detected\n" );
   }

   /* InitComplex And AddComplex Are Similar */

/* ECP: FILEname=fig1_11.c */
   typedef struct Complex Complex;

   void AddComplex( const Complex *X, const Complex *Y, Complex *Sum )
   {
       Sum->Real = X->Real + Y->Real;
       Sum->Imag = X->Imag + Y->Imag;
   }

/* ECP: FILEname=fig9_20.c */
       /* Header File With Incomplete struct Declaration  */
   typedef struct Complex *Complex;

   Complex InitComplex( double Real, double Imag );
   void AddComplex( const Complex A, const Complex B, Complex Sum );
   void PrintComplex( const Complex A );

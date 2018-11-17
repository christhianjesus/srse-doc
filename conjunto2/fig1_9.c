/* ECP: FILEname=fig1_9.c */
   struct Complex
   AddComplex( struct Complex X, struct Complex Y )
   {
       struct Complex Sum;

       Sum.Real = X.Real + Y.Real;
       Sum.Imag = X.Imag + Y.Imag;

       return Sum;
   }

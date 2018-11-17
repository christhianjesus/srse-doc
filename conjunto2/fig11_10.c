/* ECP: FILEname=fig11_10.c */
   /* Given A And B, Assume Gcd( A, B ) = 1 */
   /* Find X And Y Such That A X + B Y = 1 */

   void
   FullGcd( const HugeInt A, const HugeInt B,
                                         HugeInt *X, HugeInt *Y )
   {
       HugeInt X1, Y1;

       if( B == 0 )
       {
           *X = 1;     /* If A != 1, There Is No Inverse */
           *Y = 0;     /* We Omit this Check */
       }
       else
       {
           FullGcd( B, A % B, &X1, &Y1 );
           *X = Y1;
           *Y = X1 - ( A / B ) * Y1;
       }
   }

   /* Solve A X == 1 ( Mod N ) */
   /* Assume That Gcd( A, N ) = 1 */

   HugeInt
   Inverse( const HugeInt A, const HugeInt N )
   {
       HugeInt X, Y;

       FullGcd( A, N, &X, &Y );
       return X > 0 ? X : X + N;
   }

/* ECP: FILEname=fig9_19.c */
   int
   Comp( const void *Lhs, const void *Rhs )
   {
       int Leftkey  =  ( ( Block * ) Lhs )->Key;
       int Rightkey =  ( ( Block * ) Rhs )->Key;

       return Leftkey < Rightkey ? -1 : Leftkey != Rightkey;
   }


       /* ... */
       Shellsort( P, 2000, sizeof( Block ), Comp );
       /* ... */

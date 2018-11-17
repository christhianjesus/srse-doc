/* ECP: FILEname=fig8_24.c */
   int
   Strcmp( const char *Lhs, const char *Rhs )
   {
       for( ; *Lhs == *Rhs && *Lhs != '\0';  Lhs++, Rhs++ )
           ;

       return *Lhs - *Rhs;
   }

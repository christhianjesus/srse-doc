/* ECP: FILEname=fig8_22.c */
   char *
   Strcpy( char * const Lhs, const char *Rhs )
   {
       char *Lhp = Lhs;

       if( Lhs != Rhs )
           while( ( *Lhp++ = *Rhs++ ) != '\0' )
               ;

       return Lhs;
   }


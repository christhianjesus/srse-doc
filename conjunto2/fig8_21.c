/* ECP: FILEname=fig8_21.c */
   /* Incorrect Routine That Will Work On Almost All Machines */

   unsigned int
   WrongStrlen( const char * const Str )
   {
       const char *Sp = Str - 1;    /* Illegal Pointer */

       while( *++Sp )
           ;

       return Sp - Str;
   }

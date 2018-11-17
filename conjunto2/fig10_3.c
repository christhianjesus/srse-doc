/* ECP: FILEname=fig10_3.c */
   int
   CheckMatch( const Symbol *OpSym, const Symbol *ClSym )
   {
       if( OpSym->Sym == '(' && ClSym->Sym == ')' 
         ||  OpSym->Sym == '[' && ClSym->Sym == ']' 
         ||  OpSym->Sym == '{' && ClSym->Sym == '}' ) 
           return 0;

       printf( "Found %c on line %d;"
               " does not match %c at line %d\n",
           ClSym->Sym, ClSym->Line, OpSym->Sym, OpSym->Line );
       return 1;
   }

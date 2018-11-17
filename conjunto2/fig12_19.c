/* ECP: FILEname=fig12_19.c */
   void
   SetOptions( const char *Option )
   {
       Lflag = Wflag = Cflag = 0;

       while( *++Option )
           switch( *Option )
           {
             case 'l':
               Lflag++; break;
             case 'w':
               Wflag++; break;
             case 'c':
               Cflag++; break;
             default:
               fprintf( stderr, "Illegal option %c\n", *Option );
           }
   }

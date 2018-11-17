/* ECP: FILEname=fig8_19.c */
   int
   IsPrefix( const char Little[ ], const char Big[ ] )
   {
       return !strncmp( Little, Big, strlen( Little ) );
   }

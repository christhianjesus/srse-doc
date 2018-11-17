/* ECP: FILEname=fig8_33.c */
   #include <stdio.h>

   /* The Error Codes. */
   /* Automatically Assigned Starting From 0 */

   enum
   {
       ErNoMem,
       ErOutOfRange,
       ErFormat,
       ErEOF,
       ErError
   };

   /* The Corresponding Error Messages */

   const char *ErrorMessages[ ] =
   {
       "Out of memory",
       "Input value out of range",
       "Format error",
       "Premature end of input",
       "Bad argument to PrintError"
   };

   static const NumErr =
                  sizeof( ErrorMessages ) / sizeof( char * );

   void
   PrintError( int ErrorNum )
   {
       if( ErrorNum < 0 || ErrorNum >= NumErr )
           ErrorNum = ErError;
       printf( "Error: %s.\n", ErrorMessages[ ErrorNum ] );
   }

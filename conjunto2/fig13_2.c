/* ECP: FILEname=fig13_2.c */
   #include <errno.h>
   #include <stdio.h>
   #include <string.h>
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <time.h>


   /* Return Number Of Seconds Terminal Has Been Idle */
   /* -1 Is Returned On Error */

   #define MaxLen 32
   #define DevLen  6           /* strlen( "/dev/" ) + 1 */

   int
   Idle( const char *Terminal )
   {
       struct stat StatBuf;
       char TerminalName[ MaxLen ] = "/dev/";
       time_t Now;

       strncat( TerminalName, Terminal, MaxLen - DevLen );
       if( lstat( TerminalName, &StatBuf ) < 0 )
           perror( TerminalName );
       else
       if( !S_ISCHR( StatBuf.st_mode ) )
           fprintf( stderr, "%s: Not a terminal\n", TerminalName );
       else
       {	
           time( &Now );
           return ( int ) difftime( StatBuf.st_atime, Now );
       }
       return -1;              /* Error Indicator */
   }

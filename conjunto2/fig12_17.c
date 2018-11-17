/* ECP: FILEname=fig12_17.c */
   #include <stdio.h>
   #include <utmp.h>
   #include <time.h>

   static const char *Wtmp = "/var/adm/wtmp";
   static const UtmpSize = sizeof( struct utmp );

   #define NameLen       8
   #define LineLen       8

   int
   Logins( const char *SearchName )
   {
       int HowMany = 0;
       struct utmp UtEntry;
       FILE *Ufp;

       if( ( Ufp = fopen( Wtmp, "rb" ) ) == NULL )
       {
           fprintf( stderr, "Can not open %s\n", Wtmp );
           return -1;
       }

       fseek( Ufp, -UtmpSize, SEEK_END );
       while( fread( &UtEntry, UtmpSize, 1, Ufp ) == 1 )
       {
           char Name[ NameLen + 1 ] = "", Line[ LineLen + 1 ] = "";

           if( !strncmp( UtEntry.ut_name, SearchName, NameLen ) )
           {
               strncpy( Name, UtEntry.ut_name, NameLen );
               strncpy( Line, UtEntry.ut_line, LineLen );
               printf( "%-*s %-*s %26s", NameLen, Name, LineLen,
                           Line, ctime( &UtEntry.ut_time ) );
               HowMany++;
           }
               /* Back Up Past Current Structure */
           if( fseek( Ufp, -UtmpSize * 2, SEEK_CUR ) == -1 )
               break;
       }

       fclose( Ufp );
       return HowMany;
   }

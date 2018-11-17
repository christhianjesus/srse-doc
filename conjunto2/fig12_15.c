/* ECP: FILEname=fig12_15.c */
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

       while( fread( &UtEntry, UtmpSize, 1, Ufp ) == 1 )
       {
           char Name[ NameLen + 1 ] = "", Line[ LineLen + 1 ] = "";

           if( strncmp( UtEntry.ut_name, SearchName, NameLen ) == 0 )
           {
               strncpy( Name, UtEntry.ut_name, NameLen );
               strncpy( Line, UtEntry.ut_line, LineLen );
               printf( "%-*s %-*s %26s", NameLen, Name, LineLen,
                           Line, ctime( &UtEntry.ut_time ) );
               HowMany++;
           }
       }

       fclose( Ufp );
       return HowMany;
   }

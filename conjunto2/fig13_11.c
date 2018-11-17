/* ECP: FILEname=fig13_11.c */
   /* Copy From SrcFile To DestFile */
   /* Return Number Of Characters Copied, -1 For Errors */

   #include <stdio.h>
   #include <sys/stat.h>
   #include <fcntl.h>
   #include <sys/unistd.h>
   #include <string.h>
   #include <errno.h>

   #define BufSize 8192

   long int
   Copy( const char *DestFile, const char *SrcFile )
   {
       long int CharsRead, CharsCounted = 0;
       int SrcDesc, DestDesc;
       char Buffer[ BufSize ];
       const CreateFlag =  O_WRONLY | O_CREAT | O_TRUNC;
       const Mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

       if( strcmp( SrcFile, DestFile ) == 0 )
       {
           fprintf( stderr, "Can not copy to self\n" );
           return -1L;
       }

       if( ( SrcDesc = open( SrcFile, O_RDONLY ) ) < 0 )
       {
           perror( SrcFile );
           return -1L;
       }
       if( ( DestDesc = open( DestFile, CreateFlag, Mode ) ) < 0 )
       {
           perror( DestFile );
           return -1L;
       }

       while( ( CharsRead = read( SrcDesc, Buffer, BufSize ) ) > 0 )
           if( write( DestDesc, Buffer, CharsRead ) < CharsRead )
           {
               perror( DestFile );
               break;
           }
           else
               CharsCounted += CharsRead;

       close( SrcDesc ); close( DestDesc );
       return CharsCounted;
   }

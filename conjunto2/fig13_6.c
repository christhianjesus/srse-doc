/* ECP: FILEname=fig13_6.c */
   #include <stdio.h>
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <sys/param.h>       /* For MAXPATHLEN */
   #include <dirent.h>
   #include <errno.h>

   struct stat Slash;      /* Stores Info For "/" */


   int
   main( void )
   {
       if( lstat( "/", &Slash ) < 0 )
           perror( "/" );
       else
           Pwd( "." );

       return 0;
   }


   int
   IsMatch( const struct stat *F1, const struct stat *F2 )
   {
       return F1->st_ino == F2->st_ino && F1->st_dev == F2->st_dev;
   }


   void
   Pwd( const char *DirName )
   {
       struct stat Dot;

       if( lstat( DirName, &Dot ) < 0 )
           perror( DirName );
       else
       if( IsMatch( &Dot, &Slash ) )
           printf( "/" );
       else
           Pwd1( ".", &Dot );
       printf( "\n" );
   }

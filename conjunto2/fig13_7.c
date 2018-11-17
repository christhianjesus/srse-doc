/* ECP: FILEname=fig13_7.c */
   void
   Pwd1( const char *DirName, const struct stat *Dot )
   {
       struct stat DotDot, Buf;
       char FileName[ MAXPATHLEN ], Parent[ MAXPATHLEN ];
       DIR *ParentDir;
       struct dirent *Slot;

       if( IsMatch( Dot, &Slash ) )           /* Base Case */
           return;                      /* We Are At Slash */

       /* First, Recursively Print Up To The Parent */
       sprintf( Parent, "%s/..", DirName );
       if( lstat( Parent, &DotDot ) < 0 )
       {
           perror( Parent );
           return;
       }
       Pwd1( Parent, &DotDot );

       /* Now, Print Last Component Of The Pathname */
       if( ( ParentDir = opendir( Parent ) ) == NULL )
       {
           perror( Parent );
           return;
       }

       while( ( Slot = readdir( ParentDir ) ) != NULL )
       {
           sprintf( FileName, "%s/%s", Parent, Slot->d_name );
           if( !lstat( FileName, &Buf ) && IsMatch( &Buf, Dot ) )
           {
               printf( "/%s", Slot->d_name );
               closedir( ParentDir );
               return;
           }
       }
       printf( "/???" );      /* This Should Never Occur */
   }

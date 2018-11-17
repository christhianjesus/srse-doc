/* ECP: FILEname=fig13_9.c */
   long
   du( const char *DirName )
   {
       DIR *DirPtr;           /* Pointer To Directory Stream */
       struct dirent *Slot;             /* Slot in Directory */
       struct stat StatBuf;
       long Blocks = 0L;
       char FileName[ MAXPATHLEN ];

       if( ( DirPtr = opendir( DirName ) ) == NULL )
       {
           perror( DirName );
           return 0L;
       }
       while( ( Slot = readdir( DirPtr ) ) != NULL )
       {
           if( strcmp( Slot->d_name, ".." ) == 0 )
               continue;		/* Skip Parent */

           sprintf( FileName, "%s/%s", DirName, Slot->d_name );
           if( lstat( FileName, &StatBuf ) != 0 )
           {
               perror( FileName );
               continue;
           }
           if ( S_ISDIR( StatBuf.st_mode ) )     /* Directories */
           {
               if( strcmp( Slot->d_name, "." ) == 0 )
                   Blocks += StatBuf.st_blocks;
               else
                   Blocks += du( FileName );
               continue;
           }
           /* Print The Answer in 1k Blocks, Not 512 Byte Blocks */
           if( aflag )
               printf( "%-8ld%s\n", StatBuf.st_blocks/2, FileName );
           Blocks += StatBuf.st_blocks;
       }
       if( Blocks )
           printf( "%-8ld%s\n", Blocks/2, DirName );
       closedir( DirPtr );
       return Blocks;
   }

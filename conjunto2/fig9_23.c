/* ECP: FILEname=fig9_23.c */
   #include <stdio.h>

   void Help( void );
   void Quit( void );
   void Reset( void );
   void Undo( void );

   typedef struct
   {
       char *Command;
       void ( *Func )( void );
   } CommStruct;

   static const CommStruct TheCommands[ ] =
   {
       "exit", Quit,
       "help", Help,
       "quit", Quit,
       "reset", Reset,
       "undo", Undo,
       NULL, NULL             /* Place Last; No Match */
   };

   void
   DoCommand( const char *Comm )
   {
       const CommStruct *Ptr;

       for( Ptr = TheCommands; Ptr->Command != NULL; Ptr++ )
           if( strcmp( Comm, Ptr->Command ) == 0 )
           {
               ( *Ptr->Func )( );
               return;
           }

       printf( "Error: unrecognized command\n" );
   }

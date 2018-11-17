/* ECP: FILEname=fig13_24.c */
   #include <stdio.h>
   #include <string.h>
   #include <sys/types.h>
   #include <sys/stat.h>
   #include <fcntl.h>
   #include <sys/wait.h>
   #include <unistd.h>
   #include <errno.h>
   #include <signal.h>

   /* Simple Shell */

   /* A Simple Command Is An Array Of Up To MaxArgc+1 Strings */
   /* The Last String Is NULL */
   /* This Can Be Used Directly For execvp */
   /* Very Limited Error Checking To Keep Code Short */

   #define MaxArgc 10
   #define MaxPipes 10
   #define FileNameLen MaxLineLen
   #define MaxLineLen 256

   typedef char *SimpleCommand[ MaxArgc + 1  ];

   typedef struct
   {
       char InFile[ FileNameLen ];
       char OutFile[ FileNameLen ];
       int NumPipes;
       SimpleCommand Commands[ MaxPipes ];
       int Background;
   } FullCommand;

   enum { Eoln, Error, From, To, Pipe, Word, Amper };

   /* Read A Line, return NULL On EOF */
   #define GetLine( S ) ( fgets( S, MaxLineLen, stdin ) )

   /* Return Pointer Indicating Where To Begin Next Search */
   /* Str Will Be Filled if *Token Is Word, From, Or To */
   char *GetToken( char *TheLine, char *Str, int *Token );

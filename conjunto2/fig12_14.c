/* ECP: FILEname=fig12_14.c */
   struct utmp {
       char ut_line[ 8 ];  /* Tty Name */
       char ut_name[ 8 ];  /* User Id */
       char ut_host[ 16 ]; /* Host Name, if Remote */
       long ut_time;       /* Time On */
   };

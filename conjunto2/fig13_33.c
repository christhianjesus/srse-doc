/* ECP: FILEname=fig13_33.c */
   #include <sys/time.h>
   #include <sys/resource.h>

   #define Milli( X ) ( ( X.tv_sec * 1000 + X.tv_usec / 1000 ) )

   long int
   MilliElapsed( void )
   {
       struct Rusage Buf;
       static struct Timeval LastUtime;
       long int ElapsedTime;
       
       getrusage( RUSAGE_SELF, &Buf );
       ElapsedTime = Milli( Buf.ru_utime ) - Milli( LastUtime );
       LastUtime = Buf.ru_utime;

       return ElapsedTime;
   }

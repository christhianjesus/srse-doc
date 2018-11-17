/* ECP: FILEname=fig9_5.c */
   /* Find All Friday The 13th Birthdays */
   /* For Person Born On Nov. 13, 1973 */

   #include <time.h>
   #include <stdio.h>

   main( void )
   {
       const Friday = 6 - 1;            /* Sunday Is 0, Etc... */
       struct tm TheTime = { 0 };       /* Set All Fields To 0 */
       int Year;

       TheTime.tm_mon = 11 - 1;         /* January Is 0, Etc... */
       TheTime.tm_mday = 13;            /* 13th Day Of The Month */

       for( Year = 1973; Year < 2073; Year++ )
       {
           TheTime.tm_year = Year - 1900; /* 1900 Is 0, Etc... */
           if( mktime( &TheTime ) == -1 )
           {
               printf( "mktime failed in %d\n", Year );
               break;
           }
           if( TheTime.tm_wday == Friday )
               printf( "%s", asctime( &TheTime ) );
       }

       return 0;
   }

/* ECP: FILEname=fig9_9.c */
   /*Fill In The tm_yday Field, As In mktime */

   int
   MkYear( struct tm *TmStruct )
   {
       static const int MonthDays[ ] =
           { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
       static const int LeapMonthDays[ ] =
           { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
       const int *MyMonthDays;
       int i;

       if( TmStruct != NULL )
       {
                 int Days  = ( *TmStruct ).tm_mday;
           const int Month = ( *TmStruct ).tm_mon;
           const int Year  = ( *TmStruct ).tm_year + 1900;

           MyMonthDays = IsLeap( Year ) ? LeapMonthDays : MonthDays;
           if( Month < 0 || Month > 11 || Days < 0 ||
                       Days > MyMonthDays[ Month ] )
               return -1; 

           for( i = 0; i < Month; i++ )
               Days += MyMonthDays[ i ];

           ( *TmStruct ).tm_yday = Days;
           return 0;
       }
       return -1;
   }

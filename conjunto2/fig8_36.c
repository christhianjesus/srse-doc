/* ECP: FILEname=fig8_36.c */
   const char *States[ ] =
   {
       "alabama", "alaska", "arizona", "arkansas", "california",
       "colorado", "connecticut", "delaware", "florida", "georgia",
       "hawaii", "idaho", "illinois", "indiana", "iowa",
       "kansas", "kentucky", "louisiana", "maine", "maryland",
       "massachusetts", "michigan", "minnesota", "mississippi",
       "missouri", "montana", "nebraska", "nevada", "newhampshire",
       "newjersey", "newmexico", "newyork", "northcarolina",
       "northdakota", "ohio", "oklahoma", "oregon", "pennsylvania",
       "rhodeisland", "southcarolina", "southdakota", "tennessee",
       "texas", "utah", "vermont", "virginia", "washington",
       "westvirginia", "wisconsin", "wyoming"
   };

   static const NumStates = sizeof States / sizeof( char * );


   /* Return Position Of A String In An Array Of Strings. */
   /* Array Must Be Sorted; return -1 if Not Found. */

   int
   BinarySearch( const char *Str, const char *StrArray[ ],
                   const unsigned int ArrayLen )
   {
       int Low = 0, High = ArrayLen - 1;
       int Mid;
       int Cmp;

       while( Low <= High )
       {
           Mid = ( Low + High ) / 2;
           Cmp = strcmp( Str, StrArray[ Mid ] );
           if( Cmp < 0 )
               High = Mid - 1;
           else if( Cmp > 0 )
               Low = Mid + 1;
           else
               return Mid;
       }

       return -1;		/* Item Not Found */
   }

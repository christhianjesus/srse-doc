/* ECP: FILEname=fig9_8.c */
   int
   IsLeap( int Year )
   {
       if( Year % 4 )     /* Not Divisible By 4 */
           return 0;
       if( Year % 100 )   /* Divisible By 4, But Not 100 */
           return 1;
       if( Year % 400 )   /* Divisible By 100, But Not 400 */
           return 0;
       return 1;          /* Divisible By 400 */
   }

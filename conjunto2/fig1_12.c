/* ECP: FILEname=fig1_12.c */

   #include <stdio.h>

   /* Read Items, Compute Their Average */

   main( void )
   {
       FILE *Fp;                    /* File Pointer */
       char FileName[ 256 ];        /* File Name */
       int ItemsRead = 0;
       double ThisItem, Sum = 0.0;

       printf( "Enter input file: " );
       if( scanf( "%s", FileName ) != 1 ||
               ( Fp = fopen( FileName, "r" ) ) == NULL )
       {
           fprintf( stderr, "Cannot open input file\n" );
           return 1;
       }

       while( fscanf( Fp, "%lf", &ThisItem ) == 1 )
       {
           ItemsRead++;
           Sum += ThisItem;
       }

       printf( "The average of %d items was %f\n",
               ItemsRead, Sum / ItemsRead );

       return 0;
   }

/* ECP: FILEname=fig2_13.c */
       /* Faculty Profile Fields */
   #define Sex          0x0001   /* On If Female */
   #define Minority     0x0002   /* On If In A Minority Group */
   #define Veteran      0x0004   /* On If Veteran */
   #define Disabled     0x0008   /* On If Disabled */
   #define UScitizen    0x0010   /* On If Citizen */
   #define Doctorate    0x0020   /* On If Holds A Doctorate */
   #define Tenured      0x0040   /* On If Tenured */
   #define TwelveMonth  0x0080   /* On If On 12 Month Contract */
   #define Visitor      0x0100   /* On If Not Permanent Faculty */
   #define Campus       0x0200   /* On If Work Is At Main Campus */

   #define Rank         0x0c00   /* Two Bits To Represent Rank */
   #define Assistant    0x0400   /* Assistant Professor */
   #define Associate    0x0800   /* Associate Professor */
   #define Full         0x0c00   /* Full Professor */

   #define College      0xf000   /* Represents 16 Colleges */
       ...
   #define ArtsScience  0x3000   /* Arts And Science = College #3 */
       ...


       /* Initialize Appropriate Fields */
       Tim = ArtsScience | Associate | Campus | Tenured |
                       Doctorate | UScitizen;

       /* Promote Tim To Full Professor */
       Tim &= ~Rank;       /* Turn All Rank Fields Off */
       Tim |= Full;        /* Turn Rank Fields On */

       /* Find Bob's Tenure And College */
       BobsTenured = Bob & Tenured;   /* Zero If Untenured */
       BobsCollege = ( Bob >> 12 ) & 0x000f;

/* ECP: FILEname=fig11_14.c */
   typedef struct TreeNode *Tree;

   typedef struct TreeNode
   {
       char *Item;          /* The Item */
       int Count;           /* Frequency Of Occurrence */
       Tree Left;           /* Left Tree, Recursively Defined */
       Tree Right;          /* Right Tree, Recursively Defined */
   } TreeNode;

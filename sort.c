/* EasyCASE V6.8 06.01.2017 16:48:02 */
/* EasyCASE O
If=vertical
LevelNumbers=no
LineNumbers=yes
Colors=16777215,0,12582912,12632256,0,0,0,16711680,8388736,0,33023,32768,0,0,0,0,0,32768,255,255,65280,255,255,16711935
ScreenFont=Courier New,Regular,100,4,-13,0,400,0,0,0,0,0,0,3,2,1,49,96,96
PrinterFont=Courier,,100,65530,-83,0,400,0,0,0,0,0,0,3,2,1,49,600,600
LastLevelId=308 */
/* EasyCASE ( 1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
/* EasyCASE - */
#include "cdefL.h"
/* EasyCASE ( 18
   Definitions */
#define SORT__nListElementSize (/* 1000000ul ) */ 100000ul)
/* EasyCASE - */
/* large array that holds the unsorted read data */
static uint8 SORT__au8ReadDataArray[SORT__nListElementSize];
/* EasyCASE - */
#ifdef MY_ALGO
/* EasyCASE - */
/* QuickSort prototype */
static bool SORT_QuickSort(uint8 * u8Array, uint32 u32Size);
/* EasyCASE - */
/* BubbleSort prototype */
static bool SORT_BubbleSort(uint8 * u8Array, uint32 u32Size);
/* EasyCASE - */
#endif /* MY_ALGO */
/* EasyCASE ( 19
   time related */
#define _POSIX_C_SOURCE 200809L
/* EasyCASE ) */
/* EasyCASE ) */
#ifdef MY_ALGO
/* EasyCASE - */
#if 0 /* QuickSort */
/* EasyCASE ( 16
   SORT_QuickSort - split aray */
/* EasyCASE F */
static bool SORT_QuickSort(uint8 * u8Array, uint32 u32Size)
   {
   /* Insert Algo below! */
   /* EasyCASE - */
   /* QUICK SORT:
    * Quicksort, is a divide-and-conquer recursive algorithm. 
   */
   /* --------------------------------------------------------
   function quicksort(array)
       less, equal, greater := three empty arrays
       if length(array) > 1  
           pivot := select any element of array
           for each x in array
               if x < pivot then add x to less
               if x = pivot then add x to equal
               if x > pivot then add x to greater
           quicksort(less)
           quicksort(greater)
           array := concatenate(less, equal, greater)
    -------------------------------------------------------- */
    
    /* NOTE: This is very time consuming algorithm (400ms @ 100K numbers input), 
     * as well as high RAM consumer (due to double the read array into RAM) */
   /* EasyCASE - */
   /* Definitions */
   uint8 au8Less[u32Size];
   uint8 au8Greater[u32Size];
   uint32 u32Counter;
   uint32 u32LocalCounter1 = 0, u32LocalCounter3 = 0;
   /* EasyCASE - */
   uint8 u8Pivot = 0;
   /* EasyCASE - */
   #ifdef DEBUG1
   uint32 u32PrintCounter = 0;
   #endif
   if (u32Size > 2)
      {
      u8Pivot = u8Array[u32Size-1]; /* Choose pivot as the middle element of array */
      /* EasyCASE - */
      /* Build the 2 arrays with Less or Greater than pivot */
      for (u32Counter = 0; u32Counter < u32Size; u32Counter++)
         {
         if (u8Array[u32Counter] <= u8Pivot)
            {
            au8Less[u32LocalCounter1] = u8Array[u32Counter];
            /* EasyCASE - */
            u32LocalCounter1++; /* increment pointer address */
            }
         else
            {
            au8Greater[u32LocalCounter3] = u8Array[u32Counter];
            /* EasyCASE - */
            u32LocalCounter3++; /* increment pointer address */
            }
         }
      /* At this moment, in case the input string length is the same with one of the splitted arrays, 
       * we'll enter an endless loop. Move the Pivot to the empty array! */
      if (u32LocalCounter1 == 0 /* Small array is empty */)
         {
         au8Less[0] = u8Pivot;
         u32LocalCounter1--;
         u32LocalCounter3++;
         }
      else
         {
         if (u32LocalCounter3 == 0 /* Large array is empty */)
            {
            au8Greater[0] = u8Pivot;
            u32LocalCounter1--;
            u32LocalCounter3++;
            }
         else
            {
            /* Do Nothing */
            }
         }
      /* Just finished splitting into 2 array, one with values smaller or eq than Pivot, the other with 
       * larger values. Continue sorting the SmallEq array. */
      /* EasyCASE - */
      SORT_QuickSort(&au8Less[0], u32LocalCounter1);
      /* EasyCASE - */
      /* Sort the Large array, without the last element as XX */
      SORT_QuickSort(&au8Greater[0], u32LocalCounter3);
      /* EasyCASE - */
      memcpy(u8Array, &au8Less, u32LocalCounter1);
      /* EasyCASE - */
      u8Array = u8Array + u32LocalCounter1;
      /* EasyCASE - */
      memcpy(u8Array, &au8Greater, u32LocalCounter3);
      }
   else
      {
      /* ERROR, or FINISHED?! */
      }
   return 1;
   }
/* EasyCASE ) */
#elif 0 /* Bubble Sort, recursive */
/* EasyCASE ( 286
   SORT_QuickSort - swap elements recursive */
/* EasyCASE F */
static bool SORT_QuickSort(uint8 * u8Array, uint32 u32Size)
   {
   /* Insert Algo below! */
   /* EasyCASE - */
    /* --------------------------------------------------------
   function quicksort(array)
       temp := empty number
       counter := variable
       if length(array) > 1  
       counter := 0
           for each x in array
               if x <= x+1 then do nothing
               if x  > x+1 then swap x with x+1 (using temp); counter++
               continue until end of array
           if counter != 0 then quicksort(array)
    -------------------------------------------------------- */
   /* EasyCASE - */
   #ifdef DEBUG1
   uint32 u32PrintCounter = 0;
   #endif
   /* EasyCASE - */
   bool boArrayStillSorting = False;
   uint8 u8Temp;
   uint32 u32Counter;
   if (u32Size > 1)
      {
      for (u32Counter = 0; u32Counter < u32Size - 1; u32Counter++)
         {
         if (u8Array[u32Counter] <= u8Array[u32Counter + 1])
            {
            /* Do nothing */
            }
         else
            {
            /* Swap bytes */
            u8Temp = u8Array[u32Counter];
            u8Array[u32Counter] = u8Array[u32Counter + 1];
            u8Array[u32Counter + 1] = u8Temp;
            /* EasyCASE - */
            boArrayStillSorting = True;
            }
         }
      if (boArrayStillSorting == True)
         {
         SORT_QuickSort(&u8Array[0], u32Size);
         }
      else
         {
         /* Finished */
         }
      }
   return 1;
   }
/* EasyCASE ) */
#elif 0  /* Bubble Sort, iterative */
/* EasyCASE ( 297
   SORT_QuickSort - swap elements iterative */
/* EasyCASE F */
static bool SORT_QuickSort(uint8 * u8Array, uint32 u32Size)
   {
   /* Insert Algo below! */
   /* EasyCASE - */
   /* BUBBLE SORT, from:
   https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html
   */
   /* EasyCASE - */
   int i, j;
   if (u32Size > 0)
      {
      for (i = (u32Size - 1); i >= 0; i--)
         {
         for (j = 1; j <= i; j++)
            {
            if (u8Array[j-1] > u8Array[j])
               {
                             int temp = u8Array[j-1];
                             u8Array[j-1] = u8Array[j];
                             u8Array[j] = temp;
               }
            }
         }
      }
   return 1;
   }
/* EasyCASE ) */
#else
/* EasyCASE ( 308
   SORT_QuickSort - swap elements split array */
/* EasyCASE F */
static bool SORT_QuickSort(uint8 * u8Array, uint32 u32Size)
   {
   /* Insert Algo below! */
   /* EasyCASE - */
    /* --------------------------------------------------------
   function quicksort(array)
       temp := empty number
       counter := variable
       if length(array) > 1  
       counter := 0
           for each x in array
               if x <= x+1 then do nothing
               if x  > x+1 then swap x with x+1 (using temp); counter++
               continue until end of array
           if counter != 0 then quicksort(array)
    -------------------------------------------------------- */
    /* Runtime: 64seconds @ 100K input data */
   /* EasyCASE - */
   #ifdef DEBUG1
   uint32 u32PrintCounter = 0;
   #endif
   /* EasyCASE - */
   bool boArrayStillSorting = False;
   uint8 u8Temp;
   uint32 u32Counter;
   if (u32Size > 1)
      {
      for (u32Counter = 0; u32Counter < u32Size - 1; u32Counter++)
         {
         if (u8Array[u32Counter] <= u8Array[u32Counter + 1])
            {
            /* Do nothing */
            }
         else
            {
            /* Swap bytes */
            u8Temp = u8Array[u32Counter];
            u8Array[u32Counter] = u8Array[u32Counter + 1];
            u8Array[u32Counter + 1] = u8Temp;
            /* EasyCASE - */
            boArrayStillSorting = True;
            }
         }
      if (boArrayStillSorting == True)
         {
         SORT_QuickSort(&u8Array[0], u32Size);
         }
      else
         {
         /* Finished */
         }
      }
   return 1;
   }
/* EasyCASE ) */
#endif
/* EasyCASE ( 17
   SORT_BubbleSort */
/* EasyCASE F */
bool SORT_BubbleSort(uint8 * u8Array, uint32 u32Size)
   {
   /* Insert Algo below! */
   return True;
   }
/* EasyCASE ) */
#else
/* EasyCASE - */
/* https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C */
/* EasyCASE ( 273
   quicksort */
/* EasyCASE < */
void quicksort(uint8 *A, uint32 len)
{
  if (len < 2) return;
 
  uint32 pivot = A[len / 2];
 
  uint32 i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;
 
    if (i >= j) break;
 
    uint32 temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }
 
  quicksort(A, i);
  quicksort(A + i, len - i);
}
/* EasyCASE > */
/* EasyCASE ) */
#endif
/* EasyCASE ( 2
   MAIN() */
/* EasyCASE F */
void main(void)
   {
   struct timespec SORT_Spec;
   uint32            SORT_u32MsAtEnd;
   uint32            SORT_u32MsAtStart;
   /* EasyCASE - */
   uint32 u32Counter;
   /* EasyCASE - */
   /* Open file for write random data */
   FILE * filePointer = NULL;
   /* EasyCASE ( 43
      Initializations */
   /* Clear time holders */
   SORT_u32MsAtStart = 0;
   SORT_u32MsAtEnd = 0;
   /* EasyCASE ) */
   /* --------------  CODE -------------------*/
   /* EasyCASE - */
   filePointer = fopen("./RandomFile.txt" , "r" );
   if (filePointer != NULL)
      {
      /* EasyCASE ( 53
         Done once */
      #ifdef CREATE_INPUT_FILE /* create the file and fill with data. Done only once, ast start-up */
      /* EasyCASE - */
      filePointer = fopen("./RandomFile.txt" , "w" );
      for (u32Counter = 0; u32Counter < SORT__nListElementSize; u32Counter++)
         {
         fprintf(filePointer, "%d ", rand() % 100);  /* 0...100*/
         }
      fclose(filePointer);
      /* EasyCASE - */
      exit(1);
      /* EasyCASE - */
      #endif /* create the file and fill with data. Done only once, ast start-up */
      /* EasyCASE ) */
      /* EasyCASE ( 82
         Read pointed File */
      /* Read content of pointed File, into local Array */
      /* EasyCASE - */
      /* read all file content into local array for later sorting */
      for (u32Counter = 0; u32Counter < SORT__nListElementSize; u32Counter++)
         {
         fscanf(filePointer, "%hhu", &SORT__au8ReadDataArray[u32Counter]);
         }
      fclose(filePointer);
      /* EasyCASE ) */
      /* We don't really need to print the file content! */
      /* EasyCASE ( 248
         removed prints */
      #ifdef DEBUG2
      /* EasyCASE - */
      fprintf(stderr, "++++++++++ Input array is: ");
      for (u32Counter = 0; u32Counter < SORT__nListElementSize; u32Counter++)
         {
         fprintf(stderr, "%d ", SORT__au8ReadDataArray[u32Counter]);
         }
      fprintf(stderr, "\n");
      fflush (stderr);
      /* EasyCASE - */
      #endif
      /* EasyCASE ) */
      /*
        ____ _____  _    ____ _____      _    _     ____  ___  
       / ___|_   _|/ \  |  _ \_   _|    / \  | |   / ___|/ _ \ 
       \___ \ | | / _ \ | |_) || |     / _ \ | |  | |  _| | | |
        ___) || |/ ___ \|  _ < | |    / ___ \| |__| |_| | |_| |
       |____/ |_/_/   \_\_| \_\|_|   /_/   \_\_____\____|\___/ 
                                                               
      */
      /* EasyCASE ( 90
         TIME STAMP START */
      clock_gettime(CLOCK_MONOTONIC, &SORT_Spec);
      
      SORT_u32MsAtStart = SORT_Spec.tv_sec * 1000 + (SORT_Spec.tv_nsec / 1000000);
      
      fprintf(stderr, "\n[%ld] Started QuickSort! \n", SORT_u32MsAtStart);
      fflush(stderr);
      /* EasyCASE ) */
      #ifdef MY_ALGO
      /* EasyCASE - */
      /* Call Quick Algo with pointer to RAM stored, unsorted file read data */
      SORT_QuickSort(&SORT__au8ReadDataArray[0], SORT__nListElementSize);
      /* EasyCASE - */
      #else
      /* EasyCASE - */
      quicksort(&SORT__au8ReadDataArray[0], SORT__nListElementSize);
      /* EasyCASE - */
      #endif
      /* EasyCASE ( 91
         TIME STAMP END */
      clock_gettime(CLOCK_MONOTONIC, &SORT_Spec);
      
      SORT_u32MsAtEnd = SORT_Spec.tv_sec * 1000 + (SORT_Spec.tv_nsec / 1000000);
      
      fprintf(stderr, "[%ld] Finished QuickSort! Duration = %ld Ms \n", SORT_u32MsAtEnd, SORT_u32MsAtEnd - SORT_u32MsAtStart);
      fflush(stderr);
      /* EasyCASE ) */
      /* EasyCASE ( 142
         Sorted ARRAY */
      #ifdef DEBUG2
      /* EasyCASE - */
      fprintf(stderr, "\n -------- Sorted ARRAY is: ");
      for (u32Counter = 0; u32Counter < SORT__nListElementSize; u32Counter++)
         {
         fprintf(stderr, "%d ", SORT__au8ReadDataArray[u32Counter]);
         }
      fprintf(stderr, "\n");
      fflush (stderr);
      /* EasyCASE - */
      #endif
      /* EasyCASE ) */
      /* EasyCASE ( 257
         Write Sorted string to an txt file */
      filePointer = fopen("./SortedFile.txt" , "w" );
      if (filePointer != NULL)
         {
         /* EasyCASE ( 262
            Write string to pointed File */
         /* Read content of pointed File, into local Array */
         /* EasyCASE - */
         /* read all file content into local array for later sorting */
         for (u32Counter = 0; u32Counter < SORT__nListElementSize; u32Counter++)
            {
            fprintf(filePointer, "%d ", SORT__au8ReadDataArray[u32Counter]);
            }
         fflush(filePointer);
         /* EasyCASE - */
         fclose(filePointer);
         /* EasyCASE ) */
         }
      else
         {
         perror("Cannot write to file");
         }
      /* EasyCASE ) */
      }
   else
      {
      perror("Open file to read error");
      }
   return;
   }
/* EasyCASE ) */
/* EasyCASE ) */

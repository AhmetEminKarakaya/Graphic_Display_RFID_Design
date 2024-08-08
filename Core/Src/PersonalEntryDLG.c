/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)

#include "main.h"
#include "fatfs.h"
#include "rc522.h"
#include "string.h"
#include "GUI.h"

// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0 (GUI_ID_USER + 0x00)
#define ID_TEXT_0 (GUI_ID_USER + 0x01)
#define ID_TEXT_1 (GUI_ID_USER + 0x02)
#define ID_TEXT_2 (GUI_ID_USER + 0x03)
#define ID_TEXT_3 (GUI_ID_USER + 0x04)
#define ID_TEXT_4 (GUI_ID_USER + 0x05)
#define ID_TEXT_5 (GUI_ID_USER + 0x06)
#define ID_TEXT_6 (GUI_ID_USER + 0x07)
#define ID_TEXT_7 (GUI_ID_USER + 0x08)


// USER START (Optionally insert additional defines)

uint8_t status;
uint8_t str[MAX_LEN];
uint8_t sNum[5];

FATFS 	fs;
FRESULT res;
FIL 	file;

short br,i;
char ret;
char *ptr;
char *token;
char strCardID[16];
char buffer[4096];
char PersonalInfo[5][20];

// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
		  { FRAMEWIN_CreateIndirect, "PersonalEntry", ID_FRAMEWIN_0, 120, 0, 200, 240, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Name:", ID_TEXT_0, 7, 18, 49, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Registry No:", ID_TEXT_1, 6, 41, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Occupation:", ID_TEXT_2, 7, 64, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Card No:", ID_TEXT_3, 7, 85, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Text", ID_TEXT_4, 70, 16, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Text", ID_TEXT_5, 70, 39, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Text", ID_TEXT_6, 70, 63, 80, 20, 0, 0x0, 0 },
		  { TEXT_CreateIndirect, "Text", ID_TEXT_7, 70, 84, 120, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreatePersonalEntry
*/
WM_HWIN CreatePersonalEntry(void);
WM_HWIN CreatePersonalEntry(void) {
WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)

char CheckData(char *CardID)
{
	sprintf(strCardID,"%03d%03d%03d%03d%03d",CardID[0],CardID[1],CardID[2],CardID[3],CardID[4]);

	res = f_open(&file, "liste.txt", FA_READ);

	if(res == FR_OK)
	{
		res = f_read(&file,buffer,sizeof(buffer),&br);
		if(res == FR_OK)
		{
			ptr = strstr(buffer,strCardID);
			if(ptr)
			{
				token = strtok(ptr,"\t");
				i=0;
				while(token != NULL)
				{
					sprintf(&PersonalInfo[i++][0],token);
					if(i == 5) break;
					token = strtok(NULL,"\t");
				}
				ptr = strchr(&PersonalInfo[4][0],'\r');
				*ptr = 0;
			}
		}
		else
		{
			f_close(&file);
			return 1;
		}
	}
	else
	{
		f_close(&file);
		return 1;
	}

	f_close(&file);

	return 0;
}

char _acBuffer[1024];
static int _GetData(void * p, const U8 ** ppData, unsigned NumBytesReq, U32 Offset) {
    unsigned int NumBytesRead;
    f_lseek((FIL *) p, Offset); //Set file pointer to the required position
    /*
     * Read file function
     * FIL*     fp      -	Pointer to the file object
     * void*    buff    -	Pointer to data buffer
     * UINT     btr     -	Number of bytes to read
     * UINT*    br      -	Pointer to number of bytes read
     */
    f_read((FIL *) p, (void *) _acBuffer, NumBytesReq, &NumBytesRead); //Read data into buffer
    *ppData = (const U8 *) _acBuffer; //Set pointer to the buffer
    return NumBytesRead;
}


void RFID_Reader()
{
	WM_HWIN hWin;

	TEXT_Handle hText4,hText5,hText6,hText7;

    MFRC522_Init();

	ret = f_mount(&fs,"", 0);

	if(ret != FR_OK)
	{
	   while(1);
	}

	 hWin = CreatePersonalEntry();

	 hText4 = WM_GetDialogItem(hWin, ID_TEXT_4);
	 hText5 = WM_GetDialogItem(hWin, ID_TEXT_5);
	 hText6 = WM_GetDialogItem(hWin, ID_TEXT_6);
	 hText7 = WM_GetDialogItem(hWin, ID_TEXT_7);

	 while(1)
	 {
		 status = MFRC522_Request(PICC_REQIDL, str);
		 status = MFRC522_Anticoll(str);
		 memcpy(sNum, str, 5);
		 HAL_Delay(100);

		 if(CheckData(sNum) == 0)
		 {
			 TEXT_SetText(hText4, &PersonalInfo[1][0]);
			 TEXT_SetText(hText5, &PersonalInfo[2][0]);
			 TEXT_SetText(hText6, &PersonalInfo[3][0]);
			 TEXT_SetText(hText7, &PersonalInfo[0][0]);

			 res = f_open(&file, &PersonalInfo[4][0], FA_OPEN_EXISTING | FA_READ);
		  	 	 if(res == FR_OK)
		  	 		 GUI_BMP_DrawEx(_GetData, &file, 14, 30);

		  	 	 f_close(&file);
		 }
		 HAL_Delay(250);
		 GUI_Exec();
	  }
}

// USER END

/*************************** End of file ****************************/

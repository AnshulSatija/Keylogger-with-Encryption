#include <iostream>
#include <fstream>
using namespace std;
int main()
{
  	char dictionary[] ={ '\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
  	char dictionary1[] ={ '\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  	char dictionarynum[] ={ '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
  	char dictionarysym[] ={ '\0', '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', '-', '.','/', ':', ';', '<', '=', '>', '?', '@', '\[', '\\', ']', '^', '_', '`', '{', '|', '}', '~' };
  	int k = 0;
  	char x;
  	int n;
  	string str;
  	string str1;
  	int quo=0;
  	cout << "Welcome to cryptography program \n " << endl;
  	cout << "Enter your input filename ";
  	getline (cin, str);
  	cout << "Enter your output filename ";
  	getline (cin, str1);
  	cout << "Give key ";
  	cin >> n;
  	std::string finalstr;
	ifstream inFile;
    inFile.open(str.c_str());
    ofstream MyFile(str1.c_str());
    if (!inFile)
	{
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >>std::noskipws>> x) 
	{
    	k = 0;
      	for (int i = 1; i < 27; i++)
		{
	 		if (dictionary[i] == x)
	    	{
	      		if ((i - n) > 0)
				{
		  			MyFile<< dictionary[(i - n)];
		  			k = k + 1;
				}
	      		else
				{
		  			quo = n / 26;
		  			if (quo == 0)
		    		{
		      			MyFile<< dictionary[26 + i - n];
		      			k = k + 1;
		   			}
		  			else
		    		{
		      			MyFile<< dictionary[(26 * quo) + i - n];
		      			k = k + 1;
		    		}
				}
	    	}
	  		else if (dictionary1[i] == x)
	    	{
	      		if ((i - n) > 0)
				{
		  			MyFile<< dictionary1[i - n];
		  			k = k + 1;
				}
	      		else
				{
		  			quo = n / 26;
		  			if (quo == 0)
		   	 		{
		     		 	MyFile<< dictionary1[26 + i - n];
		      			k = k + 1;
		    		}
		  			else
		    		{
		      			MyFile<< dictionary1[(26 * quo) + i - n];
		      			k = k + 1;
		    		}
				}	
	    	}
		}
      	for (int i = 1; i < 10; i++)
		{	
	 		if (dictionarynum[i] == x)
	    	{
	      		if ((i - n) > 0)
				{
		  			MyFile<< dictionarynum[(i - n)];
		  			k = k + 1;
				}
	      		else
				{
		  			quo = n / 9;
		  			if (quo == 0)
		    		{
		      			MyFile<< dictionarynum[9 + i - n];
		      			k = k + 1;
		    		}
		  			else
		    		{
		      			MyFile<< dictionarynum[(9 * quo) + i - n];
		      			k = k + 1;
		    		}
				}
	    	}
		}
		for (int i = 1; i < 33; i++)
		{
	 		if (dictionarysym[i] == x)
	    	{
	      		if ((i - n) > 0)
				{
		  			MyFile<< dictionarysym[(i - n)];
		  			k = k + 1;
				}
	      		else
				{
		  			quo = n / 32;
		  			if (quo == 0)
		    		{
		      			MyFile<< dictionarysym[32 + i - n];
		      			k = k + 1;
		    		}
		  			else
		    		{
		      			MyFile<< dictionarysym[(32 * quo) + i - n];
		      			k = k + 1;
		    		}
				}
	    	}
		}
		
    	if (k == 0)
		{
	  		MyFile<< x;
		}
    }
  return 0;   
}


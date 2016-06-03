#include<iostream>
#include<string>

unsigned long max(unsigned long a, unsigned long b)
{
	return (a>b) ? a : b;
}

typedef char* longNumber;


longNumber CreateLong(const char* str = "0")
{
	unsigned long length = strlen(str);
	char check; 

				
	if (str == NULL || length == 0)
	{
		longNumber result = new char[2];
		result[0] = '0';
		result[1] = '\0';
		return result;
	}

	unsigned long indexCounter;
	for (indexCounter = 0; indexCounter < length; indexCounter++)
	{
		check = str[indexCounter];
		if (check < '0' || check > '9')
		{
		
			longNumber result = new char[2];
			result[0] = '0';
			result[1] = '\0';
			return result;
		}
	}

	
	for (indexCounter = 0; indexCounter < length; indexCounter++)
	{
		result[indexCounter] = str[length - 1 - indexCounter]; 
	}
	result[indexCounter] = '\0'; 

	while (result[--indexCounter] == '0')
	{
		if (indexCounter == 0)
		{
			break; 
		}
	}
	result[indexCounter + 1] = '\0'; 

	return result;
}


void destroyLong(longNumber & lnum)
{
	delete lnum;
	lnum = NULL;
	
}

void add(const longNumber& longNum1, const longNumber& longNum2, longNumber & result)
{
	
	if (longNum1 == NULL || longNum2 == NULL)
	{
		delete result;
		result = NULL;
		cerr << "Error in addition of longNumbers at " << &longNum1 << " and " << &longNum2 << endl;
		return;
	}

	unsigned long int length1 = strlen(longNum1), length2 = strlen(longNum2);

	delete result;
	
	result = new char[max(length1, length2) + 2];

	short countAdd = 0, tempDigit = 0;
	unsigned long int indexCounter = 0;

	
	while (longNum1[indexCounter] != '\0' && longNum2[indexCounter] != '\0')
	{
		tempDigit = (longNum1[indexCounter] - '0') + (longNum2[indexCounter] - '0') + countAdd;
		if (tempDigit > 9)
		{
			tempDigit = tempDigit - 10;
			countAdd = 1;
		}
		else
		{
			countAdd = 0;
		}
		result[indexCounter] = (char)tempDigit + '0';
		indexCounter++;
	}

	
	if (longNum1[indexCounter] == '\0')
	{
		while (longNum2[indexCounter] != '\0')
		{
			tempDigit = (longNum2[indexCounter] - '0') + countAdd;
			if (tempDigit > 9)
			{
				tempDigit = tempDigit - 10; countAdd = 1;
			}
			else
			{
				countAdd = 0;
			}
			result[indexCounter] = (char)tempDigit + '0';
			indexCounter++;
		}
	}
	
	else if (longNum2[indexCounter] == '\0')
	{
		while (longNum1[indexCounter] != '\0')
		{
			tempDigit = (longNum1[indexCounter] - '0') + countAdd;
			if (tempDigit > 9)
			{
				tempDigit = tempDigit - 10; countAdd = 1;
			}
			else
			{
				countAdd = 0;
			}
			result[indexCounter] = (char)tempDigit + '0';
			indexCounter++;
		}
	}

	
	if (countAdd == 1)
	{
		result[indexCounter] = '1';
		indexCounter++;
	}

	result[indexCounter] = '\0'; 





void subtract(const longNumber& longNum1, const longNumber& longNum2, longNumber & result)
{


	if (longNum1 == NULL || longNum2 == NULL)
	{
		delete result;
		result = NULL;
		cerr << "Error in subtraction of longNumber at " << &longNum2
			<< " from longNumber at " << &longNum2 << endl;
		return;
	}

	unsigned long int length1 = strlen(longNum1), length2 = strlen(longNum2);

	delete result;
	result = new char[max(length1, length2) + 2];

	short countSub = 0, tempDigit = 0;
	unsigned long int indexCounter = 0;

	while (longNum2[indexCounter] != '\0')
	{
		tempDigit = (longNum1[indexCounter] - '0') - (longNum2[indexCounter] - '0') - countSub;
		if (tempDigit < 0)
		{
			tempDigit += 10;
			countSub = 1;
		}
		else
		{
			countSub = 0;
		}
		result[indexCounter] = tempDigit + '0';
		indexCounter++;
	}

	while (longNum1[indexCounter] != '\0')
	{
		tempDigit = (longNum1[indexCounter] - '0') - countSub;
		if (tempDigit < 0)
		{
			tempDigit += 10;
			countSub = 1;
		}
		else
		{
			countSub = 0;
		}
		result[indexCounter] = tempDigit + '0';
		indexCounter++;
	}

	result[indexCounter] = '\0'; 
	while (result[--indexCounter] == '0')
	{
		if (indexCounter == 0)
		{
			break; 
		}
	}
	result[indexCounter + 1] = '\0';
}




void multiplyDigitLong(unsigned short digit, const longNumber & longNum, longNumber & result)
{
	
	if (longNum == NULL)
	{
		delete result;
		result = NULL;
		cerr << "Error in multiplication of longNumber at " << &longNum << " by " << digit << endl;
		return;
	}

	
	if (digit>10)
	{
		digit %= 10;
	}

	long int length = strlen(longNum);
	delete result;
	
	result = new char[length + 2];

	
	short countMult = 0, tempDigit = 0;
	unsigned long indexCounter = 0;

	
	while (longNum[indexCounter] != '\0')
	{
		tempDigit = (longNum[indexCounter] - '0') * digit + countMult;
		result[indexCounter] = tempDigit % 10 + '0';
		countMult = tempDigit / 10;
		indexCounter++;
	}

	if (countMult != 0)
	{
		result[indexCounter] = countMult + '0';
		indexCounter++;
	}

	result[indexCounter] = '\0';

	
	while (result[--indexCounter] == '0')
	{
		if (indexCounter == 0)
		{
			break; 
		}
	}
	result[indexCounter + 1] = '\0';

}


void printLong(const longNumber & longNum, char c = ' ')
{
	
	if (longNum == NULL)
	{
		cerr << "Error in trying to print longNumber at " << &longNum << endl;
		return;
	}

	unsigned long length = strlen(longNum);

	unsigned short tripleCount = (short)length % 3;

	while (length--)
	{
		cout << longNum[length] - '0';
		if (tripleCount == 1 && length > 2) 
		{
			cout << c;
		}
		tripleCount = (short)length % 3;
	}
}





void main()
{
	cout << "Enter two long numbers, separated by a comma: ####,####" << endl;
	cout << "Make sure that the first is greater than the second." << endl;
	char s1[100], s2[100];
	cin.getline(s1, 99, ',');
	cin >> s2;


	longNumber l1 = CreateLong(s1), l2 = CreateLong(s2), l3 = CreateLong();

	cout << endl;

	printLong(l1, '\''); 
	cout << endl << "+" << endl;
	printLong(l2, '\'');
	cout << endl << "=" << endl;
	add(l1, l2, l3);
	printLong(l3, '\'');
	cout << endl << endl;

	printLong(l1);
	cout << endl << "-" << endl;
	printLong(l2);
	cout << endl << "=" << endl;
	subtract(l1, l2, l3);
	printLong(l3);

	cout << endl;
	unsigned short num;
	do
	{
		cout << "Enter a number in [0-10]: ";
		cin >> num;
	} while (num<0 || num>10);

	cout << endl;
	printLong(l1);
	cout << " * " << num << " =" << endl;
	multiplyDigitLong(num, l1, l3);
	printLong(l3);
	cout << endl;


	destroyLong(l1);
	destroyLong(l2);
	destroyLong(l3);
}

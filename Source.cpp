#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;

int main()
{
	//A = 00
	//T = 01
	//G = 10
	//C = 11

	string input;
	string subsequence;
	string subChoice;
	string fullBinary;
	string dna;
	string rna;
	string subst;
	string encoding;
	string dnaStrand1;
	string dnaStrand2;
	string reverseDna;
	string dnaComplement;
	string dnaComplementChoice;
	string dnaComplementInput;
	string binary;
	string decimalOutput;
	string textSubstrChoice;
	string textSubstr;
	string dnaToBin;
	string asciiOutput;
	int binToDec;
	char letter;
	int sz;

	//Objective 1:

	cout << "Please enter DNA or RNA for your encoding" << endl;
	cin >> encoding;
	while (encoding != "DNA" && encoding != "RNA")
	{
		cout << "Invalid entry, please enter DNA or RNA" << endl;
		cin >> encoding;
	}
	cout << endl;

	cout << "Please input an ASCII string" << endl; //I am assuming the user will input a valid ASCII string
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		string binary;
		int remainder = 0;
		int result = 0;
		letter = input.at(i);
		remainder = int(letter) % 2;
		result = int(letter) / 2;
		binary += to_string(remainder);
		while (result != 0)
		{
			remainder = result % 2;
			result = result / 2;
			binary += to_string(remainder);
		}
		reverse(binary.begin(), binary.end());
		if (binary.size() % 2 != 0)
		{
			binary.insert(0, "0");
		}
		fullBinary += binary;
	}

	//Continuation of Objective 1 and start of Objective 2:

	for (int i = 0; i < fullBinary.size(); i++)
	{
		subst = fullBinary.substr(i, 2);
		if (subst == "00")
		{
			if (encoding == "RNA")
				rna += "A";
			else
				dna += "A";
		}
		else if (subst == "01")
		{
			if (encoding == "RNA")
				rna += "U";
			else
				dna += "T";
		}
		else if (subst == "10")
		{
			if (encoding == "RNA")
				rna += "G";
			else
				dna += "G";
		}
		else if (subst == "11")
		{
			if (encoding == "RNA")
				rna += "C";
			else
				dna += "C";
		}
		i++;
	}

	if (encoding == "DNA")
		cout << "The DNA strand is: " << dna << endl << endl;
	else
		cout << "The RNA strand is: " << rna << endl << endl;

	//Objective 3: I don't understand this objective very well, so I am not completely sure what to do, but I will do what I think it is asking for me to do.
	
	cout << "Would you like to find standard ASCII text substrings in a DNA strand?" << endl; //I am assuming they enter a valid DNA strand.
	cin >> textSubstrChoice;
	cout << endl;
	if (textSubstrChoice == "yes" || textSubstrChoice == "Yes")
	{
		cout << "Please enter the DNA strand" << endl;
		cin >> textSubstr;

		for (int i = 0; i < textSubstr.size(); i++)
		{
			subst = textSubstr.substr(i, 1);
			if (subst == "A")
			{
				dnaToBin += "00";
			}
			else if (subst == "T")
			{
				dnaToBin += "01";
			}
			else if (subst == "G")
			{
				dnaToBin += "10";
			}
			else if (subst == "C")
			{
				dnaToBin += "11";
			}
		}

		for (int i = 0; i < dnaToBin.size();)
		{
			binary = dnaToBin.substr(i, 8);
			binToDec = stoi(binary);
			int remainder;
			int decimal = 0;
			int base = 1;
			while (binToDec > 0)
			{
				remainder = binToDec % 10;
				decimal += remainder * base;
				base *= 2;
				binToDec /= 10;
			}

			asciiOutput += char(decimal);
			i += 8;
		}

		string letter;
		int position;
		for (int i = 0; i < asciiOutput.size(); i++)
		{
			if (!isdigit(asciiOutput[i]))
			{
				position = i;
				break;
			}
			else
			{
				position = -1;
			}
		}

		cout << "The ASCII text substring starts at: " << position << endl << endl;
	}

	//Objective 4:

	cout << "Would you like to find the ASCII equivalent of the primary strand of DNA given a complementary strand of DNA?" << endl; //I am assuming the user will input yes/Yes to use this interface, or no to move on.
	cin >> dnaComplementChoice;	
	cout << endl;
	if (dnaComplementChoice == "yes" || dnaComplementChoice == "Yes")
	{
		cout << "Please enter a complementary strand of DNA" << endl; //I am assuming that the user enters a valid DNA strand
		cin >> dnaComplementInput;
		for (int i = 0; i < dnaComplementInput.size(); i++)
		{
			subst = dnaComplementInput.substr(i, 1);
			if (subst == "A")
			{
				dnaComplement += "T";
			}
			else if (subst == "T")
			{
				dnaComplement += "A";
			}
			else if (subst == "G")
			{
				dnaComplement += "C";
			}
			else if (subst == "C")
			{
				dnaComplement += "G";
			}
		}

		cout << "This is the primary strand: " << dnaComplement << endl;


		for (int i = 0; i < dnaComplement.size(); i++)
		{
			subst = dnaComplement.substr(i, 1);
			if (subst == "A")
			{
				reverseDna += "00";
			}
			else if (subst == "T")
			{
				reverseDna += "01";
			}
			else if (subst == "G")
			{
				reverseDna += "10";
			}
			else if (subst == "C")
			{
				reverseDna += "11";
			}
		}

		for (int i = 0; i < reverseDna.size();)
		{
			binary = reverseDna.substr(i, 8);
			binToDec = stoi(binary);
			int remainder;
			int decimal = 0;
			int base = 1;
			while (binToDec > 0)
			{
				remainder = binToDec % 10;
				decimal += remainder * base;
				base *= 2;
				binToDec /= 10;
			}

			decimalOutput += char(decimal);
			i += 8;
		}
		cout << "The ASCII Equivalent of the complementary strand is: " << decimalOutput << endl << endl;
	}
	
	//Objective 5:

	cout << "Would you like to find the longest common subsequence between two single DNA strands?" << endl; //I am assuming the user will enter yes/Yes to use this feature, or no to move on.
	cin >> subChoice;
	cout << endl;
	if (subChoice == "yes" || subChoice == "Yes")
	{
		cout << "Please enter the first DNA strand" << endl; //I am assuming that the user enters a valid DNA strand.
		cin >> dnaStrand1;

		cout << "Please enter the second DNA strand" << endl; //I am assuming that the user enters a valid DNA strand.
		cin >> dnaStrand2;

		if (dnaStrand1.size() < dnaStrand2.size())
			sz = dnaStrand1.size();
		else
			sz = dnaStrand2.size();


		for (int i = 0; i < sz; i++)
		{
			if (dnaStrand1.at(i) == dnaStrand2.at(i))
				subsequence += dnaStrand1.at(i);
		}

		if (subsequence.size() != 0)
		{
			cout << "The longest common subsequence of the two DNA strands is: " << subsequence << endl << endl;
		}
		else
			cout << "There is no common subsequence between the two DNA strands" << endl << endl;
		
		cout << "Thank you, this is the end of the program." << endl << endl;
	}
	else
		cout << "Thank you, this is the end of the program." << endl << endl;

	system("pause");
}
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class WordCounter
{
private:

	int charCount;
	int wordCount;
	int lineCount;
	string text;

public:
	WordCounter()
	{
		charCount = 0;
		wordCount = 0;
		lineCount = 0;
	}

	void readFile(string filename)
	{
		ifstream file(filename);

		if (!file.is_open())
		{
			cout << "File not found" << endl;
			return;
		}

		string line;
		while (getline(file, line))
		{
			text += line + '\n';
			lineCount++;
		}

		file.close();
	}

	void analyze()
	{
		bool word = false;

		for (char c : text)
		{
			charCount++;

			if (c == ' ' || c == '\n')
			{
				word = false;
			}
			else
			{
				if (!word)
				{
					wordCount++;
					word = true;
				}
			}
		}
	}

	void save(string filename)
	{
		ofstream file(filename);

		if (!file.is_open())
		{
			cout << "File not found" << endl;
			return;
		}

		file << "Number of characters: " << charCount << endl;
		file << "Number of words: " << wordCount << endl;
		file << "Number of lines: " << lineCount << endl;
	}
};

int main()
{
	WordCounter counter;

	counter.readFile("input.txt");
	counter.analyze();
	counter.save("result.txt");

	cout << "Result is written to result.txt" << endl;

	return 0;
}
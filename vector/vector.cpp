/***************************************
 * Автор: Тенц Ангелина                *
 * Вариант: 27                         *   
 * Название: строки, векторы и словари *
 ***************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;

int main() {
  char part;
	
  cout << "Enter part letter: ";
  cin >> part;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (part == 'A') {
    string line, fromLine, toLine;
	int maxLineLength;

	maxLineLength = 200;

	cout << "Enter lines: ";
	getline(cin, line);
	getline(cin, fromLine);
	getline(cin, toLine);

	if (line.size() > maxLineLength || fromLine.size() > 1 || toLine.size() > 1) {
	  cout << "INVALID";
	  return 1;
	}

	if (line.empty()) {
	  cout << "EMPTY";
	  return 0;
	}

	for (int symbolIndex = 0; symbolIndex < line.size(); ++symbolIndex) {
	  if (line[symbolIndex] == fromLine[0]) {
	    line[symbolIndex] = toLine[0];
	  }
	}

	cout << line;
  }

  if (part == 'B') {
    int count;
	int number;
	vector<int> numbers;
	vector<int> result;
	int maxCount, minCount, minValue, maxValue;
	
	minCount = 0;
	maxCount = 200;
	minValue = -1000;
	maxValue = 1000;

	cout << "Enter numbers count: ";
	cin >> count;

	if (count > maxCount || count < minCount) {
	  cout << "INVALID";
	  return 1;
	}

	cout << "Enter numbers: ";

	for (int numberIndex = 0; numberIndex < count; ++numberIndex) {
	  cin >> number;
	  if (number > maxValue || number < minValue) {
	    cout << "INVALID";
		return 1;
	  }
	  numbers.push_back(number);
	}

	for (int numberIndex = 0; numberIndex < numbers.size(); ++numberIndex) {
	  if ((numberIndex + 1) % 2 != 0) {
	    result.push_back(numbers[numberIndex]);
	  }
	}
	if (result.empty()) {
		cout << "EMPTY";
	} else {
	  for (int resultIndex = 0; resultIndex < result.size(); ++resultIndex) {
		cout << " " << result[resultIndex];
	  }
	}
  }

  if (part == 'C') {
    int pairCount;
	string key, deleteKey;
	int value;
	map<string, int> data;

	cout << "Enter the number of pairs: ";
	cin >> pairCount;

	for (int pairIndex = 0; pairIndex < pairCount; ++pairIndex) {
	  cin >> key;
	  cin >> value;
	  data[key] = value;
	}

	cout << "Enter the key to delete: ";
	cin >> deleteKey;

	data.erase(deleteKey);

	if (data.empty()) {
	  cout << "EMPTY\n";
	} else {
	  for (auto& pair : data) {
		cout << pair.first << " " << pair.second << "\n";
	  }
	}
  }

  if (part == 'D') {
	int fileCount;
	int totalAll, sizeValue;
	string folder, sizeText, folderName;
	vector<map<string, string>> files;
	vector<string> result;
	map<string, int> folderTotals;
	map<string, string> file;

	totalAll = 0;

	cout << "Enter the number of files: ";
	cin >> fileCount;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter folder names and files size:\n";

	for (int fileIndex = 0; fileIndex < fileCount; ++fileIndex) {
	  getline(cin, folder);
	  getline(cin, sizeText);
	  file["folder"] = folder;
	  file["size"] = sizeText;
	  files.push_back(file);
	}

	for (auto& file : files) {
	  folderName = file["folder"];
	  sizeValue = 0;
	  for (char symbol : file["size"]) {
		sizeValue = sizeValue * 10 + (symbol - '0');
	  }
	  folderTotals[folderName] += sizeValue;
	  totalAll += sizeValue;
	}

	for (auto& data : folderTotals) {
	  result.push_back(data.first + " " + to_string(data.second));
	}

	result.push_back("TOTAL " + to_string(totalAll));

	for (string& line : result) {
	  cout << line << "\n";
	}
  }

	return 0;

}

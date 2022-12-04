#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <experimental/filesystem> // _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define endl "\n"
#define DEBUG 1
#define OLD 0
using namespace std;
namespace fs = experimental::filesystem;
void console_cp() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
class LogChecker {

	fs::path DirPath;
	string LogFileName;
	string ParsAfter;
	string Numbers = "0123456789";

	vector<string> GetVectorNameFromDir() {
		vector<string> DirNames;
		for (fs::directory_iterator::value_type dir_entry : fs::directory_iterator(DirPath))
		{
			DirNames.push_back(dir_entry.path().string());
		}
		string::iterator StringIterator;
		string cache;
		for (string& i : DirNames) {
			StringIterator = i.begin() + i.rfind('\\') + 1;
			for (; StringIterator != i.end(); StringIterator++) {
				cache.push_back(*StringIterator);
			}
			i = cache;
			cache.clear();
#if DEBUG == 1
			cout << i << endl;
#endif // DEBUG == 1
		}
		return DirNames;
	}


	int GetHowManyCharacters() {
		ifstream FILE;
		FILE.open(LogFileName);
		string line;
		int Characters = 0;
		while (getline(FILE, line))
		{
#if DEBUG == 1
			cout << line << "\t" << endl;
#endif // DEBUG == 1
			Characters += line.length();
		}
#if DEBUG == 1
		cout << "Characters = " << Characters << endl;
#endif // DEBUG == 1
		FILE.close();
		return Characters;
	}

	string GetLogFile() {
		ifstream FILE;
		FILE.open(LogFileName);
		if (FILE.is_open()) {
			string result;
			string line;
			int Characters = 0;
			while (getline(FILE, line))
			{
				result += line;
#if DEBUG == 1
				cout << line << "\t" << endl;
#endif // DEBUG == 1
			}
			FILE.close();
#if DEBUG == 1
			cout << result << endl;
#endif // DEBUG == 1
			return result;
		}
		else {
			FILE.close();
			cout << "ERROR: open file." << endl;
			return "ERROR";
		}
	}

	bool CheckIfNotInVector(vector<string> InVector, string Value) {
		for (vector<string>::iterator iterator = InVector.begin(); iterator != InVector.end(); iterator++) {
			if (*iterator == Value) {
				return false;
			}
		}
		return true;
	}

	vector<string> ParsIDFormSrring(string str) {
		vector<string> Ids;
		int ParsAfterSize = ParsAfter.size();
		string cache;
		for (int i = str.find(ParsAfter, 0), last_i = 0; i > last_i; i = str.find(ParsAfter, i + 1)) {
			for (string::iterator iterator = str.begin() + i + ParsAfterSize; *iterator != ' '; iterator++) {
				cache.push_back(*iterator);
			}
			if (CheckIfNotInVector(Ids, cache)) {
				Ids.push_back(cache);
			}
			else {
#if DEBUG == 2
				cout << "secon text finded" << endl;
#endif // DEBUG == 2
			}
			cache.clear();
			last_i = i;
		}
		return Ids;
	}

public:

	LogChecker(string Pach, string LogFileName, string ParsAfter) {
		DirPath.replace_filename(Pach);
		this->LogFileName = LogFileName;
		this->ParsAfter = ParsAfter;
#if DEBUG == 1
		cout << "DirPath = " << DirPath << endl;
		cout << "LogFileName = " << LogFileName << endl;
#endif // DEBUG == 1
	}

	void StarScript() {
		vector<string> FileNams = GetVectorNameFromDir();
		vector<string> Ids = ParsIDFormSrring(GetLogFile());
		bool IsThearErros = false;
		for (vector<string>::iterator iterator = Ids.begin(); iterator != Ids.end(); iterator++) {
			if (CheckIfNotInVector(FileNams, *iterator)) {
				cout << *iterator << " - not found!" << endl;
				IsThearErros = true;
			}
#if DEBUG == 1
			else {
				cout << *iterator << " - is here!" << endl;
			}
#endif // DEBUG == 1
		}
		if (!IsThearErros) {
			cout << "All good!";
		}
		cout << "mods count - " << Ids.size() << endl;
	}
};
int main()
{
	console_cp();
	LogChecker Script("[PathToDir]", "workshop_log.txt", " [AppID 294100] Download item ");
	Script.StarScript();
}
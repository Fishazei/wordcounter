#include <iostream>
#include <string>
using namespace std;

int runTest(string name, string input, string expect);

int main(int argc, char *argv[]){
	int result;
	result += runTest(
		"test1",
		"abrakadabra",
		"1"
	);
	result += runTest(
		"test2",
		"sim salabim",
		"2"
	);
	result += runTest(
		"test3",
		"ahalai mahalai zherebec sladkiy",
		"4"
	);
	return result;
}

int runTest(string name, string input, string expect){
	string command = "echo \"" + input + "\" | ../usr/bin/wordcounter";
	FILE* pipe = popen(command.c_str(), "r");
	if (!pipe){
		throw runtime_error("popen failed");
	}
	char buffer[128];
	string result;
	while (fgets(buffer, sizeof(buffer), pipe) != NULL){
		result += buffer;
	}
	pclose(pipe);
	result = result.substr(0, result.find('\n'));
	if (!result.compare(expect)){
		cout << name << " passed\n";
		return 0;
	}
        cout << endl << expect << endl;
	cout << result << endl;
	cout << name << " failed\n";
	return 1;
}

#include "VReadByTxt.h"

vector<Form*> VReadByTxt::read(const string& file)
{
	if (file.substr(file.find_last_of('.')) != ".txt") throw Error("read : file isn't .txt");
	vector<Form*> result;
	Form* form;
	string line;
	try {
		_fs.open(file);
		while (getline(_fs, line)) {	
			form = parse(line);
			if (form) result.push_back(form);
		}
		_fs.close();
	}
	catch (Error const& err) {
		throw err;
	}
	return result;
}

Form* VReadByTxt::parse(string line)
{
	if (!_fs.is_open()) throw Error("file isn't open");

	const VReadDetector* detector = InitializeCor::getInstance().getDetectorRead();

	return detector->detector(line);
}


#include "VReadByTxt.h"
#include <Windows.h>

int main() {
	try {
		//METTRE AILLEUR QUE DANS VISITOR CAR CE N'EST PAS UN VISITOR
		VReadByTxt* visitorDrawText = new VReadByTxt();

		vector<Form*> forms = visitorDrawText->read("test.txt");

		for (unsigned int i = 0; i < forms.size(); i++) {
			cout << *forms[i] << endl;
		}
	}
	catch (Error const& err) {
		cerr << err << endl;
	}
}
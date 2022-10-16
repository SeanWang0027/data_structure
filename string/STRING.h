#ifndef STRING
#define STRING
#include <iostream>
using namespace std;
#define OverFlow -2
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define STRING_INIT_SIZE 100
typedef int Status;

class String {
private:
	struct node {
		char* ch = NULL;
		int length = 0;
	}HString;
public:
	String();
	String(String&);
	String(const char*);
	Status StrAssign(const char*);
	friend ostream& operator<<(ostream&, String);
	Status StrCopy(String);
	Status StrEmpty();
	int StrCompare(String);
	int StrLength();
	Status ClearString();
	Status Concat(String, String );
	Status SubString(String&,int, int);
	int KMP_index(String&, int);
};

String::String() {
	HString.ch = (char*)malloc(sizeof(char) * STRING_INIT_SIZE);
	if (HString.ch == NULL) {
		cout << "Data OverFlow" << endl;
		exit(OverFlow);
	}
	HString.length = STRING_INIT_SIZE;
}

String::String(String& p) {
	int Count = p.HString.length;
	HString.length = Count;
	HString.ch = (char*)malloc(sizeof(char) * Count);
	if (HString.ch == NULL) {
		exit(OverFlow);
	}
	for (int i = 0; i < Count; ++i) {
		HString.ch[i] = p.HString.ch[i];
	}
}

String::String(const char* p) {
	int Count = 0;
	while (p[Count] != '\0') {
		Count++;
	}
	HString.length = Count;
	HString.ch = (char*)malloc(sizeof(char) * Count);
	if (HString.ch == NULL) {
		exit(OverFlow);
	}
	for (int i = 0; i < Count; ++i) {
		HString.ch[i] = p[i];
	}
}

Status String::StrAssign(const char* p) {
	int Count = 0;
	while (p[Count] != '\0') {
		Count++;
	}
	HString.length = Count;
	HString.ch = (char*)malloc(sizeof(char) * Count);
	if (HString.ch == NULL) {
		return OverFlow;
	}
	for (int i = 0; i < Count; ++i) {
		HString.ch[i] = p[i];
	}
	return OK;
}

ostream& operator<<(ostream& out, String s) {
	for (int i = 0; i < s.HString.length; i++) {
		out << s.HString.ch[i];
	}
	return out;
}

Status String::StrCopy(String s) {
	if (s.HString.ch == NULL) {
		return ERROR;
	}
	this->StrAssign(s.HString.ch);
	return OK;
}

Status String::StrEmpty() {
	if (HString.length) {
		return FALSE;
	}
	return TRUE;
}

int String::StrCompare(String s) {
	for (int i = 0; i < HString.length && i < s.HString.length; ++i) {
		if (s.HString.ch[i] != HString.ch[i]) {
			return HString.ch[i]-s.HString.ch[i];
		}
	}
	return HString.length - s.HString.length;
}

int String::StrLength() {
	return HString.length;
}

Status String::ClearString() {
	if (HString.ch) {
		free(HString.ch);
		HString.length = 0;
		return OK;
	}
	return ERROR;
}

Status String::Concat(String s, String t) {
	if (s.StrEmpty() || t.StrEmpty()) {
		return ERROR;
	}
	HString.length = s.HString.length + t.HString.length;
	HString.ch = (char*)malloc(sizeof(char) * HString.length);
	if (HString.ch == NULL) {
		return OverFlow;
	}
	int i;
	for (i = 0; i < s.HString.length; i++) {
		HString.ch[i] = s.HString.ch[i];
	}
	for (i; i < HString.length; ++i) {
		HString.ch[i] = t.HString.ch[i- s.HString.length];
	}
	return OK;
}

Status String::SubString(String&Sub,int pos, int len) {
	if (pos < 0 || pos >= HString.length) {
		return ERROR;
	}
	if (pos + len >= HString.length) {
		return ERROR;
	}
	Sub.HString.ch = (char*)malloc(sizeof(char) * len);
	if (!Sub.HString.ch) {
		return OverFlow;
	}
	Sub.HString.length = len;
	for (int i = 0; i < len; ++i) {
		Sub.HString.ch[i] = HString.ch[i+pos];
	}
	return OK;
}

int KMP_index(String T, int pos) {

}

#endif
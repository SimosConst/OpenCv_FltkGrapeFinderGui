#include "pch.h"

struct StringList {
	std::string* list;
	u_char maxLength, currCap;

#pragma region staticFunctions

	static void initList(StringList* sList, size_t max_length) {
		sList->maxLength = max_length;
		sList->list = new std::string[sList->maxLength];
	}

	static u_char containsAt(StringList* sList, std::string a) {
		for (u_char i = 0; i < sList->currCap; i++)
		{
			if (sList->list[i] == a)
				return i;
		}
		return sList->maxLength;
	}

	static bool canContainAt(StringList* sList, u_char a) {
		return a < sList->maxLength;
	}

#pragma endregion

public:
	//CONSTRUCTOR
	StringList(size_t max_length) {
		initList(this, max_length);
	}

	void add(std::string a) {
		for (u_char i = 0; i < currCap; i++)
		{
			if (list[i] == "") {
				list[currCap] = a;
				currCap++;
			}
		}
	}

	void remove(std::string a) {
		/*for (u_char i = 0; i < currCap; i++)
		{
			if (list[i] == a)
				list[i] = "";
		}*/
		auto b = containsAt(this, a);
		if (!b == maxLength) list[b] = "";
	}

	void setAt(u_char indx, std::string a) {
		if (canContainAt(this, indx))
			list[indx] = a;
	}

	void removeAt(u_char indx) {
		setAt(indx, "");
	}

};


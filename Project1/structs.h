#include "pch.h"

struct StringList {
	std::string* list;
	u_char maxLength, currCap=0;

#pragma region staticFunctions

	static void initList(StringList* sList, size_t max_length) {
		sList->maxLength = max_length;
		sList->list = new std::string[sList->maxLength];
	}

	static u_char find(StringList* sList, std::string str) {
		for (u_char i = 0; i < sList->currCap; i++)
		{
			if (sList->list[i] == str)
				return i;
		}
		return sList->maxLength;
	}

	static bool canContainAt(StringList* sList, u_char indx) {
		return indx < sList->maxLength;
	}

	static bool canContainMore(StringList* sList) {
		return canContainAt(sList, sList->currCap);
	}

	static bool canRemoveMore(StringList* sList) {
		return sList->currCap > 0;
	}

#pragma endregion

public:
	//CONSTRUCTOR
	StringList(size_t max_length) {
		initList(this, max_length);
	}

	void* add(std::string str) {
		for (u_char i = 0; i < maxLength; i++)
		{
			if (list[i] == "") {
				list[i] = str;
				currCap++;
				return &list[i];
			}
		}
		throw EXCEPTION_ARRAY_BOUNDS_EXCEEDED;
	}

	void remove(std::string str) {
		/*for (u_char i = 0; i < currCap; i++)
		{
			if (list[i] == a)
				list[i] = "";
		}*/
		if (canRemoveMore(this)) {
			auto b = find(this, str);
			if (b < maxLength) {
				list[b].clear();
				currCap--;
			}
		}
	}

	void removeFromPtr(void* ptr) {
		auto filenamePTR = (std::string*)ptr;
		remove(filenamePTR->c_str());
	}

	void setAt(u_char indx, std::string str) {
		if (canContainAt(this, indx))
			list[indx] = str;
		else
			throw EXCEPTION_ARRAY_BOUNDS_EXCEEDED;
	}

	void removeAt(u_char indx) {
		if (canRemoveMore(this)) { setAt(indx, ""); currCap--; }
	}

	bool canContainMore() {
		return canContainMore(this);
	}

	bool alreadyExsists(std::string str) {
		return find(this, str) != maxLength;
	}

	bool canBeAddedDistinct(std::string str) {
		return canContainMore() && !alreadyExsists(str);
	}
};


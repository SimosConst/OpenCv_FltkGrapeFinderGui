#include "pch.h"

struct StringList {
    std::string* list;
    u_char maxLength, currCap = 0;

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

    //Requires static declaration | Stores the passed variable
    StringList(std::string strList[]) {
        
        uchar i = 0; while (!strList[i].empty()) ++i;

        this->maxLength = i;
        this->list = strList;
    }

    std::string get(uchar position) { return list[position]; }

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

using namespace std::chrono;

struct Timer {
private:
    steady_clock::time_point tPointsCouple[2];

    void initPoint(uchar i) {
        tPointsCouple[i] = high_resolution_clock::now();
    }


public:
    Timer() { }

    void start() { initPoint(0); }
    void end() { initPoint(1); }

    long long getDuration() {
        auto a = duration_cast<microseconds>(tPointsCouple[1] - tPointsCouple[0]).count();
        return a;
    }

    //static void a() {
    //	auto start = high_resolution_clock::now();
    //	
    //	auto finish = high_resolution_clock::now();
    //	

    //}

};

struct CaseFuncRunner {
private:
    uchar count;
    //void** funcList;
    bool* caseList;
    void (**funcList)();

public:
    CaseFuncRunner(bool* cList, void (**fList)(), uchar c) {
        caseList = cList;
        funcList = fList;
        count = c;
    }
    void excec() {
        for (size_t i = 0; i < count; i++)
        {
            if (caseList[i]) {
                funcList[i]();
            }
        }
    }
};

enum ActiveTab {
    Tab1,
    Tab2
};

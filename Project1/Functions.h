#include "pch.h"
#include "structs.h"

#ifndef Funcs
#define Funcs

#pragma region static Variables

//DECLARE WIDGETS
static Fl_Double_Window* window = (Fl_Double_Window*)0;
static Fl_Native_File_Chooser* nativeFileChooser = (Fl_Native_File_Chooser*)0;
static Fl_Box* box_jpeg_image2 = (Fl_Box*)0;
static Fl_Box* box_jpeg_image = (Fl_Box*)0;
static Fl_Button* btn_loadImg = (Fl_Button*)0;
static Fl_Value_Slider* sld_Median_ksize = (Fl_Value_Slider*)0;
static Fl_Check_Button* chk_Median_enable = (Fl_Check_Button*)0;
static Fl_Tree* dirTree = (Fl_Tree*)0;

//static Fl_Check_Button* tmp_chkBtn;

static std::string tmp_groupName;
static bool tmp_active;

//DECLARE IMAGE DATA ARRAY BUFFER
static bool newImg = true;
static const int maxNum = 10000 * 10000 * 3;
static Fl_RGB_Image* InitImage = (Fl_RGB_Image*)0;
static Fl_RGB_Image* FinImage = (Fl_RGB_Image*)0;
static cv::Mat* tmpImg = new cv::Mat();
static cv::Mat* outImg = new cv::Mat();
static unsigned char* tmpImgBuffer = (unsigned char*)0;
//static unsigned char* imgBuffer = new unsigned char[maxNum]; //UNUSED
static std::string FileName;

//DECLARE IMG BOX DIMENSIONS
static short maxWidth = 600, maxHeight = 450, margin = 5;
static double boxAspRat = (double)maxWidth / (double)maxHeight;
//RESIZING VARIABLES
static short newWidth = maxWidth, newHeight = maxHeight;

//DIRECTORY TREE VARS
static const short dirTreeMaxItemCount = 20;
static std::vector<std::string> dirTreeFileNames;
static std::string* dirTreeFileNamesList = new std::string[dirTreeMaxItemCount];
static unsigned char DTNLstCap = 0;
static StringList* dirStringList= new StringList(dirTreeMaxItemCount);

#pragma endregion


#pragma region HelperFunctions

static void resizeImage(cv::Mat* img) {
	double width = img->cols, height = img->rows;

	/*** SKIP IF NOT LARGER ***/
	//bool LWidth = width > maxWidth, LHeight = height > maxHeight;
	//bool notLrgr = !(LWidth || LHeight);
	//if (notLrgr) return; 

	//Find Aspect Ratio of New Image
	auto aspRat = (double)img->cols / (double)img->rows;

	//CALCULATE RESIZING TYPE | W=>H, H=>W
	/*if (width > maxWidth && aspRat >= boxAspRat)
		newWidth = maxWidth, newHeight = maxWidth / aspRat;
	else if (height > maxHeight && aspRat <= boxAspRat)
		newWidth = maxHeight * aspRat, newHeight = maxHeight;*/
	if (aspRat >= boxAspRat)
		newWidth = maxWidth, newHeight = maxWidth / aspRat;
	else
		newWidth = maxHeight * aspRat, newHeight = maxHeight;

	//RESIZE
	auto a = *img, img1 = *img;
	cv::resize(*img, a, cv::Size(newWidth, newHeight));

	*img = a;
}

static void changeImgData() {

}

static void calcPre_MedianFiltr() {
	cv::medianBlur(*tmpImg, *outImg, sld_Median_ksize->value());
}

static Fl_RGB_Image* Mat2FlRgbImg(cv::Mat mat, bool newImg = false) {
	//NEW BYTE ARRAY
	auto maxLength = mat.datalimit - mat.datastart;

	////Dont create new if one already exists 
	//tmpImgBuffer = newImg ? new unsigned char[maxLength] : tmpImgBuffer;
	if (newImg)
		tmpImgBuffer = new unsigned char[maxLength];

	//COPY CV::MAT DATA TO IMG BUFFER
	for (int i = 0; i < maxLength; i += 3) {
		auto i1 = i, i2 = i + 1, i3 = i + 2;
		tmpImgBuffer[i1] = mat.data[i3];
		tmpImgBuffer[i2] = mat.data[i2];
		tmpImgBuffer[i3] = mat.data[i1];
	}

	return new Fl_RGB_Image(tmpImgBuffer, mat.cols, mat.rows);
}

static void drawImage2(Fl_Box* imgFrame) {
	//SET TO IMG TO FLBOX
	imgFrame->image(InitImage);
	//RELOAD GRAPHICS
	window->redraw();
}

#pragma endregion

#pragma region Deprecated
//static void resetImage(Fl_Box* box) {
//	for (int i = 0; i < maxNum; i++) {
//		imgBuffer[i] = 1000;
//	}
//	box->image(new Fl_RGB_Image(imgBuffer, 450, 450));
//	box->redraw();
//}

//static void drawImage(Fl_Box* imgFrame) {
//	//imgFrame->hide();
//
//	auto img1 = cv::imread(FileName);
//	if (img1.dims != 0) resizeImage(&img1);
//	auto arrLen = img1.cols * img1.rows * 3;
//
//	auto imgData = imgBuffer;
//
//	//COPY CV::MAT DATA TO IMG BUFFER
//	for (int i = 0; i < arrLen; i += 3) {
//		auto i1 = i, i2 = i + 1, i3 = i + 2;
//		imgData[i1] = img1.data[i3];
//		imgData[i2] = img1.data[i2];
//		imgData[i3] = img1.data[i1];
//	}
//
//	auto img = new Fl_RGB_Image(imgData, img1.cols, img1.rows);
//
//	imgFrame->image(img);
//	//imgFrame->show();
//	//imgFrame->redraw();
//	window->redraw();
//}

/*TRYING TO IMPEMENT UTF - 16 FILEDIALOG*/
//static void chooseFile2() {
//	OPENFILENAME ofn;
//	auto filename = FileName == "" ? "C:\\Users\\GENERIC\\Pictures" : FileName.c_str();
//	//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//	////std::string narrow = converter.to_bytes(wide_utf16_source_string);
//	//std::wstring wide = converter.from_bytes(FileName);
//	
//	auto b = FileName.c_str();
//	size_t sz(std::strlen(b) + 1);
//	wchar_t* a = new wchar_t[sz];
//	size_t outSize;
//
//	mbstowcs_s(&outSize, a, sz, b, sz - 1);
//
//	//mbstowcs_s(,&sz,a,FileName.c_str(), sz);
//
//	//ZeroMemory(&a, sizeof(a));
//	ZeroMemory(&ofn, sizeof(ofn));
//	ofn.lStructSize = sizeof(ofn);
//	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
//	//ofn.lpstrFilter = L"(Text Files\0*.txt\0Any File\0*.*\0)";
//	ofn.lpstrFile = a;
//	ofn.nMaxFile = MAX_PATH;
//	ofn.lpstrTitle = _T("Select a File, yo!");
//	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
//
//	if (GetOpenFileName(&ofn))
//	{
//		std::cout << "You chose the file \"" << a << "\"\n";
//		auto a1 = std::wstring(a);
//		auto a2 = std::string(a1.begin(), a1.end());
//		FileName = a2.c_str();
//		drawInitialImage();
//	}
//	else
//	{
//		// All this stuff below is to tell you exactly how you messed up above. 
//		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
//		switch (CommDlgExtendedError())
//		{
//		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
//		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
//		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
//		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
//		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
//		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
//		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
//		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
//		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
//		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
//		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
//		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
//		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
//		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
//		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
//		default: std::cout << "You cancelled.\n";
//		}
//	}
//}

//static struct AnonFunc
//{
//	Fl_Check_Button* chkBtn;
//	void operator()() const { switchVisibility(chkBtn); }
//	
//} f;
#pragma endregion

#pragma region CallBackFunctions

static void caseCalc() {
	//RENEW IMG DATA WITH INITIAL
	tmpImg->copyTo(*outImg);

	if (chk_Median_enable->value())
		calcPre_MedianFiltr();

}

//DRAW EDITED IMAGE
static void drawNewImage(bool init_load = false) {
	if (tmpImg->dims > 0) {

		caseCalc();

		FinImage = Mat2FlRgbImg(*outImg, init_load);
		box_jpeg_image2->image(FinImage);
		window->redraw();
	}
}

static void sliderOddVal(Fl_Valuator* btn) {

	int oddNum = (int)btn->value();
	oddNum = oddNum % 2 == 1 ? oddNum : oddNum + 1;
	btn->value(oddNum);

	drawNewImage();
}

//DRAW INITIAL IMAGE
static void drawInitialImage() {

	//GET A COPY OF THE 
	cv::imread(FileName).copyTo(*tmpImg);

	//ONLY IF CONTAINING IMG DATA
	if ((*tmpImg).dims != 0) resizeImage(tmpImg);

	//INITIAL 
	InitImage = Mat2FlRgbImg(*tmpImg, true);
	box_jpeg_image->image(InitImage);

	//FINAL CALCULATE NEW IMAGE 
	drawNewImage(true);
	/*caseCalc();
	FinImage = Mat2FlRgbImg(*outImg, true);
	box_jpeg_image2->image(FinImage);*/

	//window->redraw();
}

static void addTreeItem() {
	auto found = FileName.find_last_of("/\\");
	auto name = FileName.substr(found + 1);
	auto path = FileName.substr(0, found);
	auto lastFolder = path.substr(path.find_last_of("/\\") + 1);
	auto trPrefs = new Fl_Tree_Prefs();

	//dirTreeFileNames.push_back(FileName); //add to the struct base
	dirTreeFileNamesList[DTNLstCap] = FileName;

	auto treeItem = new Fl_Tree_Item(Fl_Tree_Prefs()), pTreeItem = new Fl_Tree_Item(Fl_Tree_Prefs());

	pTreeItem->label(lastFolder.c_str());

	treeItem->label(name.c_str());
	//treeItem->user_data(&dirTreeFileNames.back()); //add to the treeItem the ptr addr
	treeItem->user_data(&dirTreeFileNamesList[DTNLstCap]); //add to the treeItem the ptr addr
	DTNLstCap++;

	//treeItem->parent(pTreeItem);

	//dirTree->add(pTreeItem, lastFolder.c_str()); //dirTree->add((lastFolder + '/' + name).c_str());
	dirTree->add(lastFolder.c_str());
	dirTree->add(lastFolder.c_str(), treeItem);

}

static bool isDirTreeFocused() {
	auto a = dirTree->get_item_focus();
	bool isfocused = a != NULL;
	return isfocused;
}

static void removeFileEntry() {
	if (isDirTreeFocused()) {
		auto a = dirTree->get_item_focus();
		auto parent = a->parent();

		if (a != dirTree->root()) {
			dirTree->remove(a);
			if (parent->children() == 0 && dirTree->root() != parent) dirTree->remove(parent);
		}
		
		dirTree->redraw();
	}
}
static void loadImgFromTree(Fl_Widget* w, void* data) {
	auto tree = (Fl_Tree*)w;
	switch (tree->callback_reason()) {
		case FL_TREE_REASON_SELECTED:
			auto item = (Fl_Tree_Item*)tree->callback_item();    // get selected item
			if (item->children() == 0 && item!= dirTree->root()) {
				//auto ptr = dirTree->get_item_focus()->user_data();
				auto ptr = item->user_data();
				auto filenamePTR = (std::string*)ptr;

				FileName = filenamePTR->c_str();
				drawInitialImage();
			}
	}
	/*if (isDirTreeFocused()) {


	}*/
}
//CHECK IF A NEW TREE ITEM CAN BE ADDED
static bool canAddTreeItem() {
	//bool canBeContained = dirTreeFileNames.capacity() < dirTreeMaxItemCount;
	bool canBeContained = DTNLstCap < dirTreeMaxItemCount;
	bool out = false;
	if (canBeContained) {
		/*for (auto i = 0; i < (short)dirTreeFileNames.capacity() - 1; i++)
		{
			if (dirTreeFileNames.at(i) == FileName)
				return false;
		}*/
		for (auto i = 0; i < DTNLstCap; i++)
		{
			if (dirTreeFileNamesList[DTNLstCap] == FileName)
				return false;
		}
		//IF LOOP FINISHED AND DID NOT FOUND ANY MATCHES
		return true;
	}
	//CANNOT BE CONTAINED
	return false;
}

static void chooseFile() {
	//fileChooser->show();
	auto filename = FileName == "" ? "C:\\Users\\GENERIC\\Pictures" : FileName.c_str();
	//FileName = std::string(fl_file_chooser("hello", "", filename, 0));
	//FileName = fl_file_chooser("hello", "", filename, 0);

	Fl_Native_File_Chooser fnfc = *nativeFileChooser;
	fnfc.title("Pick a file");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	//fnfc.filter("Text\t*.txt\n""C Files\t*.{cxx,h,c}");
	fnfc.directory("/var/tmp");           // default directory to use
	// Show native chooser
	switch (fnfc.show()) {
		case -1: printf("ERROR: %s\n", fnfc.errmsg());    break;  // ERROR
		case  1: printf("CANCEL\n");                      break;  // CANCEL
		default:
			printf("PICKED: %s\n", fnfc.filename());
			FileName = fnfc.filename();

			if (canAddTreeItem()) addTreeItem();

			drawInitialImage();
			break;  // FILE CHOSEN
	}
}

static void switchVisibility(Fl_Button* chk) {


	tmp_active = chk->value();
	if (tmp_active) {

		chk->parent()->child(0)->activate();
	}
	else {
		chk->parent()->child(0)->deactivate();
	}

	drawNewImage();
}
#pragma endregion


#endif


//static void resizeImage(cv::Mat* img);
//
//static void changeImgData();
//
//static void calcPre_MedianFiltr();
//
//static void drawImage2(Fl_Box* imgFrame);
//
//static void caseCalc();
//
//static void drawNewImage(bool init_load);
//
//static void sliderOddVal(Fl_Valuator* btn);
//
//static void drawInitialImage();
//
// void chooseFile();
//
// void switchVisibility(Fl_Button* chk);
//

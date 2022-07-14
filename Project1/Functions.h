#include "pch.h"
#include "structs.h"

#ifndef Funcs
#define Funcs

#pragma region static Variables
#define loadingTxt "Loading Image..."

//DECLARE WIDGETS
static Fl_Double_Window* window = (Fl_Double_Window*)0;
static Fl_Native_File_Chooser* nativeFileChooser = (Fl_Native_File_Chooser*)0;
static Fl_Box* box_jpeg_image2 = (Fl_Box*)0;
static Fl_Box* box_jpeg_image = (Fl_Box*)0;
static Fl_Button* btn_loadImg = (Fl_Button*)0;
static Fl_Value_Slider* sld_preMedian_ksize = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_postMedian_ksize = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_MorphOp_ksize2 = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_MorphOp_ksize1 = (Fl_Value_Slider*)0;
static Fl_Check_Button* chk_preMedian_enable = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_postMedian_enable = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_MorphOp_enable2 = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_MorphOp_enable1 = (Fl_Check_Button*)0;
static Fl_Tree* dirTree = (Fl_Tree*)0;

//Arrays
//static Fl_Value_Slider* sldArr[] = {sld_preMedian_ksize, sld_postMedian_ksize, sld_MorphOp_ksize2, sld_MorphOp_ksize1};
//static Fl_Check_Button* tmp_chkBtn;																  

static std::string tmp_groupName;
static bool tmp_active;
static const char* LoadingText = "Loading Image...";

//DECLARE IMAGE DATA ARRAY BUFFER
static bool newImg = true;
static const int maxNum = 10000 * 10000 * 3;
static Fl_RGB_Image* InitImage = (Fl_RGB_Image*)0;
static Fl_RGB_Image* FinImage = (Fl_RGB_Image*)0;
static cv::Mat* tmpImg = new cv::Mat();
static cv::Mat* outImg = new cv::Mat();
static unsigned char* tmpImgBuffer = (unsigned char*)0;
static std::string FileName;

//DECLARE IMG BOX DIMENSIONS
static short maxWidth = 600, maxHeight = 450, margin = 5;
static double boxAspRat = (double)maxWidth / (double)maxHeight;
//RESIZING VARIABLES
static short newWidth = maxWidth, newHeight = maxHeight;

//DIRECTORY TREE VARS
static const short dirTreeMaxItemCount = 20;
//static std::vector<std::string> dirTreeFileNames;
//static std::string* dirTreeFileNamesList = new std::string[dirTreeMaxItemCount];
//static unsigned char DTNLstCap = 0;
static StringList* dirStringList = new StringList(dirTreeMaxItemCount);


//MENU ITEMS
static Fl_Choice* drp_MorphOp_Shape2 = (Fl_Choice*)0;
static Fl_Choice* drp_MorphOp_Shape1 = (Fl_Choice*)0;
static Fl_Choice* drp_MorphOp_Op2 = (Fl_Choice*)0;
static Fl_Choice* drp_MorphOp_Op1 = (Fl_Choice*)0;

static Fl_Menu_Item menu_drp_MorphOp_Shape[] = {
 {"Rectangle", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Cross", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Ellipse", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

static Fl_Menu_Item menu_drp_MorphOp_Op[] = {
 {"Erode", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Dilate", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Open", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Close", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Gradient", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Tophat", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {"Blackhat", 0,  0, 0, 0, (uchar)FL_NORMAL_LABEL, 2, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

//LABELS
static Fl_Box* lblPreMedian = (Fl_Box*)0;
static Fl_Box* lblMorphOp1 = (Fl_Box*)0;
static Fl_Box* lblMorphOp2 = (Fl_Box*)0;
static Fl_Box* lblPostMedian = (Fl_Box*)0;

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

static void calc_MedianFiltr(Fl_Value_Slider* sld) {
	cv::medianBlur(*outImg, *outImg, sld->value());
}

/*u_char op, u_char shape, size_t kSize, size_t iterations = 1*/
static void calc_StructuralOp(Fl_Value_Slider* sld, Fl_Choice* drp1, Fl_Choice* drp2) {
	int kSize = sld->value();
	auto a = drp1->value();
	auto b = drp2->value();
	auto kernel = cv::getStructuringElement(a, cv::Size(kSize, kSize));
	cv::morphologyEx(*outImg, *outImg, b, kernel);
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

static void changeCBType(bool onrelease){
	Fl_Value_Slider* sldArr[] = { sld_preMedian_ksize, sld_postMedian_ksize, sld_MorphOp_ksize2, sld_MorphOp_ksize1 };
	for (size_t i = 0; i < 4; i++)
	{
		auto cbType = onrelease ? FL_WHEN_RELEASE : FL_WHEN_CHANGED;
		sldArr[i]->when(cbType);
	}
}

static void toggleCB(Fl_Button* btn) {
	bool a = btn->value();
	changeCBType(a);
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

////CHECK IF A NEW TREE ITEM CAN BE ADDED
//static bool canAddTreeItem() {
//	//bool canBeContained = dirTreeFileNames.capacity() < dirTreeMaxItemCount;
//	bool canBeContained = DTNLstCap < dirTreeMaxItemCount;
//	bool out = false;
//	if (canBeContained) {
//		/*for (auto i = 0; i < (short)dirTreeFileNames.capacity() - 1; i++)
//		{
//			if (dirTreeFileNames.at(i) == FileName)
//				return false;
//		}*/
//		for (auto i = 0; i < DTNLstCap; i++)
//		{
//			if (dirTreeFileNamesList[DTNLstCap] == FileName)
//				return false;
//		}
//		//IF LOOP FINISHED AND DID NOT FOUND ANY MATCHES
//		return true;
//	}
//	//CANNOT BE CONTAINED
//	return false;
//}

#pragma endregion

#pragma region CallBackFunctions

static void caseCalc() {
	//RENEW IMG DATA WITH INITIAL
	tmpImg->copyTo(*outImg);

	if (chk_preMedian_enable->value()) calc_MedianFiltr(sld_preMedian_ksize);
	if (chk_MorphOp_enable1->value()) calc_StructuralOp(sld_MorphOp_ksize1, drp_MorphOp_Shape1, drp_MorphOp_Op1);
	if (chk_MorphOp_enable2->value()) calc_StructuralOp(sld_MorphOp_ksize2, drp_MorphOp_Shape2, drp_MorphOp_Op2);
	if (chk_postMedian_enable->value()) calc_MedianFiltr(sld_postMedian_ksize);

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

static void clearImgViews() {
	box_jpeg_image->image((Fl_RGB_Image*)0);
	box_jpeg_image2->image((Fl_RGB_Image*)0);

	//FileName = ""; drawInitialImage();
	window->redraw();
}

/*
toggle: true, start interval
toggle: false, stop
*/
static void loadingInterval(bool toggle = false) {
	auto a = box_jpeg_image->parent();
	auto txt = toggle ? loadingTxt : NULL;
	if (toggle) {
		//	clearImgViews();
		//	a->deactivate();
		btn_loadImg->deactivate();
	}
	else {
		//	a->activate();
		btn_loadImg->activate();//REACTIVATE
	}
	box_jpeg_image->label(txt);
	box_jpeg_image2->label(txt);
	a->redraw();
}

static void addTreeItem() {
	auto found = FileName.find_last_of("/\\");
	auto name = FileName.substr(found + 1);
	auto path = FileName.substr(0, found);
	auto lastFolder = path.substr(path.find_last_of("/\\") + 1);


	auto FilenamePtr = dirStringList->add(FileName);

	auto treeItem = new Fl_Tree_Item(Fl_Tree_Prefs());
	treeItem->label(name.c_str());
	treeItem->user_data(FilenamePtr); //add to the treeItem the ptr addr

	dirTree->deselect_all();
	dirTree->add(lastFolder.c_str());
	dirTree->add(lastFolder.c_str(), treeItem)->select();

}

static void drawSelImg() {
	auto selItem = dirTree->first_selected_item();
	FileName = ((std::string*)selItem->user_data())[0];
	drawInitialImage();
}

//CHECK IF SPECIFIC LEVEL OF TREEITEM IS SELECTED
//isFileName: true if the treeitem represents a filename
static bool isDirTreeItemSelected(bool isFileName = false) {
	auto selItem = dirTree->first_selected_item();
	bool retVal = selItem != NULL;
	if (retVal)
		retVal = isFileName
		? (selItem->parent() != dirTree->root()) && (selItem != dirTree->root())
		: (selItem != dirTree->root());

	return retVal;
}

static void removeFileEntry() {
	//GET SELECTED ITEM
	auto selItem = dirTree->first_selected_item();
	if (isDirTreeItemSelected()) {

		bool isRoot = selItem == dirTree->root();
		if (!isRoot) {
			auto parent = selItem->parent();
			bool hasRootParent = parent == dirTree->root();

			selItem->prev()->select();
			//dirTree->prev(selItem)->select();
			if (!hasRootParent) dirStringList->remove(*(std::string*)selItem->user_data()); //Remove from the fileName List
			dirTree->remove(selItem); //Remove from the FlTree

			if (parent->children() == 0 && !hasRootParent) dirTree->remove(parent); //Remove parent if empty and not root

		}


		if (isDirTreeItemSelected(true)) drawSelImg();
		else { clearImgViews(); window->redraw(); }

	}
}

static void loadImgFromTree(Fl_Widget* w, void* data) {
	auto tree = (Fl_Tree*)w;
	switch (tree->callback_reason()) {
		case FL_TREE_REASON_SELECTED:
			auto item = (Fl_Tree_Item*)tree->callback_item(); // get selected item
			bool isRoot = item == dirTree->root();
			if (!isRoot && item->parent()->parent() == dirTree->root()) {
				FileName = ((std::string*)item->user_data())[0];
				drawInitialImage();
			}
	}
	/*if (isDirTreeFocused()) {


	}*/
}

static void chooseFile() {
	//auto filename = FileName == "" ? "C:\\Users\\%USERNAME%\\Pictures" : FileName.c_str();
	//DEACTIVATE TO PREVENT USER FROM DISRUPTING THE FOLLOWING OPERATIONS
	//BY OPENING NEW FILECHOOSER
	loadingInterval(true);

	auto fnfc = *nativeFileChooser;
	fnfc.title("Pick a file");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Images\t*.{png,tiff,svg,jpeg,jpg}");
	fnfc.directory("/var/tmp");           // default directory to use

	// Show native chooser
	switch (fnfc.show()) {
		case -1: printf("ERROR: %s\n", fnfc.errmsg());    break;  // ERROR
		case  1: printf("CANCEL\n");                      break;  // CANCEL
		default:
			printf("PICKED: %s\n", fnfc.filename());
			FileName = fnfc.filename();
			if (dirStringList->canBeAddedDistinct(FileName)) {
				addTreeItem();
				drawInitialImage();
			}
			break;  // FILE CHOSEN
	}

	loadingInterval();
}

static void switchVisibility(Fl_Button* chk) {

	tmp_active = chk->value();
	auto first_sibling = chk->parent()->child(0);
	if (tmp_active)
		first_sibling->activate();
	else
		first_sibling->deactivate();

	drawNewImage();
}

static void progrCb() {

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

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
static Fl_Tabs* tabPane = (Fl_Tabs*)0;

static Fl_Value_Slider* sld_preBilateral_d = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_preBilateral_sCol = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_preBilateral_sSpace = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_thrsh_low_1 = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_thrsh_low_2 = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_thrsh_high_1 = (Fl_Value_Slider*)0;
static Fl_Value_Slider* sld_thrsh_high_2 = (Fl_Value_Slider*)0;

static Fl_Check_Button* chk_preBilateral_enable = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_threshImg_enable_1 = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_threshImg_enable_2 = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_identification_1 = (Fl_Check_Button*)0;
static Fl_Check_Button* chk_identification_2 = (Fl_Check_Button*)0;


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
static Fl_Box* lblTotTime = (Fl_Box*)0;

static Fl_Box* lblPreBilat = (Fl_Box*)0;
static Fl_Box* lblthreshImg_1 = (Fl_Box*)0;
static Fl_Box* lblthreshImg_2 = (Fl_Box*)0;
static Fl_Box* lblIdentification_1 = (Fl_Box*)0;
static Fl_Box* lblIdentification_2 = (Fl_Box*)0;
//Timer
static Timer globalTimer, stepTimer;
static int totTimer;

//Tabs
static std::string tabNamesList[] = { "Ensemble 1", "Ensemble 2" };
static StringList* tabNames = new StringList(tabNamesList);
static ActiveTab currentTab = ActiveTab::Tab1;

//Randomizer
static cv::RNG rng(12345);


#pragma endregion

#pragma region HelperFunctions

static long long calcFuncTime(Timer t, void (*func)()) {
    t.start();
    func();
    t.end();
    auto a = t.getDuration();
    return a;
}

static void fillTimer(Fl_Box* box, Timer t = stepTimer, /*uchar subDivT = 3,uchar numCount = 6,*/ std::string concStr = " ms") {
    auto a = stepTimer.getDuration();
    totTimer += a;
    auto a1 = std::to_string((float)a / 1000).substr(0, 6);
    auto b = new std::string(a1 + concStr);
    //box->label(b.c_str());
    auto c = b->c_str();
    box->label(c);
}

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
//Credits: stereomatching
static inline void mix_channels(cv::Mat const& src, cv::Mat& dst, std::initializer_list<int> from_to)
{
    cv::mixChannels(&src, 1, &dst, 1, std::begin(from_to), from_to.size() / 2);
}

static void calc_FindthreshImg(Fl_Value_Slider* sld_thrshLow, Fl_Value_Slider* sld_thrshHigh) {
    uchar lowerBound = sld_thrshLow->value(), upperBound = sld_thrshHigh->value();
    //std::vector<std::vector<cv::Point>> contours;
    ////std::vector <cv::Point> contours;
    //std::vector<cv::Vec4i> hierarchy;
    ////Get the grayscale Image //cv::split
    //mix_channels(threshImg, hue, { 0, 0 });
    cv::Mat threshImg;

    cv::cvtColor(*outImg, threshImg, cv::COLOR_BGR2HSV);
    cv::inRange(threshImg, cv::Scalar(lowerBound, 0, 0), cv::Scalar(upperBound, 255, 255), threshImg);

    //cv::threshold(hue, hue, sld_thrshLow->value(), sld_thrshHigh->value(), cv::THRESH_BINARY);
    //threshImg(cv::Range(0, 0)); cv::Mat::zeros(outImg->size(), CV_8UC3);
    //cv::cvtColor(threshImg, *outImg, cv::COLOR_HSV2BGR);
    ////cv::threshold(threshImg, threshImg, sld_thrshLow->value(), 255, cv::THRESH_BINARY);
    //////cv::Canny(threshImg, threshImg, sld_thrshLow->value(), sld_thrshLow->value() * 2);
    ////cv::findContours(threshImg, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE
    ////cv::Mat drawing = cv::Mat::zeros(outImg->size(), CV_8UC3);
    //////cv::fillPoly(drawing, contours, cv::Scalar(230, 220, 200), cv::LINE_8);
    ////cv::fillPoly(drawing, contours, cv::Scalar(255,255,255));
    ////cv::bitwise_and(*outImg, drawing, *outImg);

    cv::cvtColor(threshImg, threshImg, cv::COLOR_GRAY2BGR);
    cv::bitwise_and(threshImg, *outImg, *outImg);
    //threshImg.copyTo(*outImg);
}

static void calc_BilatFiltr(Fl_Value_Slider* sld_d, Fl_Value_Slider* sld_sc, Fl_Value_Slider* sld_ss) {
    auto a = new cv::Mat(); outImg->copyTo(*a);

    cv::bilateralFilter(*a, *outImg, (int)sld_d->value(), sld_sc->value(), sld_ss->value());
}

static void calc_MedianFiltr(Fl_Value_Slider* sld) {
    cv::medianBlur(*outImg, *outImg, sld->value());
}

static void calc_identifyAndDraw() {
    auto gray = *(new cv::Mat());
    std::vector<std::vector<cv::Point>> contours;
    std::vector<size_t> foundIndxs;
    std::vector<cv::Rect> foundRects;

    cv::cvtColor(*outImg, gray, cv::COLOR_BGR2GRAY);
    cv::findContours(gray, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    
    std::vector<std::vector<cv::Point>> hull(contours.size());
    //Find the indexes of the appropriate size contours
    for (size_t i = 0; i < contours.size(); i++)
    {
        auto rect = cv::boundingRect(contours[i]);
        if (rect.height * rect.width > 5000) {
            foundIndxs.push_back(i);
            foundRects.push_back(rect);
        }
    }
    //DRAWING
    cv::drawContours(*outImg, contours, -1, cv::Scalar(90, 180, 120), 1);
    for (size_t i = 0; i < foundIndxs.size(); i++)
    {
        //GET THE INDEX OF THE FOUND CONTOURS
        auto j = foundIndxs[i];
        
        //FIND AND DRAW CONVEX HULL   
        cv::rectangle(*outImg, foundRects[i], cv::Scalar(180, 90, 90), 2);
        cv::convexHull(contours[j], hull[i]);
        cv::drawContours(*outImg, hull, i, cv::Scalar(90, 90, 180), 2);

        //DRAW INFO
        auto midPoint = size_t(foundRects[i].width / 2) + foundRects[i].x;
        auto margin = size_t(foundRects[i].width / 16);

        auto
            point1 = cv::Point(midPoint - margin, foundRects[i].y + 10),
            point2 = cv::Point(midPoint + margin, foundRects[i].y - size_t(foundRects[i].height / 5));
        auto stem_SimpleApprox = cv::Rect(point1, point2);

        cv::rectangle(*outImg, stem_SimpleApprox, cv::Scalar(90, 90, 100), -1);
        cv::putText(
            *outImg,
            "Around: (" + std::to_string(midPoint) + ',' + std::to_string(foundRects[i].y) + ')',
            point2, cv::FONT_HERSHEY_SIMPLEX, .5, cv::Scalar(200, 200, 220), 1 ,1
        );
    }
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
    if (mat.channels() == 3) {
        for (int i = 0; i < maxLength; i += 3) {
            auto i1 = i, i2 = i + 1, i3 = i + 2;
            tmpImgBuffer[i1] = mat.data[i3];
            tmpImgBuffer[i2] = mat.data[i2];
            tmpImgBuffer[i3] = mat.data[i1];
        }
    }
    else if(mat.channels()==1) {
        for (int i = 0; i < maxLength; i++) {
            tmpImgBuffer[i] = mat.data[i];
        }
    }


    return new Fl_RGB_Image(tmpImgBuffer, mat.cols, mat.rows);
}

static void drawImage2(Fl_Box* imgFrame) {
    //SET TO IMG TO FLBOX
    imgFrame->image(InitImage);
    //RELOAD GRAPHICS
    window->redraw();
}

static void changeCBType(bool onrelease) {
    Fl_Value_Slider* sldArr[] = {
        sld_preMedian_ksize, sld_postMedian_ksize,
        sld_MorphOp_ksize2, sld_MorphOp_ksize1,
        sld_preBilateral_d, sld_preBilateral_sCol, sld_preBilateral_sSpace,
        sld_thrsh_low_1, sld_thrsh_high_1,
        sld_thrsh_low_2, sld_thrsh_high_2
    };

    uchar sz = sizeof(sldArr) / 4;
    for (size_t i = 0; i < sz; i++)
    {
        auto cbType = onrelease ? FL_WHEN_RELEASE : FL_WHEN_CHANGED;
        sldArr[i]->when(cbType);
    }
}

static void toggleCB(Fl_Button* btn) {
    bool a = btn->value();
    changeCBType(a);
}

std::string getTabName(ActiveTab tab) {
    switch (tab)
    {
        case Tab1:
            return "Ensebmle 1";
        case Tab2:
            return "Ensebmle 2";
        default:
            break;
    }
}
#pragma endregion

#pragma region CallBackFunctions

static void caseCalc() {
    //RENEW IMG DATA WITH INITIAL
    tmpImg->copyTo(*outImg);
    totTimer = 0;

    switch (currentTab)
    {
        case Tab1:
            if (chk_preMedian_enable->value()) { stepTimer.start(); calc_MedianFiltr(sld_preMedian_ksize); stepTimer.end(); fillTimer(lblPreMedian); }
            if (chk_MorphOp_enable1->value()) { stepTimer.start(); calc_StructuralOp(sld_MorphOp_ksize1, drp_MorphOp_Shape1, drp_MorphOp_Op1); stepTimer.end(); fillTimer(lblMorphOp1); }
            if (chk_MorphOp_enable2->value()) { stepTimer.start(); calc_StructuralOp(sld_MorphOp_ksize2, drp_MorphOp_Shape2, drp_MorphOp_Op2); stepTimer.end(); fillTimer(lblMorphOp2); }
            if (chk_postMedian_enable->value()) { stepTimer.start(); calc_MedianFiltr(sld_postMedian_ksize); stepTimer.end(); fillTimer(lblPostMedian); }
            if (chk_threshImg_enable_1->value()) { stepTimer.start(); calc_FindthreshImg(sld_thrsh_low_1, sld_thrsh_high_1); stepTimer.end(); fillTimer(lblthreshImg_1); }

            if (chk_identification_1->value()) { stepTimer.start(); calc_identifyAndDraw(); stepTimer.end(); fillTimer(lblIdentification_1); }

            break;
        case Tab2:
            if (chk_preBilateral_enable->value()) { stepTimer.start(); calc_BilatFiltr(sld_preBilateral_d, sld_preBilateral_sCol, sld_preBilateral_sSpace); stepTimer.end(); fillTimer(lblPreBilat); }
            if (chk_threshImg_enable_2->value()) { stepTimer.start(); calc_FindthreshImg(sld_thrsh_low_2, sld_thrsh_high_2); stepTimer.end(); fillTimer(lblthreshImg_2); }

            if (chk_identification_2->value()) { stepTimer.start(); calc_identifyAndDraw(); stepTimer.end(); fillTimer(lblIdentification_1); }

            break;
    }

    float ms = (float)totTimer / 1000;
    float s = ms / 1000;
    size_t fps = 1 / s;
    lblTotTime->label((
        new std::string(std::to_string(ms).substr(0, 5) + " ms | " +
            std::to_string(s).substr(0, 5) + " s | " +
            std::to_string(fps) + " fps"
        ))->c_str());
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
    //Get the timer label element 
    auto timerLabel = (Fl_Box*)chk->parent()->parent()->child(2);
    if (tmp_active) {
        first_sibling->activate();
        chk->parent()->parent()->child(1)->activate();
        timerLabel->activate();
    }
    else {
        first_sibling->deactivate();
        chk->parent()->parent()->child(1)->deactivate();
        timerLabel->label("0 ms");
        timerLabel->deactivate();
    }
    drawNewImage();
}

static void tabChange(Fl_Tabs* a) {
    auto str = a->value()->label();

    if (str == "Ensemble 1") currentTab = ActiveTab::Tab1;
    else if (str == "Ensemble 2") currentTab = ActiveTab::Tab2;

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

// generated by Fast Light User Interface Designer (fluid) version 1.0308

#include "Functions.h "/*

static Fl_Double_Window *window=(Fl_Double_Window *)0;

static Fl_Box *box_jpeg_image=(Fl_Box *)0;

static Fl_Box *box_jpeg_image2=(Fl_Box *)0;

static Fl_Value_Slider *sld_Median_ksize=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_Median_enable=(Fl_Check_Button *)0;

static Fl_Tree *dirTree=(Fl_Tree *)0;

static Fl_Button *btn_loadImg=(Fl_Button *)0;

*/
int __stdcall WinMain(__in HINSTANCE hInstance,__in_opt HINSTANCE hPrevInstance,__in LPSTR lpCmdLine,__in int nShowCmd) {
  Fl::scheme("gtk+");
  //Fl::scheme("gleam");
  //Fl::scheme("plastic");
  	
  Fl::background(238, 240, 241);
  { window = new Fl_Double_Window(1378, 988, "asd");
    window->box(FL_DOWN_BOX);
    window->align(Fl_Align(FL_ALIGN_CLIP|FL_ALIGN_INSIDE));
    { Fl_Group* o = new Fl_Group(720, 14, 640, 951);
      o->box(FL_PLASTIC_DOWN_BOX);
      o->color((Fl_Color)46);
      o->labelsize(24);
      { box_jpeg_image = new Fl_Box(740, 30, 600, 450);
        box_jpeg_image->box(FL_PLASTIC_DOWN_BOX);
        box_jpeg_image->size(box_jpeg_image->w() + margin, box_jpeg_image->h() + margin);
      } // Fl_Box* box_jpeg_image
      { box_jpeg_image2 = new Fl_Box(740, 495, 600, 450);
        box_jpeg_image2->box(FL_PLASTIC_DOWN_BOX);
        box_jpeg_image2->size(box_jpeg_image2->w() + margin, box_jpeg_image2->h() + margin);
      } // Fl_Box* box_jpeg_image2
      { Fl_Box* o = new Fl_Box(740, 30, 155, 25, "Initial Image");
        o->box(FL_PLASTIC_THIN_UP_BOX);
        o->color(FL_BACKGROUND2_COLOR);
        o->labelfont(3);
        o->labelsize(18);
      } // Fl_Box* o
      { Fl_Box* o = new Fl_Box(740, 495, 155, 25, "Final Image");
        o->box(FL_PLASTIC_THIN_UP_BOX);
        o->color(FL_BACKGROUND2_COLOR);
        o->labelfont(3);
        o->labelsize(18);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    { Fl_Tabs* o = new Fl_Tabs(20, 400, 680, 565);
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)48);
      { Fl_Group* o = new Fl_Group(20, 440, 680, 525, "Group1");
        o->box(FL_PLASTIC_DOWN_BOX);
        o->color((Fl_Color)46);
        { Fl_Tile* o = new Fl_Tile(40, 459, 255, 119);
          o->box(FL_PLASTIC_DOWN_BOX);
          o->labelsize(24);
          o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
          { Fl_Pack* o = new Fl_Pack(50, 490, 235, 40);
            o->labelsize(18);
            { sld_Median_ksize = new Fl_Value_Slider(50, 490, 235, 25, "Kernel Size:");
              sld_Median_ksize->type(5);
              sld_Median_ksize->box(FL_PLASTIC_DOWN_BOX);
              sld_Median_ksize->color(FL_DARK1);
              sld_Median_ksize->selection_color((Fl_Color)14);
              sld_Median_ksize->labelfont(2);
              sld_Median_ksize->labelsize(18);
              sld_Median_ksize->minimum(1);
              sld_Median_ksize->maximum(23);
              sld_Median_ksize->step(1);
              sld_Median_ksize->value(1);
              sld_Median_ksize->textsize(18);
              sld_Median_ksize->callback((Fl_Callback*)sliderOddVal);
              sld_Median_ksize->align(Fl_Align(FL_ALIGN_TOP_LEFT));
              sld_Median_ksize->when(FL_WHEN_RELEASE);
            } // Fl_Value_Slider* sld_Median_ksize
            o->end();
          } // Fl_Pack* o
          { chk_Median_enable = new Fl_Check_Button(145, 536, 140, 32, "Median Blur");
            chk_Median_enable->box(FL_PLASTIC_DOWN_BOX);
            chk_Median_enable->down_box(FL_PLASTIC_DOWN_BOX);
            chk_Median_enable->value(1);
            chk_Median_enable->labelfont(2);
            chk_Median_enable->labelsize(20);
            chk_Median_enable->callback((Fl_Callback*)switchVisibility);
            chk_Median_enable->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
          } // Fl_Check_Button* chk_Median_enable
          o->end();
        } // Fl_Tile* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(20, 440, 680, 525, "Group2");
        o->box(FL_PLASTIC_DOWN_BOX);
        o->color(FL_DARK1);
        o->hide();
        o->end();
      } // Fl_Group* o
      o->end();
    } // Fl_Tabs* o
    { Fl_Group* o = new Fl_Group(20, 16, 680, 364);
      o->box(FL_PLASTIC_DOWN_BOX);
      o->color((Fl_Color)46);
      { dirTree = new Fl_Tree(40, 39, 330, 278);
        dirTree->box(FL_PLASTIC_DOWN_BOX);
        dirTree->labelsize(20);
        dirTree->callback((Fl_Callback*)loadImgFromTree);
        dirTree->when(FL_WHEN_RELEASE);
        dirTree->root_label("Loaded Images");
      } // Fl_Tree* dirTree
      { btn_loadImg = new Fl_Button(520, 330, 160, 30, "Load New Image");
        btn_loadImg->box(FL_PLASTIC_THIN_UP_BOX);
        btn_loadImg->down_box(FL_PLASTIC_THIN_DOWN_BOX);
        btn_loadImg->labelsize(18);
        btn_loadImg->callback((Fl_Callback*)chooseFile);
      } // Fl_Button* btn_loadImg
      { Fl_Button* o = new Fl_Button(40, 330, 115, 30, "Delete entry");
        o->box(FL_PLASTIC_THIN_UP_BOX);
        o->shortcut(0xffff);
        o->down_box(FL_PLASTIC_THIN_DOWN_BOX);
        o->labelfont(2);
        o->labelsize(18);
        o->callback((Fl_Callback*)removeFileEntry);
      } // Fl_Button* o
      o->end();
    } // Fl_Group* o
    window->set_non_modal();
    window->end();
  } // Fl_Double_Window* window
  {
  nativeFileChooser = new Fl_Native_File_Chooser();
  }
  //window->end();
  window->show();
  
  return Fl::run();
}

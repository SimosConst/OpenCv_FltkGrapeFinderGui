// generated by Fast Light User Interface Designer (fluid) version 1.0308

#include "Functions.h "/*

static Fl_Double_Window *window=(Fl_Double_Window *)0;

static Fl_Box *box_jpeg_image=(Fl_Box *)0;

static Fl_Box *box_jpeg_image2=(Fl_Box *)0;

static Fl_Tabs *tabPane=(Fl_Tabs *)0;

static Fl_Value_Slider *sld_preMedian_ksize=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_preMedian_enable=(Fl_Check_Button *)0;

static Fl_Box *lblPreMedian=(Fl_Box *)0;

static Fl_Value_Slider *sld_MorphOp_ksize1=(Fl_Value_Slider *)0;

static Fl_Choice *drp_MorphOp_Shape1=(Fl_Choice *)0;

static Fl_Choice *drp_MorphOp_Op1=(Fl_Choice *)0;

static Fl_Check_Button *chk_MorphOp_enable1=(Fl_Check_Button *)0;

static Fl_Box *lblMorphOp1=(Fl_Box *)0;

static Fl_Value_Slider *sld_MorphOp_ksize2=(Fl_Value_Slider *)0;

static Fl_Choice *drp_MorphOp_Shape2=(Fl_Choice *)0;

static Fl_Choice *drp_MorphOp_Op2=(Fl_Choice *)0;

static Fl_Check_Button *chk_MorphOp_enable2=(Fl_Check_Button *)0;

static Fl_Box *lblMorphOp2=(Fl_Box *)0;

static Fl_Value_Slider *sld_postMedian_ksize=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_postMedian_enable=(Fl_Check_Button *)0;

static Fl_Box *lblPostMedian=(Fl_Box *)0;

static Fl_Value_Slider *sld_thrsh_low_1=(Fl_Value_Slider *)0;

static Fl_Value_Slider *sld_thrsh_high_1=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_threshImg_enable_1=(Fl_Check_Button *)0;

static Fl_Box *lblthreshImg_1=(Fl_Box *)0;

static Fl_Check_Button *chk_identification_1=(Fl_Check_Button *)0;

static Fl_Box *lblIdentification_1=(Fl_Box *)0;

static Fl_Value_Slider *sld_preBilateral_d=(Fl_Value_Slider *)0;

static Fl_Value_Slider *sld_preBilateral_sCol=(Fl_Value_Slider *)0;

static Fl_Value_Slider *sld_preBilateral_sSpace=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_preBilateral_enable=(Fl_Check_Button *)0;

static Fl_Box *lblPreBilat=(Fl_Box *)0;

static Fl_Value_Slider *sld_thrsh_low_2=(Fl_Value_Slider *)0;

static Fl_Value_Slider *sld_thrsh_high_2=(Fl_Value_Slider *)0;

static Fl_Check_Button *chk_threshImg_enable_2=(Fl_Check_Button *)0;

static Fl_Box *lblthreshImg_2=(Fl_Box *)0;

static Fl_Check_Button *chk_identification_2=(Fl_Check_Button *)0;

static Fl_Box *lblIdentification_2=(Fl_Box *)0;

static Fl_Tree *dirTree=(Fl_Tree *)0;

static Fl_Button *btn_loadImg=(Fl_Button *)0;

Fl_Box *lblTotTime=(Fl_Box *)0;

*/
int __stdcall WinMain(__in HINSTANCE hInstance,__in_opt HINSTANCE hPrevInstance,__in LPSTR lpCmdLine,__in int nShowCmd) {
  Fl::scheme("gtk+");
  //Fl::scheme("gleam");
  //Fl::scheme("plastic");
  	
  Fl::background(238, 240, 241);
  { window = new Fl_Double_Window(1378, 993, "Simple Grape Stemm Visual Aproximator");
    window->box(FL_PLASTIC_UP_BOX);
    window->align(Fl_Align(FL_ALIGN_CLIP|FL_ALIGN_INSIDE));
    { Fl_Group* o = new Fl_Group(720, 14, 640, 951);
      o->box(FL_PLASTIC_DOWN_BOX);
      o->color((Fl_Color)46);
      o->labelsize(24);
      { box_jpeg_image = new Fl_Box(740, 30, 600, 450);
        box_jpeg_image->box(FL_PLASTIC_DOWN_BOX);
        box_jpeg_image->labelfont(3);
        box_jpeg_image->labelsize(26);
        box_jpeg_image->labelcolor((Fl_Color)30);
        box_jpeg_image->align(Fl_Align(512|FL_ALIGN_INSIDE));
        box_jpeg_image->size(box_jpeg_image->w() + margin, box_jpeg_image->h() + margin);
      } // Fl_Box* box_jpeg_image
      { box_jpeg_image2 = new Fl_Box(740, 495, 600, 450);
        box_jpeg_image2->box(FL_PLASTIC_DOWN_BOX);
        box_jpeg_image2->labelfont(3);
        box_jpeg_image2->labelsize(26);
        box_jpeg_image2->labelcolor((Fl_Color)30);
        box_jpeg_image2->align(Fl_Align(512|FL_ALIGN_INSIDE));
        box_jpeg_image2->size(box_jpeg_image2->w() + margin, box_jpeg_image2->h() + margin);
      } // Fl_Box* box_jpeg_image2
      { Fl_Box* o = new Fl_Box(740, 30, 155, 25, "Initial Image");
        o->box(FL_PLASTIC_THIN_DOWN_BOX);
        o->color(FL_BACKGROUND2_COLOR);
        o->labelfont(3);
        o->labelsize(18);
      } // Fl_Box* o
      { Fl_Box* o = new Fl_Box(740, 495, 155, 25, "Final Image");
        o->box(FL_PLASTIC_THIN_DOWN_BOX);
        o->color(FL_BACKGROUND2_COLOR);
        o->labelfont(3);
        o->labelsize(18);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    { tabPane = new Fl_Tabs(20, 404, 685, 561);
      tabPane->box(FL_PLASTIC_THIN_UP_BOX);
      tabPane->color((Fl_Color)48);
      tabPane->callback((Fl_Callback*)tabChange);
      tabPane->when(FL_WHEN_CHANGED);
      { Fl_Scroll* o = new Fl_Scroll(22, 404, 680, 510, "Ensemble 1");
        o->type(2);
        o->box(FL_PLASTIC_DOWN_BOX);
        o->color(FL_DARK1);
        o->labelsize(18);
        { Fl_Group* o = new Fl_Group(34, 414, 656, 120);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(234, 414, 446, 118);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(237, 419, 431, 71);
              o->labelsize(18);
              { sld_preMedian_ksize = new Fl_Value_Slider(242, 449, 426, 30, "Kernel Size:");
                sld_preMedian_ksize->type(1);
                sld_preMedian_ksize->box(FL_PLASTIC_DOWN_BOX);
                sld_preMedian_ksize->selection_color((Fl_Color)14);
                sld_preMedian_ksize->labelfont(2);
                sld_preMedian_ksize->labelsize(18);
                sld_preMedian_ksize->minimum(1);
                sld_preMedian_ksize->maximum(50);
                sld_preMedian_ksize->step(1);
                sld_preMedian_ksize->value(3);
                sld_preMedian_ksize->textsize(18);
                sld_preMedian_ksize->callback((Fl_Callback*)sliderOddVal);
                sld_preMedian_ksize->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_preMedian_ksize->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_preMedian_ksize
              o->end();
            } // Fl_Group* o
            { chk_preMedian_enable = new Fl_Check_Button(242, 492, 199, 30, "Median Blur (Pre)");
              chk_preMedian_enable->box(FL_PLASTIC_DOWN_BOX);
              chk_preMedian_enable->down_box(FL_PLASTIC_DOWN_BOX);
              chk_preMedian_enable->value(1);
              chk_preMedian_enable->labelfont(2);
              chk_preMedian_enable->labelsize(20);
              chk_preMedian_enable->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_preMedian_enable
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(34, 415, 190, 30, "1. Initial bluring");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblPreMedian = new Fl_Box(124, 504, 100, 30, "0 ms");
            lblPreMedian->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblPreMedian->color(FL_DARK2);
            lblPreMedian->labelfont(3);
            lblPreMedian->labelsize(16);
            lblPreMedian->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblPreMedian
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(34, 543, 656, 148);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(234, 543, 446, 140);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(238, 543, 430, 140);
              o->labelsize(18);
              { sld_MorphOp_ksize1 = new Fl_Value_Slider(506, 637, 162, 31, "Kernel Size:");
                sld_MorphOp_ksize1->type(1);
                sld_MorphOp_ksize1->box(FL_PLASTIC_DOWN_BOX);
                sld_MorphOp_ksize1->selection_color((Fl_Color)14);
                sld_MorphOp_ksize1->labelfont(2);
                sld_MorphOp_ksize1->labelsize(18);
                sld_MorphOp_ksize1->minimum(1);
                sld_MorphOp_ksize1->maximum(50);
                sld_MorphOp_ksize1->step(1);
                sld_MorphOp_ksize1->value(7);
                sld_MorphOp_ksize1->textsize(18);
                sld_MorphOp_ksize1->callback((Fl_Callback*)drawNewImage);
                sld_MorphOp_ksize1->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_MorphOp_ksize1->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_MorphOp_ksize1
              { drp_MorphOp_Shape1 = new Fl_Choice(242, 575, 209, 30, "Morphology Shape");
                drp_MorphOp_Shape1->box(FL_PLASTIC_THIN_UP_BOX);
                drp_MorphOp_Shape1->down_box(FL_PLASTIC_THIN_DOWN_BOX);
                drp_MorphOp_Shape1->selection_color((Fl_Color)14);
                drp_MorphOp_Shape1->labelfont(2);
                drp_MorphOp_Shape1->labelsize(18);
                drp_MorphOp_Shape1->textsize(18);
                drp_MorphOp_Shape1->callback((Fl_Callback*)drawNewImage);
                drp_MorphOp_Shape1->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                drp_MorphOp_Shape1->menu(menu_drp_MorphOp_Shape);
                drp_MorphOp_Shape1->value(2);
              } // Fl_Choice* drp_MorphOp_Shape1
              { drp_MorphOp_Op1 = new Fl_Choice(466, 575, 202, 30, "Morphology Operation");
                drp_MorphOp_Op1->box(FL_PLASTIC_THIN_UP_BOX);
                drp_MorphOp_Op1->down_box(FL_PLASTIC_THIN_DOWN_BOX);
                drp_MorphOp_Op1->selection_color((Fl_Color)14);
                drp_MorphOp_Op1->labelfont(2);
                drp_MorphOp_Op1->labelsize(18);
                drp_MorphOp_Op1->textsize(18);
                drp_MorphOp_Op1->callback((Fl_Callback*)drawNewImage);
                drp_MorphOp_Op1->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                drp_MorphOp_Op1->menu(menu_drp_MorphOp_Op);
                drp_MorphOp_Op1->value(3);
              } // Fl_Choice* drp_MorphOp_Op1
              o->end();
            } // Fl_Group* o
            { chk_MorphOp_enable1 = new Fl_Check_Button(238, 636, 256, 32, "Morphology Operation 1");
              chk_MorphOp_enable1->box(FL_PLASTIC_DOWN_BOX);
              chk_MorphOp_enable1->down_box(FL_PLASTIC_DOWN_BOX);
              chk_MorphOp_enable1->value(1);
              chk_MorphOp_enable1->labelfont(2);
              chk_MorphOp_enable1->labelsize(20);
              chk_MorphOp_enable1->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_MorphOp_enable1
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(34, 543, 188, 54, "2. First Morphology operation");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblMorphOp1 = new Fl_Box(121, 653, 99, 30, "0 ms");
            lblMorphOp1->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblMorphOp1->color(FL_DARK2);
            lblMorphOp1->labelfont(3);
            lblMorphOp1->labelsize(16);
            lblMorphOp1->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblMorphOp1
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(34, 691, 656, 135);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(234, 691, 446, 135);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(237, 691, 431, 135);
              o->labelsize(18);
              { sld_MorphOp_ksize2 = new Fl_Value_Slider(506, 785, 162, 31, "Kernel Size:");
                sld_MorphOp_ksize2->type(1);
                sld_MorphOp_ksize2->box(FL_PLASTIC_DOWN_BOX);
                sld_MorphOp_ksize2->selection_color((Fl_Color)14);
                sld_MorphOp_ksize2->labelfont(2);
                sld_MorphOp_ksize2->labelsize(18);
                sld_MorphOp_ksize2->minimum(1);
                sld_MorphOp_ksize2->maximum(50);
                sld_MorphOp_ksize2->step(1);
                sld_MorphOp_ksize2->value(3);
                sld_MorphOp_ksize2->textsize(18);
                sld_MorphOp_ksize2->callback((Fl_Callback*)drawNewImage);
                sld_MorphOp_ksize2->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_MorphOp_ksize2->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_MorphOp_ksize2
              { drp_MorphOp_Shape2 = new Fl_Choice(242, 723, 209, 30, "Morphology Shape");
                drp_MorphOp_Shape2->box(FL_PLASTIC_THIN_UP_BOX);
                drp_MorphOp_Shape2->down_box(FL_PLASTIC_THIN_DOWN_BOX);
                drp_MorphOp_Shape2->selection_color((Fl_Color)14);
                drp_MorphOp_Shape2->labelfont(2);
                drp_MorphOp_Shape2->labelsize(18);
                drp_MorphOp_Shape2->textsize(18);
                drp_MorphOp_Shape2->callback((Fl_Callback*)drawNewImage);
                drp_MorphOp_Shape2->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                drp_MorphOp_Shape2->menu(menu_drp_MorphOp_Shape);
                drp_MorphOp_Shape2->value(2);
              } // Fl_Choice* drp_MorphOp_Shape2
              { drp_MorphOp_Op2 = new Fl_Choice(466, 723, 202, 30, "Morphology Operation");
                drp_MorphOp_Op2->box(FL_PLASTIC_THIN_UP_BOX);
                drp_MorphOp_Op2->down_box(FL_PLASTIC_THIN_DOWN_BOX);
                drp_MorphOp_Op2->selection_color((Fl_Color)14);
                drp_MorphOp_Op2->labelfont(2);
                drp_MorphOp_Op2->labelsize(18);
                drp_MorphOp_Op2->textsize(18);
                drp_MorphOp_Op2->callback((Fl_Callback*)drawNewImage);
                drp_MorphOp_Op2->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                drp_MorphOp_Op2->menu(menu_drp_MorphOp_Op);
                drp_MorphOp_Op2->value(3);
              } // Fl_Choice* drp_MorphOp_Op2
              o->end();
            } // Fl_Group* o
            { chk_MorphOp_enable2 = new Fl_Check_Button(237, 784, 259, 32, "Morphology Operation 2");
              chk_MorphOp_enable2->box(FL_PLASTIC_DOWN_BOX);
              chk_MorphOp_enable2->down_box(FL_PLASTIC_DOWN_BOX);
              chk_MorphOp_enable2->value(1);
              chk_MorphOp_enable2->labelfont(2);
              chk_MorphOp_enable2->labelsize(20);
              chk_MorphOp_enable2->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_MorphOp_enable2
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(35, 691, 187, 55, "3. Second Morphology operation");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblMorphOp2 = new Fl_Box(123, 796, 99, 30, "0 ms");
            lblMorphOp2->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblMorphOp2->color(FL_DARK2);
            lblMorphOp2->labelfont(3);
            lblMorphOp2->labelsize(16);
            lblMorphOp2->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblMorphOp2
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(34, 836, 656, 110);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(232, 836, 448, 110);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(232, 840, 436, 66);
              o->labelsize(18);
              { sld_postMedian_ksize = new Fl_Value_Slider(242, 868, 426, 30, "Kernel Size:");
                sld_postMedian_ksize->type(1);
                sld_postMedian_ksize->box(FL_PLASTIC_DOWN_BOX);
                sld_postMedian_ksize->color(FL_DARK1);
                sld_postMedian_ksize->selection_color((Fl_Color)14);
                sld_postMedian_ksize->labelfont(2);
                sld_postMedian_ksize->labelsize(18);
                sld_postMedian_ksize->minimum(1);
                sld_postMedian_ksize->maximum(50);
                sld_postMedian_ksize->step(1);
                sld_postMedian_ksize->value(3);
                sld_postMedian_ksize->textsize(18);
                sld_postMedian_ksize->callback((Fl_Callback*)sliderOddVal);
                sld_postMedian_ksize->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_postMedian_ksize->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_postMedian_ksize
              o->end();
            } // Fl_Group* o
            { chk_postMedian_enable = new Fl_Check_Button(240, 908, 203, 33, "Median Blur (Post)");
              chk_postMedian_enable->box(FL_PLASTIC_DOWN_BOX);
              chk_postMedian_enable->down_box(FL_PLASTIC_DOWN_BOX);
              chk_postMedian_enable->value(1);
              chk_postMedian_enable->labelfont(2);
              chk_postMedian_enable->labelsize(20);
              chk_postMedian_enable->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_postMedian_enable
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(40, 836, 189, 25, "4. Final bluring");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblPostMedian = new Fl_Box(130, 916, 99, 30, "0 ms");
            lblPostMedian->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblPostMedian->color(FL_DARK2);
            lblPostMedian->labelfont(3);
            lblPostMedian->labelsize(16);
            lblPostMedian->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblPostMedian
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(34, 954, 656, 166);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(236, 954, 444, 166);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(237, 964, 431, 123);
              o->labelsize(18);
              { sld_thrsh_low_1 = new Fl_Value_Slider(245, 964, 423, 32, "Lower Threshold");
                sld_thrsh_low_1->tooltip("The lower value threshold");
                sld_thrsh_low_1->type(3);
                sld_thrsh_low_1->box(FL_PLASTIC_THIN_DOWN_BOX);
                sld_thrsh_low_1->selection_color((Fl_Color)14);
                sld_thrsh_low_1->labelfont(2);
                sld_thrsh_low_1->labelsize(18);
                sld_thrsh_low_1->maximum(255);
                sld_thrsh_low_1->step(1);
                sld_thrsh_low_1->value(25);
                sld_thrsh_low_1->slider_size(1);
                sld_thrsh_low_1->textfont(2);
                sld_thrsh_low_1->textsize(18);
                sld_thrsh_low_1->textcolor(FL_GRAY0);
                sld_thrsh_low_1->callback((Fl_Callback*)drawNewImage);
                sld_thrsh_low_1->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
                sld_thrsh_low_1->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_thrsh_low_1
              { sld_thrsh_high_1 = new Fl_Value_Slider(245, 1028, 423, 32, "High Threshold");
                sld_thrsh_high_1->tooltip("The lower value threshold");
                sld_thrsh_high_1->type(3);
                sld_thrsh_high_1->box(FL_PLASTIC_THIN_DOWN_BOX);
                sld_thrsh_high_1->selection_color((Fl_Color)14);
                sld_thrsh_high_1->labelfont(2);
                sld_thrsh_high_1->labelsize(18);
                sld_thrsh_high_1->minimum(1);
                sld_thrsh_high_1->maximum(255);
                sld_thrsh_high_1->step(1);
                sld_thrsh_high_1->value(255);
                sld_thrsh_high_1->slider_size(1);
                sld_thrsh_high_1->textfont(2);
                sld_thrsh_high_1->textsize(18);
                sld_thrsh_high_1->textcolor(FL_GRAY0);
                sld_thrsh_high_1->callback((Fl_Callback*)drawNewImage);
                sld_thrsh_high_1->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
                sld_thrsh_high_1->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_thrsh_high_1
              o->end();
            } // Fl_Group* o
            { chk_threshImg_enable_1 = new Fl_Check_Button(245, 1083, 159, 30, "Hue Isolation");
              chk_threshImg_enable_1->box(FL_PLASTIC_DOWN_BOX);
              chk_threshImg_enable_1->down_box(FL_PLASTIC_DOWN_BOX);
              chk_threshImg_enable_1->value(1);
              chk_threshImg_enable_1->labelfont(2);
              chk_threshImg_enable_1->labelsize(20);
              chk_threshImg_enable_1->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_threshImg_enable_1
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(42, 954, 190, 30, "5. Hue thresholding ");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblthreshImg_1 = new Fl_Box(133, 1090, 100, 30, "0 ms");
            lblthreshImg_1->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblthreshImg_1->color(FL_DARK2);
            lblthreshImg_1->labelfont(3);
            lblthreshImg_1->labelsize(16);
            lblthreshImg_1->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblthreshImg_1
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(34, 1130, 656, 62);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(236, 1130, 444, 62);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(260, 1130, 15, 0);
              o->labelsize(18);
              o->end();
            } // Fl_Group* o
            { chk_identification_1 = new Fl_Check_Button(239, 1145, 157, 33, "Identification");
              chk_identification_1->box(FL_PLASTIC_DOWN_BOX);
              chk_identification_1->down_box(FL_PLASTIC_DOWN_BOX);
              chk_identification_1->value(1);
              chk_identification_1->labelfont(2);
              chk_identification_1->labelsize(20);
              chk_identification_1->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_identification_1
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(40, 1130, 191, 25, "6. Identification");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblIdentification_1 = new Fl_Box(131, 1165, 100, 27, "0 ms");
            lblIdentification_1->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblIdentification_1->color(FL_DARK2);
            lblIdentification_1->labelfont(3);
            lblIdentification_1->labelsize(16);
            lblIdentification_1->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblIdentification_1
          o->end();
        } // Fl_Group* o
        o->end();
      } // Fl_Scroll* o
      { Fl_Scroll* o = new Fl_Scroll(25, 404, 680, 394, "Ensemble 2");
        o->type(2);
        o->box(FL_PLASTIC_DOWN_BOX);
        o->color(FL_DARK1);
        o->labelsize(18);
        o->hide();
        { Fl_Group* o = new Fl_Group(28, 409, 658, 120);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(236, 409, 440, 118);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(241, 414, 435, 71);
              o->labelsize(18);
              { sld_preBilateral_d = new Fl_Value_Slider(246, 444, 124, 30, "Pixel diameter:");
                sld_preBilateral_d->type(1);
                sld_preBilateral_d->box(FL_PLASTIC_DOWN_BOX);
                sld_preBilateral_d->selection_color((Fl_Color)14);
                sld_preBilateral_d->labelfont(2);
                sld_preBilateral_d->labelsize(18);
                sld_preBilateral_d->minimum(1);
                sld_preBilateral_d->maximum(50);
                sld_preBilateral_d->step(1);
                sld_preBilateral_d->value(15);
                sld_preBilateral_d->textsize(18);
                sld_preBilateral_d->callback((Fl_Callback*)drawNewImage);
                sld_preBilateral_d->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_preBilateral_d->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_preBilateral_d
              { sld_preBilateral_sCol = new Fl_Value_Slider(386, 444, 133, 30, "Sigma Color:");
                sld_preBilateral_sCol->type(1);
                sld_preBilateral_sCol->box(FL_PLASTIC_DOWN_BOX);
                sld_preBilateral_sCol->selection_color((Fl_Color)14);
                sld_preBilateral_sCol->labelfont(2);
                sld_preBilateral_sCol->labelsize(18);
                sld_preBilateral_sCol->minimum(1);
                sld_preBilateral_sCol->maximum(80);
                sld_preBilateral_sCol->step(0.1);
                sld_preBilateral_sCol->value(50);
                sld_preBilateral_sCol->textsize(18);
                sld_preBilateral_sCol->callback((Fl_Callback*)drawNewImage);
                sld_preBilateral_sCol->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_preBilateral_sCol->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_preBilateral_sCol
              { sld_preBilateral_sSpace = new Fl_Value_Slider(535, 444, 131, 30, "Sigma Space:");
                sld_preBilateral_sSpace->type(1);
                sld_preBilateral_sSpace->box(FL_PLASTIC_DOWN_BOX);
                sld_preBilateral_sSpace->selection_color((Fl_Color)14);
                sld_preBilateral_sSpace->labelfont(2);
                sld_preBilateral_sSpace->labelsize(18);
                sld_preBilateral_sSpace->minimum(1);
                sld_preBilateral_sSpace->maximum(80);
                sld_preBilateral_sSpace->step(0.1);
                sld_preBilateral_sSpace->value(50);
                sld_preBilateral_sSpace->textsize(18);
                sld_preBilateral_sSpace->callback((Fl_Callback*)drawNewImage);
                sld_preBilateral_sSpace->align(Fl_Align(FL_ALIGN_TOP_LEFT));
                sld_preBilateral_sSpace->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_preBilateral_sSpace
              o->end();
            } // Fl_Group* o
            { chk_preBilateral_enable = new Fl_Check_Button(460, 487, 206, 30, "Bilateral Blur (Pre)");
              chk_preBilateral_enable->box(FL_PLASTIC_DOWN_BOX);
              chk_preBilateral_enable->down_box(FL_PLASTIC_DOWN_BOX);
              chk_preBilateral_enable->value(1);
              chk_preBilateral_enable->labelfont(2);
              chk_preBilateral_enable->labelsize(20);
              chk_preBilateral_enable->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_preBilateral_enable
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(36, 410, 190, 50, "1. Initial bluring (Bilateral)");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblPreBilat = new Fl_Box(126, 499, 100, 30, "0 ms");
            lblPreBilat->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblPreBilat->color(FL_DARK2);
            lblPreBilat->labelfont(3);
            lblPreBilat->labelsize(16);
            lblPreBilat->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblPreBilat
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(28, 544, 653, 171);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(236, 544, 445, 166);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(246, 554, 435, 123);
              o->labelsize(18);
              { sld_thrsh_low_2 = new Fl_Value_Slider(251, 554, 420, 32, "Lower Threshold");
                sld_thrsh_low_2->tooltip("The lower value threshold");
                sld_thrsh_low_2->type(3);
                sld_thrsh_low_2->box(FL_PLASTIC_THIN_DOWN_BOX);
                sld_thrsh_low_2->selection_color((Fl_Color)14);
                sld_thrsh_low_2->labelfont(2);
                sld_thrsh_low_2->labelsize(18);
                sld_thrsh_low_2->maximum(255);
                sld_thrsh_low_2->step(1);
                sld_thrsh_low_2->value(25);
                sld_thrsh_low_2->slider_size(1);
                sld_thrsh_low_2->textfont(2);
                sld_thrsh_low_2->textsize(18);
                sld_thrsh_low_2->textcolor(FL_GRAY0);
                sld_thrsh_low_2->callback((Fl_Callback*)drawNewImage);
                sld_thrsh_low_2->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
                sld_thrsh_low_2->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_thrsh_low_2
              { sld_thrsh_high_2 = new Fl_Value_Slider(251, 618, 420, 32, "High Threshold");
                sld_thrsh_high_2->tooltip("The lower value threshold");
                sld_thrsh_high_2->type(3);
                sld_thrsh_high_2->box(FL_PLASTIC_THIN_DOWN_BOX);
                sld_thrsh_high_2->selection_color((Fl_Color)14);
                sld_thrsh_high_2->labelfont(2);
                sld_thrsh_high_2->labelsize(18);
                sld_thrsh_high_2->minimum(1);
                sld_thrsh_high_2->maximum(255);
                sld_thrsh_high_2->step(1);
                sld_thrsh_high_2->value(255);
                sld_thrsh_high_2->slider_size(1);
                sld_thrsh_high_2->textfont(2);
                sld_thrsh_high_2->textsize(18);
                sld_thrsh_high_2->textcolor(FL_GRAY0);
                sld_thrsh_high_2->callback((Fl_Callback*)drawNewImage);
                sld_thrsh_high_2->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
                sld_thrsh_high_2->when(FL_WHEN_RELEASE);
              } // Fl_Value_Slider* sld_thrsh_high_2
              o->end();
            } // Fl_Group* o
            { chk_threshImg_enable_2 = new Fl_Check_Button(519, 670, 156, 30, "Hue Isolation");
              chk_threshImg_enable_2->box(FL_PLASTIC_DOWN_BOX);
              chk_threshImg_enable_2->down_box(FL_PLASTIC_DOWN_BOX);
              chk_threshImg_enable_2->value(1);
              chk_threshImg_enable_2->labelfont(2);
              chk_threshImg_enable_2->labelsize(20);
              chk_threshImg_enable_2->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_threshImg_enable_2
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(36, 544, 190, 30, "2. Hue thresholding ");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblthreshImg_2 = new Fl_Box(127, 680, 100, 30, "0 ms");
            lblthreshImg_2->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblthreshImg_2->color(FL_DARK2);
            lblthreshImg_2->labelfont(3);
            lblthreshImg_2->labelsize(16);
            lblthreshImg_2->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblthreshImg_2
          o->end();
        } // Fl_Group* o
        { Fl_Group* o = new Fl_Group(28, 720, 656, 65);
          o->labelsize(18);
          { Fl_Group* o = new Fl_Group(236, 720, 220, 65);
            o->box(FL_PLASTIC_DOWN_BOX);
            o->color((Fl_Color)44);
            o->labelsize(24);
            o->align(Fl_Align(FL_ALIGN_BOTTOM_LEFT));
            { Fl_Group* o = new Fl_Group(260, 745, 15, 15);
              o->labelsize(18);
              o->end();
            } // Fl_Group* o
            { chk_identification_2 = new Fl_Check_Button(246, 742, 200, 33, "Identification");
              chk_identification_2->box(FL_PLASTIC_DOWN_BOX);
              chk_identification_2->down_box(FL_PLASTIC_DOWN_BOX);
              chk_identification_2->value(1);
              chk_identification_2->labelfont(2);
              chk_identification_2->labelsize(20);
              chk_identification_2->callback((Fl_Callback*)switchVisibility);
            } // Fl_Check_Button* chk_identification_2
            o->end();
          } // Fl_Group* o
          { Fl_Box* o = new Fl_Box(34, 720, 193, 25, "3. Identification");
            o->box(FL_PLASTIC_DOWN_FRAME);
            o->color(FL_DARK2);
            o->labelfont(3);
            o->labelsize(16);
            o->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* o
          { lblIdentification_2 = new Fl_Box(126, 755, 101, 30, "0 ms");
            lblIdentification_2->box(FL_PLASTIC_ROUND_DOWN_BOX);
            lblIdentification_2->color(FL_DARK2);
            lblIdentification_2->labelfont(3);
            lblIdentification_2->labelsize(16);
            lblIdentification_2->align(Fl_Align(132|FL_ALIGN_INSIDE));
          } // Fl_Box* lblIdentification_2
          o->end();
        } // Fl_Group* o
        o->end();
      } // Fl_Scroll* o
      tabPane->end();
    } // Fl_Tabs* tabPane
    { Fl_Group* o = new Fl_Group(20, 14, 680, 364);
      o->box(FL_PLASTIC_DOWN_BOX);
      o->color((Fl_Color)46);
      { dirTree = new Fl_Tree(40, 37, 330, 278);
        dirTree->box(FL_PLASTIC_DOWN_BOX);
        dirTree->labelsize(20);
        dirTree->callback((Fl_Callback*)loadImgFromTree);
        dirTree->when(FL_WHEN_RELEASE);
        dirTree->root_label("Loaded Images");
      } // Fl_Tree* dirTree
      { btn_loadImg = new Fl_Button(210, 328, 160, 30, "Load New Image");
        btn_loadImg->box(FL_PLASTIC_THIN_UP_BOX);
        btn_loadImg->down_box(FL_PLASTIC_THIN_DOWN_BOX);
        btn_loadImg->labelsize(18);
        btn_loadImg->callback((Fl_Callback*)chooseFile);
      } // Fl_Button* btn_loadImg
      { Fl_Button* o = new Fl_Button(40, 328, 115, 30, "Delete entry");
        o->box(FL_PLASTIC_THIN_UP_BOX);
        o->shortcut(0xffff);
        o->down_box(FL_PLASTIC_THIN_DOWN_BOX);
        o->labelfont(2);
        o->labelsize(18);
        o->callback((Fl_Callback*)removeFileEntry);
      } // Fl_Button* o
      { Fl_Group* o = new Fl_Group(380, 222, 310, 136, "Time Statistics");
        o->box(FL_PLASTIC_DOWN_FRAME);
        o->labelsize(18);
        o->align(Fl_Align(FL_ALIGN_TOP|FL_ALIGN_INSIDE));
        { lblTotTime = new Fl_Box(390, 317, 280, 33, "0 ms | 0 s | 0 fps");
          lblTotTime->box(FL_PLASTIC_ROUND_DOWN_BOX);
          lblTotTime->labelsize(18);
          lblTotTime->align(Fl_Align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE));
        } // Fl_Box* lblTotTime
        { Fl_Box* o = new Fl_Box(390, 289, 170, 27, "Total time taken:");
          o->labelsize(18);
          o->align(Fl_Align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE));
        } // Fl_Box* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(380, 145, 310, 67, "Change Callback on:");
        o->box(FL_PLASTIC_DOWN_FRAME);
        o->labelsize(18);
        o->align(Fl_Align(133|FL_ALIGN_INSIDE));
        { Fl_Light_Button* o = new Fl_Light_Button(390, 172, 140, 30, "Release");
          o->box(FL_PLASTIC_ROUND_DOWN_BOX);
          o->down_box(FL_PLASTIC_ROUND_DOWN_BOX);
          o->selection_color((Fl_Color)14);
          o->labelsize(18);
          o->callback((Fl_Callback*)toggleCB);
          o->do_callback();
        } // Fl_Light_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Group* o = new Fl_Group(555, 37, 135, 100);
        o->box(FL_PLASTIC_DOWN_FRAME);
        o->labelsize(18);
        { Fl_Button* o = new Fl_Button(565, 47, 115, 35, "Help");
          o->box(FL_PLASTIC_THIN_UP_BOX);
          o->down_box(FL_PLASTIC_THIN_DOWN_BOX);
          o->labelsize(18);
        } // Fl_Button* o
        { Fl_Button* o = new Fl_Button(565, 92, 115, 35, "Credits");
          o->box(FL_PLASTIC_THIN_UP_BOX);
          o->down_box(FL_PLASTIC_THIN_DOWN_BOX);
          o->labelsize(18);
        } // Fl_Button* o
        o->end();
      } // Fl_Group* o
      { Fl_Box* o = new Fl_Box(380, 37, 165, 100, "Simple Grape Stem Approximator");
        o->box(FL_PLASTIC_DOWN_FRAME);
        o->labelfont(3);
        o->labelsize(20);
        o->align(Fl_Align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE));
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    window->end();
  } // Fl_Double_Window* window
  {
  nativeFileChooser = new Fl_Native_File_Chooser();
  tabPane->do_callback();
  }
  //window->end();
  window->show();
  
  return Fl::run();
}

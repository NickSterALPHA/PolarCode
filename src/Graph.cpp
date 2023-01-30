#include <FL/Fl.H>
#include <iostream>
#include <vector>
#include <cmath>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Radio_Round_Button.H>
#include "matplotlibcpp.h"
#include "PolarCode.h"
#include "Simulation.h"
#include <cstdlib>

namespace plt = matplotlibcpp;

static int N = 0; 
static int k = 0; 
static int CRC_size = 0; 
static int CanNum = 0; 
static bool select_SC = false; 
static bool select_SCL = false; 
static bool select_Fast_SCL = false; 
static bool select_Upgraded_Fast_SCL = false; 
static double SNR_start = 0.0; 
static double SNR_end = 0.0; 
static double SNR_step = 0.0; 
static int Max_Iter = 100;

Fl_Double_Window *My_Win=(Fl_Double_Window *)0;

Fl_Value_Input *inp_N=(Fl_Value_Input *)0;

Fl_Button *Button=(Fl_Button *)0;

Fl_Value_Input *inp_k=(Fl_Value_Input *)0;

Fl_Value_Input *inp_CRC=(Fl_Value_Input *)0;

Fl_Value_Input *inp_CanNum=(Fl_Value_Input *)0;

Fl_Box *info_box=(Fl_Box *)0;

Fl_Box *Box_decod=(Fl_Box *)0;

Fl_Box *snr_box=(Fl_Box *)0;

Fl_Value_Input *inp_SNR_start=(Fl_Value_Input *)0;

Fl_Value_Input *inp_SNR_end=(Fl_Value_Input *)0;

Fl_Value_Input *inp_SNR_step=(Fl_Value_Input *)0;

Fl_Group *Radio_Group=(Fl_Group *)0;

Fl_Radio_Round_Button *radio_SC=(Fl_Radio_Round_Button *)0;

Fl_Radio_Round_Button *radio_SCL=(Fl_Radio_Round_Button *)0;

Fl_Radio_Round_Button *radio_Fast_SCL=(Fl_Radio_Round_Button *)0;

Fl_Radio_Round_Button *radio_Upgraded_Fast_SCL=(Fl_Radio_Round_Button*)0;

Fl_Double_Window *Window_Error=(Fl_Double_Window *)0;

Fl_Box *error_box=(Fl_Box *)0;

Fl_Box *enter_info_box=(Fl_Box *)0;

Fl_Button *BTN_OK_1=(Fl_Button *)0;

Fl_Double_Window *Window_Dec_Error=(Fl_Double_Window *)0;

Fl_Box *error_dec_box=(Fl_Box *)0;

Fl_Box *enter_dec_info_box=(Fl_Box *)0;

Fl_Button *BTN_OK_2=(Fl_Button *)0;

std::vector<int> Generate_Vector(int length) {
    std::vector<int> res(length);
    for (int i = 0; i < length; i++) {
        res[i] = std::rand() % 2;
    }
    return res;
}

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for(const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

bool CheckParams() {
    bool positive = (N > 0) && (CRC_size > 0) && (k > 0) && (CanNum > 0);
    bool size = (k + CRC_size < N);
    bool Power2 = std::pow(2, (int)std::log2(N)) == N;
    return positive && size && Power2;
}

bool SelectDecoder() {
  return select_SC || select_Fast_SCL || select_SCL || select_Upgraded_Fast_SCL;
}


void CB_RADIO_SC(Fl_Radio_Round_Button* widg, void *data) {
  select_SC = true;
  select_SCL = false;
  select_Fast_SCL = false;
  select_Upgraded_Fast_SCL = false;
}

void CB_RADIO_SCL(Fl_Radio_Round_Button* widg, void *data) {
  select_SC = false;
  select_SCL = true;
  select_Fast_SCL = false;
  select_Upgraded_Fast_SCL = false;
}

void CB_RADIO_FAST_SCL(Fl_Radio_Round_Button* widg, void *data) {
  select_SC = false;
  select_SCL = false;
  select_Fast_SCL = true;
  select_Upgraded_Fast_SCL = false;
}

void CB_RADIO_UPGRADED_FAST_SCL(Fl_Radio_Round_Button* widg, void *data) {
  select_SC = false;
  select_SCL = false;
  select_Fast_SCL = false;
  select_Upgraded_Fast_SCL = true;
}

void CB_INP_SNR_START(Fl_Value_Input* widg, void* data) {
  SNR_start = widg->value();
}

void CB_INP_SNR_END(Fl_Value_Input* widg, void* data) {
  SNR_end = widg->value();
}

void CB_INP_SNR_STEP(Fl_Value_Input* widg, void* data) {
  SNR_step = widg->value();
}

void CB_INP_N(Fl_Value_Input* widg, void* data) {
  N = widg->value();
}

void CB_INP_k(Fl_Value_Input* widg, void* data) {
  k = widg->value();
}

void CB_INP_CRC(Fl_Value_Input* widg, void* data) {
  CRC_size = widg->value();
}

void CB_INP_CanNum(Fl_Value_Input* widg, void* data) {
  CanNum = widg->value();
}

void CB_BTN_OK_1(Fl_Button* widg, void* data) {
  Window_Error->hide();
  return;
}

void CB_BTN_OK_2(Fl_Button* widg, void* data) {
  Window_Dec_Error->hide();
  return;
}

void CB_BUTTON(Fl_Button* widg, void* data) {
  inp_N->callback((Fl_Callback*)CB_INP_N);
  inp_k->callback((Fl_Callback*)CB_INP_k);
  inp_CRC->callback((Fl_Callback*)CB_INP_CRC);
  inp_CanNum->callback((Fl_Callback*)CB_INP_CanNum);
  inp_SNR_start->callback((Fl_Callback*)CB_INP_SNR_START);
  inp_SNR_end->callback((Fl_Callback*)CB_INP_SNR_END);
  inp_SNR_step->callback((Fl_Callback*)CB_INP_SNR_STEP);
  radio_SC->callback((Fl_Callback*)CB_RADIO_SC);
  radio_SCL->callback((Fl_Callback*)CB_RADIO_SCL);
  radio_Fast_SCL->callback((Fl_Callback*)CB_RADIO_FAST_SCL);

  if (!CheckParams()) {
      { Window_Error = new Fl_Double_Window(320, 170, "Window_Error");
      { error_box = new Fl_Box(70, 13, 190, 37, "Error has occurred");
      } // Fl_Box* error_box
      { enter_info_box = new Fl_Box(45, 46, 265, 51, "Please enter correct variable values");
      } // Fl_Box* enter_info_box
      { BTN_OK_1 = new Fl_Button(135, 105, 70, 25, "OK");
        BTN_OK_1->callback((Fl_Callback*)CB_BTN_OK_1);
      } // Fl_Button* BTN_OK_1
      Window_Error->end();
      } // Fl_Double_Window* Window_Error
    Window_Error->show();
    return;
  }

  if (!SelectDecoder()) {
      { Window_Dec_Error = new Fl_Double_Window(320, 170, "Window_Error");
      { error_dec_box = new Fl_Box(70, 13, 190, 37, "Error has occurred");
      } // Fl_Box* error_dec_box
      { enter_dec_info_box = new Fl_Box(45, 46, 265, 51, "Please choose the decoder");
      } // Fl_Box* enter_dec_info_box
      { BTN_OK_2 = new Fl_Button(135, 105, 70, 25, "OK");
        BTN_OK_2->callback((Fl_Callback*)CB_BTN_OK_2);
      } // Fl_Button* BTN_OK_2
      Window_Dec_Error->end();
      } // Fl_Double_Window* Window_Error
    Window_Dec_Error->show();
    return;
  }


  std::vector<double> SNR_points;
  std::vector<double> Prob_points;
  std::vector<double> noises;
  int GenSize = k + CRC_size;
  for (double cur_SNR = SNR_start; cur_SNR <= SNR_end; cur_SNR += SNR_step) {
    SNR_points.push_back(cur_SNR);
    double Rate = (double)k / N;
    double EbNo = std::pow(10, cur_SNR / 10);
    double noise = std::sqrt(1.0 / (2 * EbNo * Rate));
    noises.push_back(noise);
    int cur_num_errors = 0;
    double error_exp = 0.0, num_exp = 0.0;
    
    while(cur_num_errors < CanNum) {
      // generate vector with crc
      std::vector<int> msg = Generate_Vector(k); // generate random vec
      std::vector<int> crc_code = Get_CRC(msg, CRC_size); // get crc
      std::vector<int> msg_crc(msg);
      msg_crc.insert(msg_crc.end(), crc_code.begin(), crc_code.end()); // insert crc

      // encode vector
      std::vector<int> msgFrozen = AddFrozen(msg_crc, N); // adding Frozen
      std::vector<std::vector<int>> Matrix1 = PolarTransform((int)log2(N));
      std::vector<int> CodeWord = PolarEncoding(msgFrozen, Matrix1);
      
      //simulate channel
      BPSK(CodeWord);
      std::vector<double> ReceivedWord = AWGN(CodeWord, noise);

      std::vector<int> DecodedWord;

      if (select_SC) {
        DecodedWord = SC_Decoding(ReceivedWord, GenSize);
      } else if (select_SCL) {
        std::vector<std::vector<int>> PosibleWords = SCList(ReceivedWord, GenSize, 4);
        DecodedWord = Msg_Correct_CRC(PosibleWords, CRC_size);
      } else if (select_Fast_SCL) {
        std::vector<std::vector<int>> PosibleWords = Fast_SCL(ReceivedWord, GenSize, 4);
        DecodedWord = Msg_Correct_CRC(PosibleWords, CRC_size);
      } else if (select_Upgraded_Fast_SCL) {
        std::vector<std::vector<int>> PosibleWords = Upgrade_Fast_SCL(ReceivedWord, GenSize, 4);
        DecodedWord = Msg_Correct_CRC(PosibleWords, CRC_size);
      }
      
      DecodedWord.erase(DecodedWord.end() - CRC_size, DecodedWord.end()); // delete CRC (need to check)
      if (NumErrors(msg, DecodedWord) != 0) {
        error_exp += 1.0;
        cur_num_errors += 1;
      }

      num_exp += 1.0;
      }
    double Prob = error_exp / num_exp;
    Prob_points.push_back(Prob);
  }
  plt::semilogy(SNR_points, Prob_points);
  plt::xlabel("SNR, dB");
  plt::ylabel("Probability");
  plt::show();
}



int main(int argc, char **argv) {
  
  std::srand((unsigned) time(NULL));
  { My_Win = new Fl_Double_Window(575, 500, "Settings");
    { inp_N = new Fl_Value_Input(135, 90, 60, 30, "Enter N:");
      inp_N->callback((Fl_Callback*)CB_INP_N);
    } // Fl_Value_Input* inp_N
    { Button = new Fl_Button(245, 405, 115, 25, "Plot Graphic");
      Button->callback((Fl_Callback*)CB_BUTTON);
    } // Fl_Button* Button
    { inp_k = new Fl_Value_Input(135, 140, 60, 30, "Enter k:");
      inp_k->callback((Fl_Callback*)CB_INP_k);
    } // Fl_Value_Input* inp_k
    { inp_CRC = new Fl_Value_Input(485, 90, 60, 30, "Enter CRC-size:");
      inp_CRC->callback((Fl_Callback*)CB_INP_CRC);
    } // Fl_Value_Input* inp_CRC
    { inp_CanNum = new Fl_Value_Input(485, 135, 60, 30, "Enter number of cancelation:");
      inp_CanNum->callback((Fl_Callback*)CB_INP_CanNum);
    } // Fl_Value_Input* inp_CanNum
    { info_box = new Fl_Box(255, 28, 80, 30, "PolarCode project");
    } // Fl_Box* info_box
    { Box_decod = new Fl_Box(255, 208, 85, 30, "Select decoder");
    } // Fl_Box* Box_decod
    { snr_box = new Fl_Box(255, 306, 85, 30, "Write SNR range");
    } // Fl_Box* snr_box
    { inp_SNR_start = new Fl_Value_Input(159, 345, 60, 30, "Value SNR From:");
      inp_SNR_start->callback((Fl_Callback*)CB_INP_SNR_START);
    } // Fl_Value_Input* inp_SNR_start
    { inp_SNR_end = new Fl_Value_Input(280, 345, 60, 30, "to:");
      inp_SNR_end->callback((Fl_Callback*)CB_INP_SNR_END);
    } // Fl_Value_Input* inp_SNR_end
    { inp_SNR_step = new Fl_Value_Input(430, 345, 60, 30, "Step:");
      inp_SNR_step->callback((Fl_Callback*)CB_INP_SNR_STEP);
    } // Fl_Value_Input* inp_SNR_step
    { Radio_Group = new Fl_Group(-5, 245, 560, 45);
      { radio_SC = new Fl_Radio_Round_Button(85, 255, 60, 30, "SC");
        radio_SC->down_box(FL_ROUND_DOWN_BOX);
        radio_SC->callback((Fl_Callback*)CB_RADIO_SC);
      } // Fl_Round_Button* radio_SC
      { radio_SCL = new Fl_Radio_Round_Button(185, 255, 60, 30, "SCL");
        radio_SCL->down_box(FL_ROUND_DOWN_BOX);
        radio_SCL->callback((Fl_Callback*)CB_RADIO_SCL);
      } // Fl_Round_Button* radio_SCL
      { radio_Fast_SCL = new Fl_Radio_Round_Button(280, 255, 60, 30, "Fast SCL");
        radio_Fast_SCL->down_box(FL_ROUND_DOWN_BOX);
        radio_Fast_SCL->callback((Fl_Callback*)CB_RADIO_FAST_SCL);
      } // Fl_Round_Button* radio_Fast_SCL
      { radio_Upgraded_Fast_SCL = new Fl_Radio_Round_Button(400, 255, 155, 30, "Upgraded Fast SCL");
        radio_Upgraded_Fast_SCL->down_box(FL_ROUND_DOWN_BOX);
        radio_Upgraded_Fast_SCL->callback((Fl_Callback*)CB_RADIO_UPGRADED_FAST_SCL);
      } // Fl_Round_Button* radio_Upgraded_Fast_SCL
      Radio_Group->end();
    } // Fl_Group* Radio_Group
    My_Win->end();
  } // Fl_Double_Window* My_Win
  My_Win->show(argc, argv);
  return Fl::run();
}

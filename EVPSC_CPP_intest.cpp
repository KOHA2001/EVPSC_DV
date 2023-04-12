#include <time.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <Eigen/Dense>

#include "Input.h"
#include "Toolbox.h"
#include "global.h"
#include "Processes.h"
#include "Polycrystals.h"

int main()
{
    Polycs::polycrystal metal; //declare object
    Procs::Process Proc1;
    logger.info("EVPSC_CPP Start!");

    string ftex, fsx, fload;
    if(EVPSCinput(ftex, fsx, fload, Proc1)) exit(0);
    if(texinput(ftex, metal)) exit(0);
    if(sxinput(fsx, metal)) exit(0);
    if(loadinput(fload, Proc1)) exit(0);
    
    double Start = clock();
    Proc1.loading(metal);
    double End = clock();
    string end_message = "EVPSC_CPP End! The run time is: " + std::to_string((double)(End - Start) / (Mtr * CLOCKS_PER_SEC)) + " sec";
    logger.info(end_message);
    return 0;
}

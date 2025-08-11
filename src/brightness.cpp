#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

std::string const currentBrightnessPath = "/sys/class/backlight/intel_backlight/brightness";
std::string const maxBrightnessPath = "/sys/class/backlight/intel_backlight/max_brightness";

int main(int argumentCount, char *argValues[]) {
  if (argumentCount <= 1) {
    std::cerr << "Please provide a compelling argument!" << std::endl;
    return 1;
  }

  if (argumentCount == 2) {
    int newBrightnessInt = std::stoi(argValues[1]);
    std::ofstream currentBrightnessFile(currentBrightnessPath);
    std::ifstream maxBrightnessFile(maxBrightnessPath);

    std::string maxBrightnessString;
    std::getline(maxBrightnessFile, maxBrightnessString);
    int maxBrightnessInt = std::stoi(maxBrightnessString);

    if (newBrightnessInt <= maxBrightnessInt) {
      currentBrightnessFile << newBrightnessInt;
      std::cout << "Current Brightness: " << newBrightnessInt << "/" << maxBrightnessInt << std::endl;
    } else {
      std::cerr << "File open error" << std::endl;
    }

    currentBrightnessFile.close();
    maxBrightnessFile.close();
    return 0;
  }
}
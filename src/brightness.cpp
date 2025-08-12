#include <fstream>
#include <iostream>
#include <string>

std::string const currentBrightnessPath =
    "/sys/class/backlight/intel_backlight/brightness";
std::string const maxBrightnessPath =
    "/sys/class/backlight/intel_backlight/max_brightness";

void set_int_from_file(std::string path, int content) {
  std::ofstream file(path);
  file << content;
}

int get_int_from_file(std::string path) {
  std::ifstream file(path);

  std::string fileString;
  std::getline(file, fileString);
  int fileInt = std::stoi(fileString);
  return fileInt;
}

int main(int argumentCount, char *argValues[]) {
  if (argumentCount <= 1) {
    std::cerr << "Please provide a compelling argument!" << std::endl;
    return 1;
  }

  if (argumentCount == 2) {
    int newBrightnessInt = std::stoi(argValues[1]);
    int maxBrightnessInt = get_int_from_file(maxBrightnessPath);

    if (newBrightnessInt <= maxBrightnessInt) {
      set_int_from_file(currentBrightnessPath, newBrightnessInt);
      std::cout << "Current Brightness: " << newBrightnessInt << "/"
                << maxBrightnessInt << std::endl;
    } else {
      std::cerr << "File open error" << std::endl;
    }

    return 0;
  }
}
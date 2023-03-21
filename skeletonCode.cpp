#include <iostream>
#include <string>
#include <Simb/Image.h>

using namespace Simb;

int main() {
  // Read in the image
  Image image;
  image.read("input.png");

  // Prompt the user to enter the message
  std::string message;
  std::cout << "Enter the message to embed: ";
  std::getline(std::cin, message);

  // Convert the message to binary
  std::string binary_message = "";
  for (char c : message) {
    // Convert each character to its ASCII code
    int ascii_code = static_cast<int>(c);
    // Convert the ASCII code to binary
    std::string binary_code = "";
    for (int i = 0; i < 8; i++) {
      binary_code = std::to_string(ascii_code % 2) + binary_code;
      ascii_code /= 2;
    }
    binary_message += binary_code;
  }

  // Embed the binary message into the image
  int message_index = 0;
  for (int x = 0; x < image.width(); x++) {
    for (int y = 0; y < image.height(); y++) {
      // Get the RGB values of the current pixel
      RGBColor color = image.getPixel(x, y);
      // Modify the least significant bit of each value to encode a bit of the binary message
      color.r = (color.r & ~1) | (binary_message[message_index++] - '0');
      color.g = (color.g & ~1) | (binary_message[message_index++] - '0');
      color.b = (color.b & ~1) | (binary_message[message_index++] - '0');
      // Set the modified pixel color
      image.setPixel(x, y, color);
      // If the entire message has been embedded, break out of the loop
      if (message_index >= binary_message.length()) {
        break;
      }
    }
    if (message_index >= binary_message.length()) {
      break;
    }
  }

  // Save the modified image to a new file
  image.write("output.png");

  return 0;
}

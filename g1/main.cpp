#include <cstdlib>   // EXIT_SUCCESS, EXIT_FAILURE
#include <iostream>  // std::cout, std::cin, std::endl, std::getline
#include <string>    // std::string
#include <vector>    // std::vector<T>


/**
 * This is where I start my C++ logic. This takes a collection of
 * strings in a vector as the arguments, as this makes implementing
 * debugging flags a little easier.
 *
 * @param args the const reference to the vector of string arguments.
 *     The first is always the executable path in respect to the
 *     current working directory.
 * @return the exit code.
 */
inline unsigned short int cpp_main(const std::vector<std::string>& args)
{
  try
  {
    std::cout << "Hello, World!" << std::endl;
    return EXIT_SUCCESS;
  }
  catch (const std::string& err_msg)
  {
    std::cerr << err_msg << std::endl;
    return EXIT_FAILURE;
  }
}


/**
 * Application entry point. To make debugging easier, I generate
 * a vector of std::string objects for the command line arguments,
 * and pass this to the entry point above. Might as well utilise
 * some of the tools in C++ to make my life a little easier.
 *
 * @param argc the number of arguments passed.
 * @param argv any command line arguments passed.
 * @return the exit code.
 */
int main(const size_t argc, const char* const argv[])
{
  std::vector<std::string> args;

  for (size_t i = 0; i < argc; ++i)
  {
    std::string next_arg = argv[i];
    args.push_back(next_arg);
  }

  int result = static_cast<int>(cpp_main(args));
  std::cerr << "Press ENTER to exit." << std::endl;
  std::string placeholder;
  // Ensures I can read any output before the console dies.
  std::getline(std::cin, placeholder);
  return result;
}

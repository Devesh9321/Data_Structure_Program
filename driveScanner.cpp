
/****************************************
*   Auther : Devesh Patil + chatgpt     *
****************************************/

#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

void scanDirectory(const fs::path &directory, std::ofstream &outputFile)
{
    for (const auto &entry : fs::directory_iterator(directory))
    {
        try
        {
            if (fs::is_directory(entry.path()))
            {
                scanDirectory(entry.path(), outputFile); // Recursively scan subdirectories
            }
            else if (fs::is_regular_file(entry.path()))
            {
                fs::path filePath = entry.path();
                std::string fileName = filePath.filename().string();
                std::string fileSize = std::to_string(fs::file_size(entry.path()));
                std::string fileLastModified = std::to_string(fs::last_write_time(entry.path()));

                // Write file information to the output file
                outputFile << "File Name: " << fileName << "\n";
                outputFile << "File Size: " << fileSize << " bytes\n";
                outputFile << "Last Modified: " << fileLastModified << "\n\n";
            }
        }
        catch (const std::exception &ex)
        {
            std::cerr << "Error processing file: " << ex.what() << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <source_directory> <output_file>" << std::endl;
        return 1;
    }

    fs::path sourceDirectory(argv[1]);
    fs::path outputFile(argv[2]);

    if (!fs::exists(sourceDirectory) || !fs::is_directory(sourceDirectory))
    {
        std::cerr << "Source directory does not exist or is not a directory." << std::endl;
        return 1;
    }

    std::ofstream output(outputFile);
    if (!output.is_open())
    {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    try
    {
        scanDirectory(sourceDirectory, output);
        std::cout << "Scan completed successfully." << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error during scanning: " << ex.what() << std::endl;
        return 1;
    }

    output.close();
    return 0;
}

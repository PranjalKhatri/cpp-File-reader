#ifndef __DATAREADER_H__
#define __DATAREADER_H__
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
// using namespace std;

/// @brief Loads the data from csv to floating vectors
/// @warning It is the users responsibility to ensure there is only floating/numerical data  except the headings
class DATASET
{
private:
    
    //to display data in a nice format
    int maxtitle_len = 5;
public:
    /// @brief numerical data
    std::vector<std::vector<float>> data;
    int num_fields = 0;
    int datasize = 0;
    std::vector<std::string> titles;

public:
    DATASET() = default;
    /// @brief Loads the data(csv file) into the memory
    /// @param name name of the file to open
    void open(std::string name)
    {
        std::ifstream stream(name);
        std::string str;
        std::getline(stream, str);
        std::string x;
        titles.push_back(x);
        for (auto i : str)
        {
            if (i == ',')
            {
                std::string temp;
                titles.push_back(temp);
                num_fields++;
            }
            else
            {
                titles[num_fields] += i;
                maxtitle_len = std::max(maxtitle_len,int(titles[num_fields].size()));
            }
        }
        num_fields++;
        for (int i = 0; i < num_fields; i++)
        {
            std::vector<float> v;
            data.push_back(v);
        }

        while (!stream.eof())
        {
            datasize++;
            std::string s;
            std::getline(stream, s);
            int ci = 0;
            std::string dat = "";
            for (auto i : s)
            {
                if (i == ',')
                {
                    // dat.pop_back();
                    data[ci].push_back(atof(dat.c_str()));
                    dat = "";
                    ci++;
                }
                else
                {
                    dat += i;
                }
            }
            data[ci].push_back(atof(dat.c_str()));

            // cout<<x<<" "<<y<<endl;
        }
    }
    
    /// @brief outputs a table containing first 5 enteries of the data 
    void HEAD()
    {
        int k = std::min(5,datasize);

        for (auto i : titles)
        {
            std::cout << std::setw(maxtitle_len) << i << " |";
        }
        std::cout << "\n";
        for (int j = 0; j<=(titles.size()+1)*maxtitle_len;j++)
        {
            std::cout <<"-";
        }
        std::cout << "\n";
        for (int i = 0; i < k; i++)
        {
            for (auto item : data)
            {
                std::cout << std::setw(maxtitle_len) << std::setfill(' ') << item[i] << " |";
            }
            std::cout << "\n";
        }
    }
    
    ~DATASET()
    {
        for (auto i : data)
        {
            i.clear();
        }
        data.clear();
    }
};


#endif
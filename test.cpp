#include "./headers/datareader.h"

int main(int argc, char const *argv[])
{
    DATASET d;
    d.open("./test_data/kc_house_data.csv");
    d.HEAD();
    for (int i = 0; i < 5; i++)
    {
        std::cout<<d.titles[i]<<" ";
    }
    
    std::vector<float> dat = d.data[2];
    for (int i = 0; i < 5; i++)
    {
        std::cout<<dat[i]<<std::endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

bool isSilence(float n)
{
    return n == 0.0;
}

int findSilence(vector<float> data, bool (*fn)(float n))
{
    int count = 0;
    for (vector<float>::iterator it = data.begin(); it != data.end(); it++)
    {
        if (isSilence(*it))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<float> samples;

    samples.push_back(0.0);
    samples.push_back(0.5);
    samples.push_back(1.0);
    samples.push_back(0.5);
    samples.push_back(0.0);
    samples.push_back(-0.5);
    samples.push_back(-1.0);
    samples.push_back(-0.5);
    samples.push_back(0.0);

    cout << "Silence: " << findSilence(samples, isSilence) << endl;

    return 0;
}
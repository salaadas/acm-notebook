#include <iostream>
#include <string>

#define int long long

int32_t main()
{
    int t;
    while (std::cin >> t) {
        int xo, yo; std::cin >> xo >> yo;
        while (t--) {
            int xt, yt; std::cin >> xt >> yt;
            std::string output;
            if (xt > xo && yt > yo)
                output = "NE";
            else if (xt < xo && yt > yo)
                output = "NO";
            else if (xt > xo && yt < yo)
                output = "SE";
            else if (xt < xo && yt < yo)
                output = "SO";
            else if (xt == xo || yt == yo)
                output = "divisa";
            std::cout << output << std::endl;
        }
    }
    return(0);
}

#include <iostream>

// include depthai library
#include <depthai/depthai.hpp>

int main(){
    using namespace std;

    dai::ImgFrame frame;
    frame.setData({1,2,3,4});
    frame.setWidth(2);
    frame.setHeight(2);
    frame.setType(dai::ImgFrame::Type::GRAY8);

#ifdef DEPTHAI_OPENCV_SUPPORT
    auto x = frame.getFrame();
    std::cout << "Frame cols: " << x.cols << " rows: " << x.rows << std::endl;
#else
    std::cout << "Data size: " << frame.getData().size() << std::endl;
#endif

    return 0;
}


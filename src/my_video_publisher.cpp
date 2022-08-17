#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>

using namespace cv;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "my_video_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("/my_image", 1);

  VideoCapture cap(0);
  if(!cap.isOpened()) return 1;
  Mat frame;
  sensor_msgs::ImagePtr msg;

  ros::Rate loop_rate(10);
  while (nh.ok()) {
    cap >> frame; //Read a new frame
    // Check if grabbed frame is actually full with some content
   if(!frame.empty()) {
     msg = cv_bridge::CvImage(std_msgs::Header(),"bgr8", frame).toImageMsg();
     //Encoding:
     //mono8: CV_8UC1, grayscale image,
     //bgr8: CV_8UC3, color image with blue-green-red color order
     //rgb8: CV_8UC3, color image with red-green-blue color order
     pub.publish(msg);
    }
    ros::spinOnce(); //Since this node publishes, spinonce function is used
    loop_rate.sleep();
  }
}

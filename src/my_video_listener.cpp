#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

std::string window_name = "Video stream";

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  try
  {
    cv::imshow(window_name, cv_bridge::toCvShare(msg, "bgr8")->image);
    cv::waitKey(10);
   }
  catch (cv_bridge::Exception& e)
   {
     ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
  }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_video_listener");
  ros::NodeHandle nh;
  cv::namedWindow(window_name,CV_WINDOW_AUTOSIZE);
  cv::waitKey(1);
  image_transport::ImageTransport it(nh);

  std::string topic_name;
  if(argc !=1 ) topic_name = argv[1];
  else{
    topic_name = "/my_image";
    std::cout << "No topic name given, the default topic name will be used: " << topic_name << std::endl;
  }
  image_transport::Subscriber sub = it.subscribe(topic_name, 1, imageCallback);
  ros::spin(); //Since this node subscribes to a topic only, spin function is used. Otherwise, spinonce function must be used
  cv::destroyWindow(window_name);
}

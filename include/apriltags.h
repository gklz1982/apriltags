const double SMALL_TAG_SIZE = 0.0358968;
const double MED_TAG_SIZE = 0.0630174;
const double PAGE_TAG_SIZE = 0.165;

const std::string DEFAULT_TF_FRAME = "/apriltags";
const std::string DEFAULT_TAG_FAMILY = "Tag36h11";
const std::string DEFAULT_IMAGE_TOPIC = "image";
const std::string DEFAULT_CAMERA_INFO_TOPIC = "camera_info";
const std::string DEFAULT_MARKER_TOPIC = "marker_array";
const double DEFAULT_TAG_SIZE = SMALL_TAG_SIZE;

// ROS parts
ros::NodeHandlePtr node_;
boost::shared_ptr<image_transport::ImageTransport> image_;

ros::Publisher marker_publisher_;
ros::Subscriber info_subscriber;
image_transport::Subscriber image_subscriber;

sensor_msgs::CameraInfo camera_info_;

// AprilTag parts
TagFamily* family_;
TagDetector* detector_;

TagDetectorParams tag_params;
std::string tag_data;
std::string tag_family_name_;

// Settings and local information
int viewer_;
double default_tag_size_;
boost::unordered_map<size_t, double> tag_sizes_;
std::string frame_;
bool running_;

Eigen::Matrix4d GetDetectionTransform(TagDetection detection);
void InfoCallback(const sensor_msgs::CameraInfoConstPtr& camera_info);
void InfoCallback(const sensor_msgs::CameraInfoConstPtr& camera_info);
void ConnectCallback(const ros::SingleSubscriberPublisher& info);
void DisconnectCallback(const ros::SingleSubscriberPublisher& info);
void DisconnectHandler();
void GetParameterValues();
void SetupPublisher();
void InitializeTags();
void StoreTagData(std::string tag_data);
void InitializeROSNode();

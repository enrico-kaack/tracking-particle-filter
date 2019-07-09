#include "ObservationModel.h"

  void calculateHist(cv::Mat& img, cv::Mat& hist){
    int histSize[3];
    float hranges[2];
    const float* ranges[3];
    int channels[3];
    // Prepare arguments for a color histogram
    histSize[0] = 5; histSize[1] = histSize[2] = 25;
    hranges[0] = 0.0; // BRG range
    hranges[1] = 255.0;
    ranges[0] = hranges; // all channels have the same range
    ranges[1] = hranges;
    ranges[2] = hranges;
    channels[0] = 0; // the three channels
    channels[1] = 1;
    channels[2] = 2;
    
    cv::calcHist(&img,
	1, // histogram of 1 image only
	channels, // the channel used
	cv::Mat(), // no mask is used
	hist, // the resulting histogram
	3, // it is a 3D histogram
	histSize, // number of bins
	ranges // pixel value range
	);
  }


  ObservationModel::ObservationModel(cv::Mat img, double lambda_){
    // claculate the histogram of the given image (use calcHist function above)

    calculateHist(img, this->histogram);
    // normalize the histogram
    cv::normalize(this->histogram, this->histogram);
    // store the histogram and lambda
    this->lambda = lambda_;
  }
  
  double ObservationModel::likelihood(cv::Mat img, Particle p){
        // caluclate a histogramm for the window defined by the particle
        auto subImage = p.getSubImg(img);
        calculateHist(subImage, subImage);

      // normalize it
        cv::normalize(subImage, subImage);

        // compare it to the stored histogram using the cv::compareHist function (use the Bahttacharyya distance)
        double histDist = cv::compareHist(subImage, this->histogram, cv::HISTCMP_BHATTACHARYYA);
	// return the likelihood exp(-lambda * histogram_distance)
	return  cv::exp(-lambda*histDist);;
  }


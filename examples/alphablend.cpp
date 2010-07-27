/* This program takes in 8 arguments, argv[1] and argv[2] are the images being blended. *
 * The ROI of argv[2] is blended into the ROI of argv[1]. argv[3] and argv[4] are the   *
 * x and y coordinates respectively of the top left or bottom left corner of the ROI in *
 * the argv[1] image. argv[5] and argv[6] are the width and height of the ROI from the  *
 * x,y coordinate. arg[7] is the weighted alph value of image argv[1], and argv[8] is   * 
 * the weighted beta value of the image argv[2] to be blended.                          */

# include <cv.h>
# include <highgui.h>

int main( int argc, char** argv ) {
	IplImage *src1, *src2;
	if( argc == 9 && ((src1=cvLoadImage(argv[1],1)) != 0
		)&&((src2=cvLoadImage(argv[2],1)) != 0))
		{
			int x = atoi(argv[3]);
			int y = atoi(argv[4]);
			int width = atoi(argv[5]);
			int height = atoi(argv[6]);
			double alpha = (double)atof(argv[7]);
			double beta = (double)atof(argv[8]);
			cvSetImageROI(src1, cvRect(x,y,width,height));
			cvSetImageROI(src2, cvRect(x,y,width,height));
			cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);
			cvResetImageROI(src1);
			cvNamedWindow( "Alpha_blend", 1 );
			cvShowImage( "Alpha_blend", src1 );
			cvWaitKey();
		}
	return 0;
}

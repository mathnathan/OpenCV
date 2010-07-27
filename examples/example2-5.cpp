# include "stdio.h"
# include "cv.h"
# include "highgui.h"

int main( int argc, char** argv ) {
	IplImage* frame = 0;
	IplImage* augframe = 0;

	if( argc < 2 ) {
		printf( "Usage: Accepts one video as argument\n" );
		exit( 0 );
	}

	cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
	cvMoveWindow( "Example2", 100, 100);
	cvNamedWindow( "output", CV_WINDOW_AUTOSIZE );
	cvMoveWindow( "output", 500, 100);
	CvCapture* capture = cvCreateFileCapture( argv[1] );

	while(1) {
	    frame = cvQueryFrame( capture );
	    if( !frame) break;
		augframe = cvCreateImage( cvGetSize( frame ), IPL_DEPTH_8U, 3 );
		cvSmooth( frame, augframe, CV_BILATERAL, 3, 3 );
	    cvShowImage( "Example2", frame );
	    cvShowImage( "output", augframe );
	    char c = cvWaitKey(73);
	    if( c == 27 ) break;
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "Example2" );
}

		



# include "stdio.h"
# include "highgui.h"

int main( int argc, char** argv ) {
	IplImage* frame = 0;

	if( argc < 2 ) {
		printf( "Usage: Accepts one video as argument\n" );
		exit( 0 );
	}

	cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
	cvMoveWindow( "Example2", 100, 100);
	CvCapture* capture = cvCreateFileCapture( argv[1] );

	while(1) {
	    frame = cvQueryFrame( capture );
	    if( !frame) break;
		cvSmooth( frame, augframe, CV_BLUR, 3, 3 );
	    cvShowImage( "Example2", frame );
	    char c = cvWaitKey(73);
	    if( c == 27 ) break;
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "Example2" );
}

		



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

    double fps = cvGetCaptureProperty( capture, CV_CAP_PROP_FPS );
	while(1) {
	    frame = cvQueryFrame( capture );
	    if( !frame) break;
	    cvShowImage( "Example2", frame );
	    char c = cvWaitKey( 33 );
	    if( c == 27 ) break;
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "Example2" );
}

		



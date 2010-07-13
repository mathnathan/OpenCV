# include "stdio.h"
# include "highgui.h"

int main( int argc, char** argv ) {
	IplImage* img = 0;
	int height, width, step, channel;

	if( argc < 2 ) {
		printf( "Usage: Accepts one image as argument\n" );
		exit(EXIT_SUCCESS);
	}

	img	= cvLoadImage( argv[1] );
	if(!img) {
		printf( "Error loading image file %s\n", argv[1]);
		exit(EXIT_SUCCESS);
	}

	cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
	cvMoveWindow( "Example1", 100, 100 );
	cvShowImage( "Example1", img );
	cvWaitKey( 0 );
	cvReleaseImage( &img );
	cvDestroyWindow( "Example1" );
	return EXIT_SUCCESS;
}

# include "stdio.h"
# include "highgui.h"
# include "cv.h"

int main( int argc, char** argv ) {
		IplImage* img = 0;
		IplImage* out = 0;

		
		if( argc < 2 ) {
			printf( "Usage: Accepts one image as argument\n" );
			exit( EXIT_SUCCESS );
		}

		img = cvLoadImage( argv[1] );

		if( !img ) {
			printf( "Error loading image file %s\n", argv[1]);
			exit( EXIT_SUCCESS );
		}

		out = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 3 );

		cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );
		cvMoveWindow( "Example1", 100, 100 );
		cvNamedWindow( "Output", CV_WINDOW_AUTOSIZE );
		cvMoveWindow( "Output", 300, 100 );
		cvShowImage( "Example1", img );
		cvSmooth( img, out, CV_GAUSSIAN, 3, 3 );
		cvShowImage( "Output", out );
		cvWaitKey( 0 );
		cvReleaseImage( &img );	
		cvReleaseImage( &out );
		cvDestroyWindow( "Example1" );
		cvDestroyWindow( "Output" );
		return EXIT_SUCCESS;
}

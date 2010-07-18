# include "highgui.h"
# include "cv.h"
 
int main( int argc, char** argv ) {
	    CvCapture* capture;
		 
		capture = cvCreateCameraCapture(0);	 
			    
		assert( capture != NULL );
				 
		IplImage* bgr_frame = cvQueryFrame( capture );
					 
		CvSize size = cvSize(
				(int)cvGetCaptureProperty( capture,
					CV_CAP_PROP_FRAME_WIDTH),
				(int)cvGetCaptureProperty( capture,
					CV_CAP_PROP_FRAME_HEIGHT)
				);

		cvNamedWindow( "Webcam", CV_WINDOW_AUTOSIZE );

		CvVideoWriter *writer = cvCreateVideoWriter( argv[ 1 ],
				CV_FOURCC('D','I','V','X'),
				30,
				size
				);
				
		while( (bgr_frame = cvQueryFrame( capture )) != NULL ) {
			cvWriteFrame( writer, bgr_frame );
			cvShowImage( "Webcam", bgr_frame );
			char c = cvWaitKey( 33 );
			if( c == 27 ) break;
		}
		cvReleaseVideoWriter( &writer );
		cvReleaseCapture( &capture );
		cvDestroyWindow( "Webcam" );		
		return( 0 );
}



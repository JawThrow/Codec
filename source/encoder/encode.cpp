#include "ICSP_Codec_Encoder.h"


extern char filename[256];

// argv: [0]:ICSPCodec.exe [1]sequence_fname [2]nframes [3]QPDC [4]QPAC [5]IntraPeroid [6]AVXFlag
int main(int argc, char *argv[])
{	
	
	char *imgfname = argv[1]; 
	int nframes = atoi(argv[2]);	
	int QPDC = atoi(argv[3]);
	int QPAC = atoi(argv[4]);
	int intraPeriod = atoi(argv[5]);
	int AVXFlag = atoi(argv[6]);
	#define SIMD AVXFlag;
	IcspCodec icspCodec;
	icspCodec.init(nframes, imgfname, 352, 288, QPDC, QPAC);
	icspCodec.encoding(intraPeriod);
	
	return 0;
}

#include <stddef.h>
#include <portaudio.h>

#define SAMPLE_RATE (48000)

void paCallBack(void *data) { /* ... */ }

void play_cry(char *crydat, size_t crylen)
{
	PaStream *stream;
	PaError PaErrCode;

	if(PaErrCode = Pa_Initialize(), PaErrCode)	goto error;
	if(PaErrCode = Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, SAMPLE_RATE, 256, paCallBack, &((struct { size_t sz; char *dt; }){ crylen, crydat })), PaErrCode)	goto error;
	if(PaErrCode = Pa_Terminate(), PaErrCode)	goto error;

	return;

error:
	printf("[PortAudio ERROR] %s\n", Pa_GetErrorText(PaErrCode));
	exit(PaErrCode);
}

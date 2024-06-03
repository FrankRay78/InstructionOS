
#define VIDEO_ADDRESS 0xb8000
#define WHITE_ON_BLUE  0x1f

int kernel_main()
{
	//Create a byte pointer to the start of video memory
    unsigned char* vidmem = (unsigned char*)VIDEO_ADDRESS;

    vidmem[0]='H';
    vidmem[1]=(char)WHITE_ON_BLUE;

	return 0;
}
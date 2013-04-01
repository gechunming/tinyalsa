#include <tinyalsa/asoundlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

struct pcm_config pcm_config_vx = {
    .channels = 2,
    .rate = 16000,
    .period_size = 160,
    .period_count = 2,
    .format = PCM_FORMAT_S16_LE,
};

struct pcm *pcm_modem_dl = NULL;	//down stream
struct pcm *pcm_modem_ul = NULL;	//up stream

#define CARD_DEFAULT	0
#define PORT_MODEM		1
#define PORT_BT			2

static int start_call()
{
	pcm_modem_dl = pcm_open(CARD_DEFAULT, PORT_MODEM, PCM_OUT, &pcm_config_vx);
	if (!pcm_is_ready(pcm_modem_dl)) {
		printf("cannot open PCM modem DL stream\n");
		return -1;
	}
	pcm_modem_ul = pcm_open(CARD_DEFAULT, PORT_MODEM, PCM_IN, &pcm_config_vx);
	if (!pcm_is_ready(pcm_modem_ul)) {
		printf("cannot open PCM modem UP stream\n");
		return -1;
	}
	pcm_start(pcm_modem_dl);
	pcm_start(pcm_modem_ul);
}

static int end_call()
{
	pcm_stop(pcm_modem_dl);
	pcm_stop(pcm_modem_ul);

	pcm_close(pcm_modem_dl);
	pcm_close(pcm_modem_ul);
}

int main(void)
{
	start_call();

	sleep(10);

	end_call();
}

/**
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "pico/stdlib.h"
#include "machine_i2s.c"

#define SCK 3
#define WS 4 // needs to be SCK +1
#define SD 29
#define BPS 32 // 24 is not valid in this implementation, but INMP441 outputs 24 bits samples
#define RATE 16000

int main() {
	stdio_init_all();
	machine_i2s_obj_t* i2s0 = machine_i2s_make_new(0, SCK, WS, SD, RX, BPS, STEREO, /*ringbuf_len*/SIZEOF_DMA_BUFFER_IN_BYTES, RATE);
	int32_t buffer[I2S_RX_FRAME_SIZE_IN_BYTES /4];
	while (true) {
		machine_i2s_stream_read(i2s0, (void*)&buffer[0], I2S_RX_FRAME_SIZE_IN_BYTES);
		printf("%.8x\n", buffer[0]); // right channel is empty, play using $ cat /dev/ttyACM0 | xxd -r -p | aplay -r16000 -c1 -fS32_BE
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//! \brief Structure for the TX Packet
typedef struct {
	uint8_t dstAddr[8];              //!<  Destination address
	uint32_t absTime;                //!< Absolute time to Tx packet (0 for immediate)
	//!< Layer will use last SeqNum used + 1

	uint8_t len;                     //!< Payload Length
	uint8_t payload[128];       //!< Payload
} EasyLink_TxPacket;

//! \brief Structure for the RX'ed Packet
typedef struct {
	uint8_t dstAddr[8];              //!< Dst Address of RX'ed packet
	int8_t rssi;                     //!< rssi of RX'ed packet
	uint32_t absTime;                //!< Absolute time to turn on Rx when passed
	//!< (0 for immediate), Or Absolute time that packet was Rx
	//!< when returned.

	uint32_t rxTimeout;              //!< Relative time in ticks from Rx start to Rx TimeOut
	//!< a value of 0 means no timeout
	uint8_t len;                     //!< length of RX'ed packet
	uint8_t payload[128]; //!< payload of RX'ed packet
} EasyLink_RxPacket;

struct Message_Packet_tx {
	uint32_t message_str[32];
	uint32_t message_num[32];
	float message_float[16];
	uint32_t message_float_conv[16];
};

struct Message_Packet_rx {
	char message_str[32];
	uint32_t message_num;
	float message_float;
	uint32_t message_float_conv;
};

struct RadioOperation {
	EasyLink_TxPacket easyLinkTxPacket;
	EasyLink_RxPacket easyLinkRxPacket;
};

struct RadioOperation currentRadioOperation;

size_t package_data(struct Message_Packet_tx sen) {

	currentRadioOperation.easyLinkTxPacket.payload[0] = (sen.message_str[0] & 0xFF000000) >> 24;
	currentRadioOperation.easyLinkTxPacket.payload[1] = (sen.message_str[0] & 0x00FF0000) >> 16;
	currentRadioOperation.easyLinkTxPacket.payload[2] = (sen.message_str[0] & 0xFF00) >> 8;
	currentRadioOperation.easyLinkTxPacket.payload[3] = (sen.message_str[0]) & 0xFF;

	currentRadioOperation.easyLinkTxPacket.payload[4] = (sen.message_str[1] & 0xFF000000) >> 24;
	currentRadioOperation.easyLinkTxPacket.payload[5] = (sen.message_str[1] & 0x00FF0000) >> 16;
	currentRadioOperation.easyLinkTxPacket.payload[6] = (sen.message_str[1] & 0xFF00) >> 8;
	currentRadioOperation.easyLinkTxPacket.payload[7] = (sen.message_str[1]) & 0xFF;

	currentRadioOperation.easyLinkTxPacket.payload[8] = (sen.message_str[2] & 0xFF000000) >> 24;
	currentRadioOperation.easyLinkTxPacket.payload[9] = (sen.message_str[2] & 0x00FF0000) >> 16;
	currentRadioOperation.easyLinkTxPacket.payload[10] = (sen.message_str[2] & 0xFF00) >> 8;
	currentRadioOperation.easyLinkTxPacket.payload[11] = (sen.message_str[2]) & 0xFF;

	currentRadioOperation.easyLinkTxPacket.payload[12] = (sen.message_num[0] & 0xFF000000) >> 24;
	currentRadioOperation.easyLinkTxPacket.payload[13] = (sen.message_num[0] & 0x00FF0000) >> 16;
	currentRadioOperation.easyLinkTxPacket.payload[14] = (sen.message_num[0] & 0xFF00) >> 8;
	currentRadioOperation.easyLinkTxPacket.payload[15] = (sen.message_num[0]) & 0xFF;

	currentRadioOperation.easyLinkTxPacket.payload[16] = (sen.message_float_conv[0] & 0xFF000000) >> 24;
	currentRadioOperation.easyLinkTxPacket.payload[17] = (sen.message_float_conv[0] & 0x00FF0000) >> 16;
	currentRadioOperation.easyLinkTxPacket.payload[18] = (sen.message_float_conv[0] & 0xFF00) >> 8;
	currentRadioOperation.easyLinkTxPacket.payload[19] = (sen.message_float_conv[0]) & 0xFF;

	currentRadioOperation.easyLinkTxPacket.len = sizeof(struct Message_Packet_tx);
	return 0;
}



size_t decode_data(struct Message_Packet_rx con) {

	con.message_str[0] = (currentRadioOperation.easyLinkRxPacket.payload[0]);
	con.message_str[1] = (currentRadioOperation.easyLinkRxPacket.payload[1]);
	con.message_str[2] = (currentRadioOperation.easyLinkRxPacket.payload[2]);
	con.message_str[3] = (currentRadioOperation.easyLinkRxPacket.payload[3]);
	con.message_str[4] = (currentRadioOperation.easyLinkRxPacket.payload[4]);
	con.message_str[5] = (currentRadioOperation.easyLinkRxPacket.payload[5]);
	con.message_str[6] = (currentRadioOperation.easyLinkRxPacket.payload[6]);
	con.message_str[7] = (currentRadioOperation.easyLinkRxPacket.payload[7]);
	con.message_str[8] = (currentRadioOperation.easyLinkRxPacket.payload[8]);
	con.message_str[9] = (currentRadioOperation.easyLinkRxPacket.payload[9]);
	con.message_str[10] = (currentRadioOperation.easyLinkRxPacket.payload[10]);
	con.message_str[11] = (currentRadioOperation.easyLinkRxPacket.payload[11]);

	con.message_num = (currentRadioOperation.easyLinkRxPacket.payload[12] << 24) | (currentRadioOperation.easyLinkRxPacket.payload[13] << 16) | (currentRadioOperation.easyLinkRxPacket.payload[14] << 8) | (currentRadioOperation.easyLinkRxPacket.payload[15]);

	con.message_float_conv = (currentRadioOperation.easyLinkRxPacket.payload[16] << 24) | (currentRadioOperation.easyLinkRxPacket.payload[17] << 16) | (currentRadioOperation.easyLinkRxPacket.payload[18] << 8) | (currentRadioOperation.easyLinkRxPacket.payload[19]);

	con.message_float = (float) con.message_float_conv / 1000000;

	printf("\n\nDecoded string: %s\n", con.message_str);
	printf("Decoded number: %x\n", con.message_num);
	printf("Decoded converted float: %d\n", con.message_float_conv);
	printf("Decoded float: %f\n", con.message_float);
	return 0;
}


int main() {

	struct Message_Packet_tx sensor;
	struct Message_Packet_rx concentrator;

	sensor.message_str[0] = 'hell';
	sensor.message_str[1] = 'o wo';
	sensor.message_str[2] = 'rld!';
	sensor.message_num[0] = 0xABCDEF1;
	sensor.message_float[0] = 1.234567;
	sensor.message_float_conv[0] = sensor.message_float[0] * 1000000;

	package_data(sensor);

	printf("Size of payload is %d\n", currentRadioOperation.easyLinkTxPacket.len);

	printf("Payload string: \n");
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[0]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[1]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[2]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[3]);
	printf("\n");

	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[4]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[5]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[6]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[7]);
	printf("\n");

	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[8]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[9]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[10]);
	printf("%c", currentRadioOperation.easyLinkTxPacket.payload[11]);
	printf("\n");

	printf("Payload num: \n");
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[12]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[13]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[14]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[15]);
	printf("\n");

	printf("Payload float: \n");
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[16]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[17]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[18]);
	printf("%x", currentRadioOperation.easyLinkTxPacket.payload[19]);


	currentRadioOperation.easyLinkRxPacket.payload[0] = currentRadioOperation.easyLinkTxPacket.payload[0];
	currentRadioOperation.easyLinkRxPacket.payload[1] = currentRadioOperation.easyLinkTxPacket.payload[1];
	currentRadioOperation.easyLinkRxPacket.payload[2] = currentRadioOperation.easyLinkTxPacket.payload[2];
	currentRadioOperation.easyLinkRxPacket.payload[3] = currentRadioOperation.easyLinkTxPacket.payload[3];

	currentRadioOperation.easyLinkRxPacket.payload[4] = currentRadioOperation.easyLinkTxPacket.payload[4];
	currentRadioOperation.easyLinkRxPacket.payload[5] = currentRadioOperation.easyLinkTxPacket.payload[5];
	currentRadioOperation.easyLinkRxPacket.payload[6] = currentRadioOperation.easyLinkTxPacket.payload[6];
	currentRadioOperation.easyLinkRxPacket.payload[7] = currentRadioOperation.easyLinkTxPacket.payload[7];

	currentRadioOperation.easyLinkRxPacket.payload[8] = currentRadioOperation.easyLinkTxPacket.payload[8];
	currentRadioOperation.easyLinkRxPacket.payload[9] = currentRadioOperation.easyLinkTxPacket.payload[9];
	currentRadioOperation.easyLinkRxPacket.payload[10] = currentRadioOperation.easyLinkTxPacket.payload[10];
	currentRadioOperation.easyLinkRxPacket.payload[11] = currentRadioOperation.easyLinkTxPacket.payload[11];

	currentRadioOperation.easyLinkRxPacket.payload[12] = currentRadioOperation.easyLinkTxPacket.payload[12];
	currentRadioOperation.easyLinkRxPacket.payload[13] = currentRadioOperation.easyLinkTxPacket.payload[13];
	currentRadioOperation.easyLinkRxPacket.payload[14] = currentRadioOperation.easyLinkTxPacket.payload[14];
	currentRadioOperation.easyLinkRxPacket.payload[15] = currentRadioOperation.easyLinkTxPacket.payload[15];

	currentRadioOperation.easyLinkRxPacket.payload[16] = currentRadioOperation.easyLinkTxPacket.payload[16];
	currentRadioOperation.easyLinkRxPacket.payload[17] = currentRadioOperation.easyLinkTxPacket.payload[17];
	currentRadioOperation.easyLinkRxPacket.payload[18] = currentRadioOperation.easyLinkTxPacket.payload[18];
	currentRadioOperation.easyLinkRxPacket.payload[19] = currentRadioOperation.easyLinkTxPacket.payload[19];

	decode_data(concentrator);

	return 0;
}

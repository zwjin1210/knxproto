#include "connres.h"
#include "header.h"

#include <string.h>

// Connection Response:
//   Octet 0:     Channel
//   Octet 1:     Status
//   Octet 2-9:   Host info
//   Octet 10-13: Connection response info

// Connection Response Information
//   Octet 0: Structure length
//   Octet 1-3: Unknown

bool knxnetip_append_connection_response(msgbuilder* mb,
                                         const knxnetip_connection_response* res) {
	const uint8_t data[2] = {res->channel, res->status};

	return
		knxnetip_append_header(mb, KNXNETIP_CONNECTION_RESPONSE, 14) &&
		msgbuilder_append(mb, data, 2) &&
		knxnetip_append_host_info(mb, &res->host) &&
		msgbuilder_append_single(mb, 4) &&
		msgbuilder_append(mb, res->extended, 3);
}

bool knxnetip_parse_connection_response(const uint8_t* message, size_t length,
                                        knxnetip_connection_response* res) {
	if (length < 14 || message[10] != 4)
		return false;

	res->channel = message[0];
	res->status = message[1];

	// TODO: Figure out what the last 4 octets do.
	memcpy(res->extended, message + 11, 3);

	return knxnetip_parse_host_info(message + 2, &res->host);
}
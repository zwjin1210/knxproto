/* KNX Client Library
 * A library which provides the means to communicate with several
 * KNX-related devices or services.
 *
 * Copyright (C) 2014, Ole Krüger <ole@vprsm.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef KNXCLIENT_KNX_TUNNELREQ_H
#define KNXCLIENT_KNX_TUNNELREQ_H

#include "msgbuilder.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Tunnel Request
 */
typedef struct {
	uint8_t channel;
	uint8_t seq_number;
	uint16_t size;
	const void* data;
} knx_tunnel_request;

/**
 * Generate the message for a tunnel request.
 */
bool knx_append_tunnel_request(msgbuilder* mb,
                               const knx_tunnel_request* req);

/**
 * Parse a message (excluding header) which contains a tunnel request.
 */
bool knx_parse_tunnel_request(const uint8_t* message, size_t length,
                              knx_tunnel_request* req);

#endif
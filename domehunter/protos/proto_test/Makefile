#
# Copyright 2015 gRPC authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11
ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif
PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`
PROTO_PATH1 = /usr/local/include/google/protobuf/
PROTO_PATH2 = /home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/proto_test/hx2dome.proto

# PROTOS_PATH = ../../protos
PROTOS_PATH = /home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/proto_test/

vpath %.proto $(PROTOS_PATH)

# all: hx2dome.proto_client hx2dome.proto_server
all: hx2dome.proto_client

hx2dome.proto_client: hx2dome.pb.o hx2dome.grpc.pb.o hx2dome.proto_client.o
	$(CXX) $^ $(LDFLAGS) -o $@

hx2dome.grpc.pb.o: hx2dome.grpc.pb.cc
	$(CXX) $^ $(LDFLAGS) -c

hx2dome.pb.o: hx2dome.pb.cc
	$(CXX) $^ $(LDFLAGS) -c

hx2dome.proto_client.o: hx2dome.proto_client.cc
	$(CXX) $^ $(LDFLAGS) -c

# hx2dome.proto_server: hx2dome.proto.pb.o hx2dome.proto.grpc.pb.o hx2dome.proto_server.o helper.o
#	 $(CXX) $^ $(LDFLAGS) -o $@

.PRECIOUS: %.grpc.pb.cc
hx2dome.grpc.pb.cc: hx2dome.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --proto_path=$(PROTO_PATH1) $(PROTO_PATH2) --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH)

.PRECIOUS: %.pb.cc
hx2dome.pb.cc: hx2dome.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

clean:
	rm -f *.o *.pb.cc *.pb.h #hx2dome.proto_client hx2dome.proto_server

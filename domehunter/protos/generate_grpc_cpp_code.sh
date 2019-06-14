#!/bin/bash

if [ "$1" == "clean" ]; then
	rm libhuntsmandome*
	rm src/*.grpc.pb.* 
	rm src/*.pb.* 
	rm *.o
	rm .qmake.stash
else
	PROTOS_PATH="/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/src/"
	PROTO_PATH1="/usr/local/include/google/protobuf/"
	PROTO_PATH2="/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/src/x2dome.proto"
	GRPC_CPP_PLUGIN_PATH="$(which grpc_cpp_plugin)"

	echo -e "Generating GRPC C++ code\n"

	echo -e "protoc -I $PROTOS_PATH --cpp_out=. src/x2dome.proto\n"
	protoc -I "$PROTOS_PATH" --cpp_out=. src/hx2dome.proto

	echo -e "protoc -I $PROTOS_PATH --grpc_out=. --proto_path=$PROTO_PATH1 $PROTO_PATH2 --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH\n"
	protoc -I "$PROTOS_PATH" --grpc_out=. --proto_path="$PROTO_PATH1" "$PROTO_PATH2" --plugin=protoc-gen-grpc="$GRPC_CPP_PLUGIN_PATH"

	echo -e "Moving generated GRPC C++ code to src/\n"
	mv *pb* src/

	echo -e "Generating Makefile from project file.\n"
	qmake

	echo -e "Running Generated Makefile.\n"
	make

	echo -e "Cleaning out object files.\n"
	rm *.o

	echo -e "Done.\n"
fi

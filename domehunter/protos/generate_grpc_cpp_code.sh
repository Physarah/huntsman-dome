#!/bin/bash

if [ "$1" == "clean" ]; then
	rm libx2dome*
	rm *.grpc.pb.* 
	rm *.pb.* 
	rm *.o
	rm .qmake.stash
else
	PROTOS_PATH="/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/"
	PROTO_PATH1="/usr/local/include/google/protobuf/"
	PROTO_PATH2="/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/x2dome.proto"
	GRPC_CPP_PLUGIN_PATH="$(which grpc_cpp_plugin)"

	echo "Generating GRPC C++ code"

	echo "protoc -I $PROTOS_PATH --cpp_out=. x2dome.proto"
	protoc -I "$PROTOS_PATH" --cpp_out=. x2dome.proto
	echo ""

	echo "protoc -I $PROTOS_PATH --grpc_out=. --proto_path=$PROTO_PATH1 $PROTO_PATH2 --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH"
	protoc -I "$PROTOS_PATH" --grpc_out=. --proto_path="$PROTO_PATH1" "$PROTO_PATH2" --plugin=protoc-gen-grpc="$GRPC_CPP_PLUGIN_PATH"
	echo ""

	echo "Generating Makefile from project file."
	qmake
	echo ""

	echo "Running Generated Makefile."
	make
	echo ""

	echo "Done."
fi

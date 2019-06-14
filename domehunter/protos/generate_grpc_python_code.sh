#!/bin/bash

if [ "$1" == "clean" ]; then
	rm src/*pb2_grpc.py 
	rm src/*pb2.py
else
	PROTOS_PATH="$HOME/Documents/REPOS/huntsman-dome/domehunter/protos/src/"
	PROTO_PATH1="/usr/local/include/google/protobuf/"
	PROTO_PATH2="/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/src/hx2dome.proto"

	echo -e "\nGenerating GRPC Python code\n"

	echo -e "python -m grpc_tools.protoc -I=$PROTOS_PATH --python_out=. --grpc_python_out=. --proto_path=$PROTO_PATH1 $PROTO_PATH2\n"

	python -m grpc_tools.protoc -I=$PROTOS_PATH --python_out=. --grpc_python_out=. --proto_path=$PROTO_PATH1 $PROTO_PATH2

	echo -e "Moving generated GRPC Python code to src/\n"
	mv *pb* src/

	echo -e "Done.\n"
fi

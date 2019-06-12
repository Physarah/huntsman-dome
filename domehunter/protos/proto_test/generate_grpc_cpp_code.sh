PROTOS_PATH='/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/proto_test/'
PROTO_PATH1='/usr/local/include/google/protobuf/'
PROTO_PATH2='/home/fergus/Documents/REPOS/huntsman-dome/domehunter/protos/proto_test/x2dome.proto'
GRPC_CPP_PLUGIN_PATH=`which grpc_cpp_plugin`


protoc -I $(PROTOS_PATH) --cpp_out=. x2dome.proto

protoc -I $(PROTOS_PATH) --grpc_out=. --proto_path=$(PROTO_PATH1) $(PROTO_PATH2) --plugin=protoc-gen-grpc=(GRPC_CPP_PLUGIN_PATH)

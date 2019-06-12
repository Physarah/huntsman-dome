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
"""The Python implementation of the GRPC helloworld.Greeter server."""

from concurrent import futures
import time
import logging

import grpc

import x2dome_pb2
import x2dome_pb2_grpc

_ONE_DAY_IN_SECONDS = 60 * 60 * 24


class X2DomeServer(x2dome_pb2_grpc.X2DomeServicer):

    def dapiGotoAzEl(self, request, context):
        # print something for debugging, so I know python server is actually getting a request from client
        print('something')
        # increment the return code by 1 so I can see the client/server communication is working
        return x2dome_pb2.ReturnCode(return_code=request.return_code+1)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    x2dome_pb2_grpc.add_X2DomeServicer_to_server(X2DomeServer(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    try:
        while True:
            time.sleep(_ONE_DAY_IN_SECONDS)
    except KeyboardInterrupt:
        server.stop(0)


if __name__ == '__main__':
    logging.basicConfig()
    serve()

# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

from google.protobuf import empty_pb2 as google_dot_protobuf_dot_empty__pb2
import x2dome_pb2 as x2dome__pb2


class X2DomeStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.dapiGetAzEl = channel.unary_unary(
        '/x2dome.X2Dome/dapiGetAzEl',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.AzEl.FromString,
        )
    self.dapiGotoAzEl = channel.unary_unary(
        '/x2dome.X2Dome/dapiGotoAzEl',
        request_serializer=x2dome__pb2.AzEl.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiAbort = channel.unary_unary(
        '/x2dome.X2Dome/dapiAbort',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiOpen = channel.unary_unary(
        '/x2dome.X2Dome/dapiOpen',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiClose = channel.unary_unary(
        '/x2dome.X2Dome/dapiClose',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiPark = channel.unary_unary(
        '/x2dome.X2Dome/dapiPark',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiUnpark = channel.unary_unary(
        '/x2dome.X2Dome/dapiUnpark',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiFindHome = channel.unary_unary(
        '/x2dome.X2Dome/dapiFindHome',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.dapiGotoComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiGotoComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiOpenComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiOpenComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiCloseComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiCloseComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiParkComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiParkComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiUnparkComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiUnparkComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiFindHomeComplete = channel.unary_unary(
        '/x2dome.X2Dome/dapiFindHomeComplete',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.IsComplete.FromString,
        )
    self.dapiSync = channel.unary_unary(
        '/x2dome.X2Dome/dapiSync',
        request_serializer=x2dome__pb2.AzEl.SerializeToString,
        response_deserializer=x2dome__pb2.ReturnCode.FromString,
        )
    self.deviceInfoNameShort = channel.unary_unary(
        '/x2dome.X2Dome/deviceInfoNameShort',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.BasicString.FromString,
        )
    self.deviceInfoNameLong = channel.unary_unary(
        '/x2dome.X2Dome/deviceInfoNameLong',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.BasicString.FromString,
        )
    self.deviceInfoDetailedDescription = channel.unary_unary(
        '/x2dome.X2Dome/deviceInfoDetailedDescription',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.BasicString.FromString,
        )
    self.deviceInfoFirmwareVersion = channel.unary_unary(
        '/x2dome.X2Dome/deviceInfoFirmwareVersion',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.BasicString.FromString,
        )
    self.deviceInfoModel = channel.unary_unary(
        '/x2dome.X2Dome/deviceInfoModel',
        request_serializer=google_dot_protobuf_dot_empty__pb2.Empty.SerializeToString,
        response_deserializer=x2dome__pb2.BasicString.FromString,
        )


class X2DomeServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def dapiGetAzEl(self, request, context):
    """Dome API
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiGotoAzEl(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiAbort(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiOpen(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiClose(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiPark(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiUnpark(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiFindHome(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiGotoComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiOpenComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiCloseComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiParkComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiUnparkComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiFindHomeComplete(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def dapiSync(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def deviceInfoNameShort(self, request, context):
    """Hardware Info Interface
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def deviceInfoNameLong(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def deviceInfoDetailedDescription(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def deviceInfoFirmwareVersion(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def deviceInfoModel(self, request, context):
    # missing associated documentation comment in .proto file
    pass
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_X2DomeServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'dapiGetAzEl': grpc.unary_unary_rpc_method_handler(
          servicer.dapiGetAzEl,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.AzEl.SerializeToString,
      ),
      'dapiGotoAzEl': grpc.unary_unary_rpc_method_handler(
          servicer.dapiGotoAzEl,
          request_deserializer=x2dome__pb2.AzEl.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiAbort': grpc.unary_unary_rpc_method_handler(
          servicer.dapiAbort,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiOpen': grpc.unary_unary_rpc_method_handler(
          servicer.dapiOpen,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiClose': grpc.unary_unary_rpc_method_handler(
          servicer.dapiClose,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiPark': grpc.unary_unary_rpc_method_handler(
          servicer.dapiPark,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiUnpark': grpc.unary_unary_rpc_method_handler(
          servicer.dapiUnpark,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiFindHome': grpc.unary_unary_rpc_method_handler(
          servicer.dapiFindHome,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'dapiGotoComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiGotoComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiOpenComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiOpenComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiCloseComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiCloseComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiParkComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiParkComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiUnparkComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiUnparkComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiFindHomeComplete': grpc.unary_unary_rpc_method_handler(
          servicer.dapiFindHomeComplete,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.IsComplete.SerializeToString,
      ),
      'dapiSync': grpc.unary_unary_rpc_method_handler(
          servicer.dapiSync,
          request_deserializer=x2dome__pb2.AzEl.FromString,
          response_serializer=x2dome__pb2.ReturnCode.SerializeToString,
      ),
      'deviceInfoNameShort': grpc.unary_unary_rpc_method_handler(
          servicer.deviceInfoNameShort,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.BasicString.SerializeToString,
      ),
      'deviceInfoNameLong': grpc.unary_unary_rpc_method_handler(
          servicer.deviceInfoNameLong,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.BasicString.SerializeToString,
      ),
      'deviceInfoDetailedDescription': grpc.unary_unary_rpc_method_handler(
          servicer.deviceInfoDetailedDescription,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.BasicString.SerializeToString,
      ),
      'deviceInfoFirmwareVersion': grpc.unary_unary_rpc_method_handler(
          servicer.deviceInfoFirmwareVersion,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.BasicString.SerializeToString,
      ),
      'deviceInfoModel': grpc.unary_unary_rpc_method_handler(
          servicer.deviceInfoModel,
          request_deserializer=google_dot_protobuf_dot_empty__pb2.Empty.FromString,
          response_serializer=x2dome__pb2.BasicString.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'x2dome.X2Dome', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))

const addon = require('../build/Release/napi-native');

module.exports = {
  allocateBuffer: addon.NapiModule,
  freeBuffer: addon.FreeBuff
}


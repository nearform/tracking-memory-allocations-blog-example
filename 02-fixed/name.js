'use strict'

const namesGenerator = require('docker-namesgenerator')
const names = {}

function name () {
  let result = namesGenerator()

  names[result] = names[result] ? 
    names[result] + 1 :
    1

  return result + names[result]
}

module.exports = name

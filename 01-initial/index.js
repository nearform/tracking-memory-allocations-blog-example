'use strict'

const path = require('path')
const fs = require('fs')
const Fastify = require('fastify')

const Handlebars = require('handlebars')
Handlebars.registerHelper('name', require('./name'))

const template = Handlebars.compile(fs.readFileSync(path.join(__dirname, 'template')).toString())

const server = Fastify()

server.get('/', serve)

function serve (req, res) {
  res.send(template({}))
}

server.listen(3000)

#!/usr/bin/env ruby

require "numo/narray"
require "fromfile"

a = Numo::DFloat[1..64].reshape(8, 8)
a.tofile("data.bin")
a = Numo::DFloat.fromfile("data.bin").reshape(8, 8)
p a

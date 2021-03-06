# frozen_string_literal: true

require_relative "lib/narray/fromfile/version"

Gem::Specification.new do |spec|
  spec.name          = "narray-fromfile"
  spec.version       = Narray::Fromfile::VERSION
  spec.authors       = ["Murata Mitsuharu"]
  spec.email         = ["hikari.photon+mygit@gmail.com"]

  spec.summary       = "Extracts data from a double precision floating point binary file."
  spec.description   = "Extracts data from a double precision floating point binary file. 倍精度浮動小数点バイナリファイルからデータを抽出するよ。"
  spec.homepage      = "https://github.com/himeyama/narray-fromfile"
  spec.required_ruby_version = ">= 2.4.0"

  spec.license       = "MIT"

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files = Dir.chdir(File.expand_path(__dir__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{\A(?:test|spec|features)/}) }
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{\Aexe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib", "ext"]

  spec.add_dependency "numo-narray"
  spec.extensions = %w[ext/fromfile/extconf.rb]
end

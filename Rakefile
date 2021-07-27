# frozen_string_literal: true

require "bundler/gem_tasks"
task default: %i[]

require "rake/extensiontask"
Rake::ExtensionTask.new "fromfile" do |ext|
    ext.lib_dir = "ext"
end


require 'rake/testtask'
Rake::TestTask.new(:test) do |t|
    t.libs << "ext"
    t.test_files = FileList["test.rb"]
    t.verbose = true
end
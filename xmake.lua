-- add release and debug modes
add_rules("mode.release", "mode.debug")

-- add deps
add_requires("fmt 9.X") -- required because lib provides a {fmt} parser
add_requires("gtest 1.12.1", {optional = true}) -- required only for size-tests

target("size")
  set_kind("headeronly")
  set_languages("cxx20")
  set_default(true)
  add_packages("fmt")
  add_headerfiles("include/**.hpp")
  add_includedirs("include", {public = true})
  --  OS specific flags
  if is_plat("linux") or is_plat("macosx") then
    add_cxxflags("-Wall -Wextra -pedantic")
  end
target_end()

target("size-example")
  set_kind("binary")
  set_languages("cxx20")
  set_default(false)
  add_packages("fmt")
  add_deps("size")
  add_files("example/example.cpp")
target_end()

target("size-tests")
  set_kind("binary")
  set_languages("cxx20")
  set_default(false)
  add_deps("size")
  add_packages("fmt")
  add_packages("gtest")
  add_files("tests/*.cpp")
  if (is_plat("windows")) then
    add_ldflags("/SUBSYSTEM:CONSOLE")
  end
target_end()

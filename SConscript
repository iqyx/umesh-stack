Import("env")

objs = env.Object(source = [
	File(Glob("src/*.c"))
])
env.Append(CPPPATH = [
	Dir("include"),
	Dir("../nanopb/")
])


Return("objs")
